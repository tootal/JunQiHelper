@echo off
echo Setting up environment for Qt usage...
set PATH=C:\Qt\6.0.0\msvc2019_64\bin;%PATH%
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat" x64

set DIR=build-deploy
set APP=JunQiHelper
if exist %DIR% (
    rmdir /s/q %DIR%
)
mkdir %DIR%
copy ..\build-%APP%-Desktop_Qt_6_0_0_MSVC2019_64bit-Release\%APP%.exe %DIR%
copy build-GlobalHook-Desktop_Qt_6_0_0_MSVC2019_64bit-Release\GlobalHook.dll %DIR%
cd %DIR%
windeployqt %APP%.exe