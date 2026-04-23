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
//接下来开始写查找函数，由于我看了 ai 的描述我觉得朴素查找太蠢了，我打算直接尝试开始写人类直觉类型的查找，然后
//我再尝试在里面加入 kmp 算法看看，先尝试一下人类直觉查找，思路是先用第一个字母开始比对，第一个对来开始对第二个，然后依次往下，有一个不对就开始下一个首字母一样的地方开始比对
int 