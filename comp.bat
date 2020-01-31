rm ./a.exe
set src=%1
set bin=a.exe
echo gcc %src% -o %bin%
call gcc %src% -o %bin%
call .\a.exe