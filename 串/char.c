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

void initStr(Str *s){
    s->ch[0]='\0';
    s->length=0;
}
