src=main.c
bin=a.out
rm ./$bin
gcc $src -o $bin
./a.out
echo 終了