# coding=utf-8
import os
import platform

ReceiveProto_h = """#pragma once
#ifndef _RECEIVEPROTO_H
#define _RECEIVEPROTO_H

#include "../pb/srvRes.pb.h"

using namespace std;

namespace CPPClient
{
    namespace Net
    {
        namespace Cmd
        {
            class ReceiveProto
            {
            public:
                void Receive(const char *buffer);

            protected:%s
            };
        } // namespace Cmd
    }     // namespace Net
} // namespace CPPClient

#endif
"""

ReceiveProto_h_func = """
                virtual void %s(lspb::%s msg, lspb::Result result, string errStr);"""

ReceiveProto_cpp = """#include "ReceiveProto.h"

using namespace CPPClient::Net::Cmd;

void ReceiveProto::Receive(const char *buffer)
{
    lspb::SrvRes res;
    res.ParseFromString(buffer);
    switch (res.methodid())
    {%s
    default:
        printf("proto error no %%d\\n", res.methodid());
        break;
    }
}
%s
"""

switchServer = """
    case lspb::SrvMsgType::%s:
        %s(res.%s(), res.result(), res.errstr());
        break;"""

funcServer = """
void ReceiveProto::%s(lspb::%s msg, lspb::Result result, string errStr)
{
    printf("-----------------------no implements %s-----------------------\\n");
}
"""

SendProto_h = """#pragma once
#ifndef _SENDPROTO_H
#define _SENDPROTO_H

#include "../pb/cliReq.pb.h"
#include "Net/UdpSocket.h"

using namespace std;

namespace CPPClient
{
    namespace Net
    {
        namespace Cmd
        {
            class SendProto
            {
            private:
                static lspb::CliReq *CreateCliReq(lspb::ClientMsgType methodId, int userId = 1, lspb::ModuleId moduleId = lspb::ModuleId::Game);

            public:%s
            };
        } // namespace Cmd
    }     // namespace Net
} // namespace CPPClient

#endif
"""

SendProto_h_func = """
                static void %s(%s);"""

SendProto_cpp = """#include "SendProto.h"

using namespace CPPClient::Net::Cmd;

lspb::CliReq *SendProto::CreateCliReq(lspb::ClientMsgType methodId, int userId, lspb::ModuleId moduleId)
{
    lspb::CliReq *req = new lspb::CliReq;
    req->set_methodid(methodId);
    req->set_userid(userId);
    req->set_moduleid(moduleId);
    return req;
}
%s
"""

funcClient = """
void SendProto::%s(%s)
{
    lspb::%s *%s = new lspb::%s;
%s
    string *output = new string;

    lspb::CliReq *req = CreateCliReq(lspb::ClientMsgType::%s, userId, moduleId);
    req->set_allocated_%s(%s);
    req->SerializeToString(output);

    int err = UdpSocket::send(output->c_str(), 8);
    if (err < 0)
    {
        printf("client send error %%d\\n", err);
    }
    else
    {
        delete req;
        req = nullptr;
        delete output;
        output = nullptr;
    }
}
"""

funcPara = """    %s->set_%s(%s);
"""
listPara = """    for (auto i = %s.begin(); i < %s.end(); i++)
    {
        auto *data = %s->add_%s();
        data->CopyFrom(*i);
    }
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
                defType = "vector<lspb::%s>" % (valueName)
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
    funcstr_cpp = ""
    funcstr_h = ""
    for funcName in structList:
        if "Cli" in funcName:
            objname = funcName[0].lower() + funcName[1:]
            deftype = []
            valuename = []
            value = structList[funcName]

            for i in range(len(value)):
                item = value[i]
                deftype.append(item[0])
                valuename.append(item[1])

            para_h = ""
            default_value = ""

            para_cpp = ""
            funcpara = ""
            for i in range(len(deftype)):
                if deftype[i] == "int32":
                    _deftype = "int"
                elif deftype[i] == "int64":
                    _deftype = "long"
                elif deftype[i] == "vector<lspb::int32>":
                    _deftype = "vector<int>"
                elif deftype[i] == "vector<lspb::int64>":
                    _deftype = "vector<long>"
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

                _para = valuename[i].lower()

                if "vector" in _deftype:
                    para_h += "const %s &%s = %s()" % (_deftype, valuename[i], _deftype)
                    para_cpp += "const %s &%s" % (_deftype, valuename[i])
                    funcpara += listPara % (valuename[i], valuename[i], objname, _para)

                else:
                    para_h += (_deftype + " " + valuename[i] + " = " + default_value)
                    para_cpp += (_deftype + " " + valuename[i])
                    funcpara += funcPara % (objname, _para, valuename[i])

                if i < len(deftype) - 1:
                    para_h += ", "
                    para_cpp += ", "

            funcstr_h += SendProto_h_func % (funcName, para_h == "" and "int userId = 1, lspb::ModuleId moduleId = lspb::ModuleId::Game" or ("%s, int userId = 1, lspb::ModuleId moduleId = lspb::ModuleId::Game") % para_h)
            funcstr_cpp += funcClient % (funcName, para_cpp == "" and "int userId, ModuleId moduleId" or ("%s, int userId, ModuleId moduleId" % para_cpp), funcName, objname, funcName, funcpara, objname, funcName.lower(), objname)

    deleteFile("Client_CPP/cmd/SendProto.h")
    writeFileContent("Client_CPP/cmd/SendProto.h", SendProto_h % (funcstr_h))
    deleteFile("Client_CPP/cmd/SendProto.cpp")
    writeFileContent("Client_CPP/cmd/SendProto.cpp", SendProto_cpp % (funcstr_cpp))

def make_receive_proto():
    (packagename, structList) = parse_proto("./LockstepSrvPB/srvRes.proto")
    switchstr = ""
    funcstr_cpp = ""
    funcstr_h = ""
    for funcName in structList:
        deftype = []
        value = structList[funcName]

        for i in range(len(value)):
            item = value[i]
            if item[0] != "SrvMsgType" and  item[0] != "Result" and  item[0] != "string":
                deftype.append(item[0])

        for i in range(len(deftype)):
            switchstr += switchServer % (deftype[i][0].lower()+deftype[i][1:], deftype[i], deftype[i].lower())
            funcstr_cpp += funcServer % (deftype[i], deftype[i], deftype[i])
            funcstr_h += ReceiveProto_h_func % (deftype[i], deftype[i])

    deleteFile("Client_CPP/cmd/ReceiveProto.h")
    writeFileContent("Client_CPP/cmd/ReceiveProto.h", ReceiveProto_h % (funcstr_h))
    deleteFile("Client_CPP/cmd/ReceiveProto.cpp")
    writeFileContent("Client_CPP/cmd/ReceiveProto.cpp", ReceiveProto_cpp % (switchstr, funcstr_cpp))

def make_proto():
    for root, dirs, files in os.walk("./LockstepSrvPB"):
        for i in range(len(files)):
            (filepath, tempfilename) = os.path.split(files[i]);
            (shotname, extension) = os.path.splitext(tempfilename);
            if extension == '.proto':
                if (platform.system() == 'Windows'):
                    os.system("./LockstepSrvPB/protoc.exe %s --cpp_out=./Client_CPP/pb -I ./LockstepSrvPB" % (root + "/" + files[i]))
                else:
                    os.system("protoc %s --cpp_out=./Client_CPP/pb -I ./LockstepSrvPB" % (root + "/" + files[i]))

if __name__ == "__main__":
    make_proto()
    make_send_proto()
    make_receive_proto()