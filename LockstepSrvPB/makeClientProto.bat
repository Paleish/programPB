for %%i in (*.proto) do (
    protoc.exe --cpp_out=../Client_CPP %%i
)
for %%i in (*.proto) do (
    protoc.exe --csharp_out=../Client_CSHARP/pb %%i
)
pause