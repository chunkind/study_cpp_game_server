pushd %~dp0

protoc.exe -I=./ --cpp_out=./ ./Enum.proto
protoc.exe -I=./ --cpp_out=./ ./Struct.proto
protoc.exe -I=./ --cpp_out=./ ./Protocol.proto

IF ERRORLEVEL 1 PAUSE

XCOPY /Y Enum.pb.h "../../../Server"
XCOPY /Y Enum.pb.cc "../../../Server"
XCOPY /Y Struct.pb.h "../../../Server"
XCOPY /Y Struct.pb.cc "../../../Server"
XCOPY /Y Protocol.pb.h "../../../Server"
XCOPY /Y Protocol.pb.cc "../../../Server"

XCOPY /Y Enum.pb.h "../../../DummyClient"
XCOPY /Y Enum.pb.cc "../../../DummyClient"
XCOPY /Y Struct.pb.h "../../../DummyClient"
XCOPY /Y Struct.pb.cc "../../../DummyClient"
XCOPY /Y Protocol.pb.h "../../../DummyClient"
XCOPY /Y Protocol.pb.cc "../../../DummyClient"

XCOPY /Y Enum.pb.h "../../../GameCoding"
XCOPY /Y Enum.pb.cc "../../../GameCoding"
XCOPY /Y Struct.pb.h "../../../GameCoding"
XCOPY /Y Struct.pb.cc "../../../GameCoding"
XCOPY /Y Protocol.pb.h "../../../GameCoding"
XCOPY /Y Protocol.pb.cc "../../../GameCoding"

DEL /Q /F *.pb.h
DEL /Q /F *.pb.cc
DEL /Q /F *.h

PAUSE