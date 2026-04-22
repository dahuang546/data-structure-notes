#include<stdio.h>
#define MAXLEN 100

typedef struct 
{
    /* data */
    int data[MAXLEN];
    int length;
}Seqlist;

void initlist(Seqlist *L){
    L->length=0;
}

void showlist(Seqlist *L){
    for(int i=0;i<<L->length-1;i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
}

void adddata(Seqlist *L ,int value){
    L->data[L->length]=value;
    L->length++;   
}

void insertdata(Seqlist *L, int value,int i){
    if(i<0||i>L->length){
        printf("插错位置了宝贝");
        return;
    }
    if(L->length<MAXLEN){
        for(int j=L->length;j>i;j--){
            L->data[j]=L->data[j-1];
        }
    }
    else{
        printf("瓦鲁伊啊，这里坐不下这么多人呢");
    }
    L->data[i]=value;
    L->length++;
}

void delete(Seqlist *L,int i){
    if(i<0||i>L->length){
        printf("搞错了宝贝");
        return;    
    }
    if(L->length>0){
        for(int j=i;j<L->length-1;j++){
            L->data[j]=L->data[j+1];

        }
    }
    else{
        printf("错啦");
    }

    L->length--;
    
}

