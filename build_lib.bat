@ECHO OFF
@SETLOCAL
SET "GDK=%cd:\=/%"
SET "GDK_WIN=%cd%"
SET PATH=%GDK_WIN%\bin;%PATH%

make -f %GDK_WIN%\makelib.gen cleanrelease
make -f %GDK_WIN%\makelib.gen release
IF %ERRORLEVEL% NEQ 0 goto: ERROR

make -f %GDK_WIN%\makelib.gen cleandebug
make -f %GDK_WIN%\makelib.gen debug
IF %ERRORLEVEL% NEQ 0 goto: ERROR

@ECHO.
@ECHO.
@ECHO -------------------------------------------
@ECHO SGDK is now ready! Press any key to exit...
@PAUSE >nul
goto: EOF

:ERROR
@ECHO.
@ECHO.
@ECHO An error has ocurred while building SGDK

:EOF
