SET file=%~1
rem set gccpath=C:\Users\mzxrules\Documents\Galatea\gcc
set gccpath=C:\Users\mzxrules\Documents\c\n64chain-win64-0717\tools
set sourcepath=C:\Users\mzxrules\Google Drive\~zelda\ocarina\C
set workpath=C:\Users\mzxrules\Documents\c\work\test
set fullsourcepath="%sourcepath%\%file%.sx"
set fullobjpath="%workpath%\%file%.o"
echo %fullsourcepath%

start "mips64-gcc-5.2.0" /B /D "%gccpath%\bin" "%gccpath%\bin\mips64-elf-gcc.exe" -march=vr4300 -mabi=32 -O0 -mno-check-zero-division -mno-gpopt -mexplicit-relocs -I "C:\Users\mzxrules\Documents\c\gcc\mips64\include" -c -o %fullobjpath% %fullsourcepath% 
