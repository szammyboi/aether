@echo off
set arg1=%1
IF %1.==. set arg1=debug

premake5 ninja & ninja %arg1%
build\bin\%arg1%\Aether.exe