/*
pythonは楽だけどメモリー消費が大きいので、できるだけCで書きたいけど面倒だからpythonで書きたい。（無限ループ）
というわけでコピペして使うC言語便利ライブラリを作りました。
*/
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>
//-----------------定数-----------------
#define STRLEN 255
//リスト
struct strListElement{
    struct strListElement *backElementPointer;
    char str[STRLEN];
    struct strListElement *nextElementPointer;
};
typedef struct strListElement strListElement;

//リストの生成
strListElement* getNewStrList(){
    //リスト要素を格納する領域を確保する。
    strListElement* firstStrListElement;
    firstStrListElement = (strListElement*)malloc(sizeof(strListElement));
    firstStrListElement->backElementPointer = NULL;
    strcpy(firstStrListElement->str,"");
    firstStrListElement->nextElementPointer = NULL;
    return firstStrListElement;
}
//リストの参照
char* getStrElementValue(strListElement* sle,int index){
    strListElement* tmpElement = sle;
    for(int nowStrListIndex=0;nowStrListIndex<index;nowStrListIndex++){
        if(tmpElement->nextElementPointer != NULL){
            tmpElement = tmpElement->nextElementPointer;
        }else{
            puts("Error:Out of Index.");
            return NULL;
        }
    }
    return tmpElement->str;
}
//リストの参照
void setStrElementValue(strListElement* sle,int index,char* str){
    strListElement* tmpElement = sle;
    for(int nowStrListIndex=0;nowStrListIndex<index;nowStrListIndex++){
        if(tmpElement->nextElementPointer != NULL){
            tmpElement = tmpElement->nextElementPointer;
        }else{
            puts("Error:Out of Index.");
            return NULL;
        }
    }
    strcpy(tmpElement->str,str);
}
//リストへ要素の追加
void appendStr(strListElement* sle,char* str){
    strListElement* tmp = sle;
    while(tmp->nextElementPointer != NULL){
        tmp = tmp->nextElementPointer;
    }
    tmp->nextElementPointer = (strListElement*)malloc(sizeof(strListElement));
    tmp->nextElementPointer->backElementPointer = tmp;
    tmp = tmp->nextElementPointer;
    tmp->nextElementPointer = NULL;
    strcpy(tmp->str,str);
}
//リストの要素数を取得する
size_t lenStr(strListElement* sle){
    strListElement* tmp = sle;
    size_t count = 1;
    for(;tmp->nextElementPointer != NULL;count++){
        tmp = tmp->nextElementPointer;
    }
    return count;
}
//--------------int型List-----------------
//リスト
struct intListElement{
    struct intListElement *backElementPointer;
    int v;
    struct intListElement *nextElementPointer;
};
typedef struct intListElement intListElement;

//リストの生成
intListElement* getNewIntList(){
    //リスト要素を格納する領域を確保する。
    intListElement* firstIntListElement;
    firstIntListElement = (intListElement*)malloc(sizeof(intListElement));
    firstIntListElement->backElementPointer = NULL;
    firstIntListElement->v = 0;
    firstIntListElement->nextElementPointer = NULL;
    return firstIntListElement;
}
//リストの参照
int getintElementValue(intListElement* sle,int index){
    intListElement* tmpElement = sle;
    for(int nowIntListIndex=0;nowIntListIndex<index;nowIntListIndex++){
        if(tmpElement->nextElementPointer != NULL){
            tmpElement = tmpElement->nextElementPointer;
        }else{
            puts("Error:Out of Index.");
            return NULL;
        }
    }
    return tmpElement->v;
}
//リストの参照
void setIntElementValue(intListElement* ile,int index,int v){
    intListElement* tmpElement = ile;
    for(int nowIntListIndex=0;nowIntListIndex<index;nowIntListIndex++){
        if(tmpElement->nextElementPointer != NULL){
            tmpElement = tmpElement->nextElementPointer;
        }else{
            puts("Error:Out of Index.");
            return NULL;
        }
    }
    tmpElement->v = v;
}
//リストへ要素の追加
void appendInt(intListElement* ile,int v){
    intListElement* tmp = ile;
    while(tmp->nextElementPointer != NULL){
        tmp = tmp->nextElementPointer;
    }
    tmp->nextElementPointer = (intListElement*)malloc(sizeof(intListElement));
    tmp->nextElementPointer->backElementPointer = tmp;
    tmp = tmp->nextElementPointer;
    tmp->nextElementPointer = NULL;
    tmp->v = v;
}
//リストの要素数を取得する
size_t lenInt(intListElement* ile){
    intListElement* tmp = ile;
    size_t count = 1;
    for(;tmp->nextElementPointer != NULL;count++){
        tmp = tmp->nextElementPointer;
    }
    return count;
}

//型変換系
int Int(char* str){
    return atoi(str);
}
char* input(){
    char tmpstr[255];
    fgets(tmpstr,sizeof(tmpstr),stdin);
    return tmpstr;
}
strListElement* split(char* str,char* sep){
    char *tp;
    strListElement* ret = getNewStrList();
    tp = strtok(str,sep);
    strcpy(ret->str,tp);
    while ( tp != NULL ) {
            tp = strtok( NULL,sep);
            if ( tp != NULL ){
                appendStr(ret,tp);
            }
    }
    return ret;
}
intListElement *mapStrToInt(strListElement* sle){
    strListElement* tmp = sle;
    intListElement* ret = (intListElement*)malloc(sizeof(intListElement));
    int index=0;
    for(;index < lenStr(sle);index++){
        if(index==0){
            setIntElementValue(ret,0,Int(tmp->str));
        }else{
            appendInt(ret,Int(tmp->str));
        }
        if(tmp->nextElementPointer != NULL) tmp = tmp->nextElementPointer;
    }
    return ret;
}
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
int main(int argc,char* argv[]){
    intListElement* input_line = mapStrToInt(split(input()," "));
    int mon = getintElementValue(input_line,0);
    int c = getintElementValue(input_line,1);
    int point = 0;
    for(int i=0;i<c;i++){
        int charge = Int(input());
        if(point >= charge){
            point -= charge;
        }else{
            mon -= charge;
            point += (charge*0.1);
        }
        printf("%d %d\n",mon,point);
    }
}