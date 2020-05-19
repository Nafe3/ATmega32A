@echo off

SETLOCAL EnableDelayedExpansion

IF EXIST "Progress.txt" (
GOTO INC
)

echo 1 >>"Progress.txt" 

goto END
:INC 

set /p Rval=< Progress.txt


set /a Rval=%Rval%+1

ECHO %Rval% > "Progress.txt" 

:END 
Exit 0

 
 





   



