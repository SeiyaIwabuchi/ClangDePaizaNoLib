/*
input_line = list(map(int,input().split()))
mon = input_line[0]
c = input_line[1]
point = 0
for i in range(c):
    charge = int(input())
    if point >= charge:
        point -= charge
    else:
        mon -= charge
        point += (charge*0.1)
    print(str(int(mon)) + " " + str(int(point)))
*/
/*
pythonは楽だけどメモリー消費が大きいので、できるだけCで書きたいけど面倒だからpythonで書きたい。（無限ループ）
というわけでコピペして使うC言語便利ライブラリを作りました。
*/
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

//まずは型変換系
int Int(char* str){
    return atoi(str);
}
char* input(){
    char tmpstr[255];
    fgets(tmpstr,sizeof(tmpstr),stdin);
    return tmpstr;
}
char** split(char* str){
    
}
int main(int argc,char* argv[]){

}