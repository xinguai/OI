@echo off
if "%1"=="" goto loop
copy symbol%1.in symbol.in >nul
echo Problem Test
echo Data %1
time<enter
symbol.exe
time<enter
copy symbol%1.out symbol.ans >nul
fc symbol.out symbol.ans
del symbol.in
del symbol.out
del symbol.ans
pause
goto quit
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:quit
