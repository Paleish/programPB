# coding=utf-8
import os
import platform

ReceiveProto = """const proto = require('../pb/srvRes_pb');

class ReceiveProto {
    receive(buffer) {
        let res = proto.SrvRes.deserializeBinary(buffer);
        switch (res.getMethodid()) {%s
            default:
                console.log(`proto error no ${res.getMethodid()}`);
                break;
        }
    };
%s
}

module.exports = ReceiveProto;
"""

switchServer = """
            case proto.SrvMsgType.%s:
                this._%s(res.get%s(), res.getResult(), res.getErrstr());
                break;"""

funcServer = """
    _%s(msg, result, errStr) {
        console.log('-----------------------no implements %s-----------------------');
    };
"""

SendProto = """const ModuleId = require('../pb/lsEnum_pb').ModuleId;
const UdpSocket = require('../../UdpSocket');
const proto = require('../pb/cliReq_pb');

class SendProto {
    static createCliReq(methodId, userId = 1, moduleId = ModuleId.GAME) {
        let req = new proto.CliReq();
        req.setMethodid(methodId);
        req.setUserid(userId);
        req.setModuleid(moduleId);
        return req;
    };
%s
}

module.exports = SendProto;
"""

funcClient = """
    static %s(%s) {
        let %s = new proto.%s();
%s
        let req = this.createCliReq(proto.ClientMsgType.%s, userId, moduleId);
        req.set%s(%s);

        let buffer = req.serializeBinary();
        UdpSocket.send(buffer);
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
        if "Cli" in funcName:
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
                _para = _valuename[0].upper() + _valuename[1:].lower()
                if "List" in _deftype:
                    funcpara += listPara % (_funcName, _para, valuename[i])
                else:
                    funcpara += funcPara % (_funcName, _para, valuename[i])
                if i < len(deftype) - 1:
                    para += ", "
            funcstr += funcClient % (objname, para == "" and "userId = 1, moduleId = ModuleId.GAME" or ("%s, userId = 1, moduleId = ModuleId.GAME" % para), _funcName, funcName, funcpara, funcName.upper(), _funcName[0].upper()+_funcName[1:], _funcName)
    deleteFile("Client_JS/cmd/SendProto.js")
    writeFileContent("Client_JS/cmd/SendProto.js", SendProto % (funcstr))

def make_receive_proto():
    (packagename, structList) = parse_proto("./LockstepSrvPB/srvRes.proto")
    switchstr = ""
    funcstr = ""
    for funcName in structList:
        deftype = []
        value = structList[funcName]

        for i in range(len(value)):
            item = value[i]
            if item[0] != "SrvMsgType" and  item[0] != "Result" and  item[0] != "string":
                deftype.append(item[0])

        for i in range(len(deftype)):
            _deftype = deftype[i][0].lower()+deftype[i][1:]
            switchstr += switchServer % (deftype[i].upper(), _deftype, deftype[i][0].upper() + deftype[i][1:].lower())
            funcstr += funcServer % (_deftype, _deftype)

    deleteFile("Client_JS/cmd/ReceiveProto.js")
    writeFileContent("Client_JS/cmd/ReceiveProto.js", ReceiveProto % (switchstr, funcstr))

def make_proto():
    for root, dirs, files in os.walk("./LockstepSrvPB"):
        for i in range(len(files)):
            (filepath, tempfilename) = os.path.split(files[i]);
            (shotname, extension) = os.path.splitext(tempfilename);
            if extension == '.proto':
                if (platform.system() == 'Windows'):
                    os.system("./LockstepSrvPB/protoc.exe %s --js_out=import_style=commonjs,binary:./Client_JS/pb -I ./LockstepSrvPB" % (root + "/" + files[i]))
                else:
                    os.system("protoc %s --js_out=import_style=commonjs,binary:./Client_JS/pb -I ./LockstepSrvPB" % (root + "/" + files[i]))

if __name__ == "__main__":
    make_proto()
    make_send_proto()
    make_receive_proto()