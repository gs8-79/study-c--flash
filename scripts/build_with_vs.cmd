@echo off
setlocal

set VSDEV=C:\Program Files\Microsoft Visual Studio\18\Community\Common7\Tools\VsDevCmd.bat

if not exist "%VSDEV%" (
    echo Visual Studio developer command script not found:
    echo %VSDEV%
    exit /b 1
)

call "%VSDEV%" -arch=x64
if errorlevel 1 exit /b 1

call "%~dp0build_all.cmd"
exit /b %errorlevel%
