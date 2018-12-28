@echo off
@echo Cleaning HTTPSYS directories
@echo .

call sourceclean.cmd

echo .
echo Ready cleaning
echo .
echo Creating a rar archive for the HTTPSYS driver
echo .
"C:\Program Files\Winrar\rar.exe" a HTTPSYS.rar HTTPSYS Documentation *.cmd README.md Planning.md .gitignore LICENSE sourceclean.cmd
echo .
echo Ready making RAR archive
echo .
robocopy . C:\Users\%USERNAME%\OneDrive\Documents HTTPSYS.rar /xo
echo .
echo Ready copying the archive to the OneDrive cloud.
pause
