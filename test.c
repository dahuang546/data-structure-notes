// #include <stdio.h>
// int main(){
//     printf("hello from clang");
//     return 0;
// }

#include <stdio.h>
#define MAXLEN 100
typedef struct {
    int data[MAXLEN];
    int length;
}Seqlist;

void initlist(Seqlist *L){
    L->length=0;
}
void adddata(Seqlist *L){
    L->data[L->length]=10;
    L->length++;   
}

void showlist(Seqlist *L){
    for(int i=0;i<<L->length-1;i++){
        
    }

}
int main()
{
    Seqlist L;
    initlist(&L);
    printf("当前的长度是%d\n",L.length);
    
    showlist(&L);
    printf("第一个数是%d",L.data[0]);
}