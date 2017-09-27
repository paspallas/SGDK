@ECHO OFF
@SETLOCAL
SET "GDK=%cd:\=/%"
SET "GDK_WIN=%cd%"
SET PATH=%GDK_WIN%\bin;%PATH%

for /d %%i in (%GDK%\sample\*) do (

cd "%%i"
echo Building sample:
cd

@RD /S /Q "out"

make -f %GDK_WIN%\makefile.gen release > nul

cd out
del *.o *.d *.out rom_head.bin
@RD /S /Q "res" 
@RD /S /Q "src"

cd ..
)
