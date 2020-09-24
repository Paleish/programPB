# coding=utf-8
import os
import platform

ReceiveProto = """const proto = require('../pb/cliReq_pb');

class ReceiveProto {
    kcpobj;

    receive(buffer, kcpobj) {
        this.kcpobj = kcpobj;
        let req = proto.CliReq.deserializeBinary(buffer);
        switch (req.getMethodid()) {%s
            default:
                console.log(`proto error no ${req.getMethodid()}`);
                break;
        }
    };
%s
}

module.exports = ReceiveProto;
"""

switchServer = """
            case proto.ClientMsgType.%s:
                this._%s(req.get%s());
                break;"""

funcServer = """
    _%s(msg) {
        console.log('-----------------------no implements %s-----------------------');
    };
"""

SendProto = """const Result = require('../pb/lsEnum_pb').Result;
const proto = require('../pb/srvRes_pb');

class SendProto {
    static createSrvRes(methodId, result = Result.SUCCESS, errStr = "") {
        let res = new proto.SrvRes();
        res.setMethodid(methodId);
        res.setResult(result);
        res.setErrstr(errStr);
        return res;
    };
%s
}

module.exports = SendProto;
"""

funcClient = """
    static %s(kcpobj, %s) {
        let %s = new proto.%s();
%s
        let res = this.createSrvRes(proto.SrvMsgType.%s, result, errStr);
        res.set%s(%s);

        let buffer = res.serializeBinary();
        let UdpSocket = require('../../UdpSocket');
        UdpSocket.send(kcpobj, buffer);
    }
"""

funcPara = """        %s.set%s(%s);
"""
listPara = """        %s.set%s(%s);
"""
def getFileContent(fileName):
    all_the_text = ""
    try:
        file_object = open(fileName, "r")
        all_the_text = file_object.read()
        file_object.close()
    except:
        pass
    return all_the_text

def writeFileContent(fileName, strContent, strEncoding="utf-8"):
    try:
        bycontent = strContent.encode("utf-8")
        output = open(fileName, "wb")
        output.write(bycontent)
        output.close()
    except:
        pass
    return


def deleteFile(fileName):
    if os.path.exists(fileName):
        os.remove(fileName)
    return

def parse_proto(file):
    structList = {}
    content = getFileContent(file)
    message = False

    # parse message name
    lines = content.splitlines()
    for line in lines:
        line = line.strip()
        line.replace("\t", " ")
        if "message " in line:
            _,_,one=line.partition("message ")
            one,_,_ = one.partition("{")
            message = one.strip()
            structList[message] = []
        if message != False and ("=" in line):
            defType, _, valueName = line.partition(" ")
            valueName, _, temp= valueName.partition(" ")
            if defType == "repeated":
                defType = "List<%s>" % (valueName)
                valueName, _, _= temp.partition(" ")
            structList[message].append([defType.strip(), valueName])
        if "}" in line:
            message = False;

    # parse package name
    packagename = ""
    lines = content.splitlines()
    for line in lines:
        line, _, _ = line.partition("//")
        line = line.strip()
        if "package" in line:
            words = line.split("package")
            if len(words) == 2:
                packagename = words[1].strip(" \t;")
                break
            for word in words:
                print("word:" + word)

    return (packagename,structList)

def make_send_proto():
    (packagename, structList) = parse_proto("./LockstepSrvPB/gameProto.proto")
    funcstr = ""
    for funcName in structList:
        if "Srv" in funcName or "BGame" in funcName:
            objname = funcName[0].lower() + funcName[1:]
            _funcName = funcName.lower()
            deftype = []
            valuename = []
            value = structList[funcName]

            for i in range(len(value)):
                item = value[i]
                deftype.append(item[0])
                valuename.append(item[1])

            para = ""
            funcpara = ""
            default_value = ""
            for i in range(len(deftype)):
                if deftype[i] == "int32":
                    _deftype = "int"
                elif deftype[i] == "int64":
                    _deftype = "long"
                elif deftype[i] == "List<int32>":
                    _deftype = "List<int>"
                elif deftype[i] == "List<int64>":
                    _deftype = "List<long>"
                else:
                    _deftype = deftype[i]

                if _deftype == "int" or _deftype == "long":
                    default_value = "0"
                elif _deftype == "float":
                    default_value = "0.0f"
                elif _deftype == "double":
                    default_value = "0.0d"
                elif _deftype == "bool":
                    default_value = "false"
                elif _deftype == "string":
                    default_value = "\"\""
                else:
                    default_value = "null"
                para += (valuename[i] + " = " + default_value)
                _valuename = valuename[i].lower()
                _para = valuename[i][0].upper() + valuename[i][1:].lower()
                if "List" in _deftype:
                    funcpara += listPara % (_funcName, _para, valuename[i])
                else:
                    funcpara += funcPara % (_funcName, _para, valuename[i])
                if i < len(deftype) - 1:
                    para += ", "
            funcstr += funcClient % (objname, para == "" and "result = Result.SUCCESS, errStr = \"\"" or ("%s, result = Result.SUCCESS, errStr = \"\"" % para), _funcName, funcName, funcpara, funcName.upper(), _funcName[0].upper()+_funcName[1:], _funcName)
    deleteFile("Server_JS/cmd/SendProto.js")
    writeFileContent("Server_JS/cmd/SendProto.js", SendProto % (funcstr))

def make_receive_proto():
    (packagename, structList) = parse_proto("./LockstepSrvPB/cliReq.proto")
    switchstr = ""
    funcstr = ""
    for funcName in structList:
        deftype = []
        value = structList[funcName]

        for i in range(len(value)):
            item = value[i]
            if item[0] != "ClientMsgType" and  item[0] != "int32" and  item[0] != "ModuleId":
                deftype.append(item[0])

        for i in range(len(deftype)):
            _deftype = deftype[i][0].lower() + deftype[i][1:]
            switchstr += switchServer % (deftype[i].upper(), _deftype, deftype[i][0].upper() + deftype[i][1:].lower())
            funcstr += funcServer % (_deftype, _deftype)

    deleteFile("Server_JS/cmd/ReceiveProto.js")
    writeFileContent("Server_JS/cmd/ReceiveProto.js", ReceiveProto % (switchstr, funcstr))

def make_proto():
    for root, dirs, files in os.walk("./LockstepSrvPB"):
        for i in range(len(files)):
            (filepath, tempfilename) = os.path.split(files[i]);
            (shotname, extension) = os.path.splitext(tempfilename);
            if extension == '.proto':
                if (platform.system() == 'Windows'):
                    os.system("./LockstepSrvPB/protoc.exe %s --js_out=import_style=commonjs,binary:./Server_JS/pb -I ./LockstepSrvPB" % (root + "/" + files[i]))
                else:
                    os.system("protoc %s --js_out=import_style=commonjs,binary:./Server_JS/pb -I ./LockstepSrvPB" % (root + "/" + files[i]))

if __name__ == "__main__":
    make_proto()
    make_send_proto()
    make_receive_proto()