@echo off
@echo Cleaning HTTPSYS directories
@echo .

attrib -h .vs

del httpsys.rar
del /q /s /f *.sdf
del /q /s /f *.VC.db
rmdir /q /s .vs
rmdir /q /s x64
rmdir /q /s Win32
rmdir /q /s Debug
rmdir /q /s Release
rmdir /q /s HTTPSYS\x64
rmdir /q /s HTTPSYS\Debug
rmdir /q /s HTTPSYS\Release
rmdir /q /s BinDebug_x64

echo .
echo Ready cleaning
