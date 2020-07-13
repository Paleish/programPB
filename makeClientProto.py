# coding=utf-8
import os

ReceiveProto = """
using Google.Protobuf;
using Lspb;
using System;
using System.Collections.Generic;

namespace CSharpClient.Net.Cmd
{
    public class ReceiveProto
    {
        private static T Deserialize<T>(byte[] data) where T : class, IMessage, new()
        {
            T obj = new T();
            IMessage message = obj.Descriptor.Parser.ParseFrom(data);
            return message as T;
        }

        public void Decode(byte[] buffer)
        {
            SrvRes res = Deserialize<SrvRes>(buffer);
            switch (res.MethodId)
            {%s
                default:
                    Console.WriteLine("proto error no {0}", res.MethodId);
                    break;
            }
        }
%s
    }
}
"""

switchServer = """
                case SrvMsgType.%s:
                    %s(res.%s, res.Result, res.ErrStr);
                    break;"""

funcServer = """
        public virtual void %s(%s msg, Result result, string errStr)
        {
            Console.WriteLine("-----------------------no implements %s-----------------------");
        }
"""

SendProto = """
using Google.Protobuf;
using Lspb;
using System.Collections.Generic;

namespace CSharpClient.Net.Cmd
{
    public class SendProto
    {
        public static byte[] Serialize<T>(T obj) where T : IMessage
        {
            return obj.ToByteArray();
        }

        private static CliReq CreateCliReq(ClientMsgType methodId, int userId = 1, ModuleId moduleId = ModuleId.Game)
        {
            return new CliReq
            {
                UserId = userId,
                ModuleId = moduleId,
                MethodId = methodId,
            };
        }
%s
    }
}
"""

funcClient = """
        public static CliReq %s(%s)
        {
            %s %s = new %s();
%s
            CliReq req = CreateCliReq(ClientMsgType.%s);
            req.%s = %s;
            return req;
        }
"""

funcPara = """            %s.%s = %s;
"""

def getFileContent(fileName):
    all_the_text = ""
    try:
        file_object = open(fileName, 'r')
        all_the_text = file_object.read()
        file_object.close()
    except:
        pass
    return all_the_text

def writeFileContent(fileName, strContent, strEncoding='utf-8'):
    try:
        bycontent = strContent.encode('utf-8')
        output = open(fileName, 'wb')
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
            if defType == 'repeated':
                defType = "IEnumerable<%s>" % (valueName)
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
    (packagename, structList) = parse_proto('/Users/yons/workspace/programPB/LockstepSrvPB/gameProto.proto')
    funcstr = ''
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

            para = ''
            funcpara = ''
            for i in range(len(deftype)):
                _deftype = deftype[i].replace('32', '').replace('64', '')
                para += (_deftype + ' ' + valuename[i])
                _para = valuename[i][0].upper() + valuename[i][1:]
                funcpara += funcPara % (objname, _para, valuename[i])
                if i < len(deftype) - 1:
                    para += ', '

            funcstr += funcClient % (funcName, para, funcName, objname, funcName, funcpara, funcName, funcName, objname)
    deleteFile("Client_CSHARP/cmd/SendProto.cs")
    writeFileContent("Client_CSHARP/cmd/SendProto.cs", SendProto % (funcstr))

def make_receive_proto():
    (packagename, structList) = parse_proto('/Users/yons/workspace/programPB/LockstepSrvPB/srvRes.proto')
    switchstr = ''
    funcstr = ''
    for funcName in structList:
        deftype = []
        value = structList[funcName]

        for i in range(len(value)):
            item = value[i]
            if item[0] != 'SrvMsgType' and  item[0] != 'Result' and  item[0] != 'string':
                deftype.append(item[0])

        for i in range(len(deftype)):
            switchstr += switchServer % (deftype[i], deftype[i], deftype[i])
            funcstr += funcServer % (deftype[i], deftype[i], deftype[i])

    deleteFile("Client_CSHARP/cmd/ReceiveProto.cs")
    writeFileContent("Client_CSHARP/cmd/ReceiveProto.cs", ReceiveProto % (switchstr, funcstr))

if __name__ == "__main__":
    make_send_proto();
    make_receive_proto();