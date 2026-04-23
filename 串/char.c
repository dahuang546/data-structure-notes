#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXLEN 100
typedef struct Str
{
    char ch[MAXLEN];
    int length;
}Str;
//先写清空函数
void clearStr(Str *s){
    s->length=0;
    s->ch[0]='\0';
}
//再写拼接函数
void concatantionStr(Str *s,Str *t){
    if(s->length+t->length>=100){
        printf("error,thats more");
    }
    else{

    
        int i=0;
        while(t->ch[i]!='\0'){
            
            s->ch[s->length]=t->ch[i];
            s->length++;
            i++;     
        }
        s->ch[s->length]='\0';
        }

}
//初始化函数**实际上就是全部化空哈哈
void initStr(Str *s){
    s->ch[0]='\0';
    s->length=0;
}
//接下来是复制函数，实际上就是把一个串先清空再拼接，没啥好说的
void copyStr(Str *s,Str *t){
    clearStr(s);
    concatantionStr(s,t);
    printf("拼接完毕，你可以查看一下: ",&s);
}