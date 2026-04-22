#include<stdio.h>
#include<stdbool.h>
#define MAXLEN 10
typedef struct stack
{
    /* data */
    int data[MAXLEN];
    int top;
}stack;

void initstack(stack *S){
    S->top=-1;
}
bool ifempty(stack *S){
    return S->top==-1;
}

bool iffull(stack *S){
    return S->top==MAXLEN-1;
    
}
void push(stack *S,int value){
    if(iffull(S)){
        printf("抱歉栈满了没法出栈\n");
    }
    else{
        S->top++;
        S->data[S->top]=value;
        printf("%d成功压栈\n",value);
    }
    
}
// int pop(stack *S){
//     if(ifempty(S)){
//         printf("抱歉没有可以出的数值了\n");
//         return 0;
//     }
//     else{
//         int value=S->data[S->top];
//         S->top--;
//         printf("出栈%d成功\n",value);
//         return value;
//     }
// }

bool pop(stack *S,int *res){
    if(ifempty(S)){
        printf("抱歉满了没法压栈\n");
        return false;
    }
    else{
        *res=S->data[S->top];
        S->top--;
        printf("出栈%d成功\n",*res);
        return true;
    }
}

int main(){
    stack s;
    initstack(&s);
    push(&s,10);
    push(&s,14);
    push(&s,21);
    int val;
    if(pop(&s,&val)){
        printf("主函数拿到出栈值%d\n",val);
    }
    if(pop(&s,&val)){
        printf("主函数拿到出栈值%d\n",val);
    }
    return 0;
}