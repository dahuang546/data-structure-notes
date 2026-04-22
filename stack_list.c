#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node* initNode(){
    Node *p=(Node*)malloc(sizeof(Node));
    p->next=NULL;
    return p;
}

bool ifempty(Node *L){
    return L->next==NULL;
}

void push(Node *L,int value){
    Node *p=malloc(sizeof(Node));
    p->data=value;
    if(ifempty(L)){
        L->next=p;
        //如果这里写的是p=L->next会怎么样豆包你告诉我
        
        p->next=NULL;
        printf("压栈%d成功这是第一个节点\n",value);
    }
    else{
        Node *q=L->next;
        L->next=p;
        p->next=q;
        printf("压栈%d成功\n",value);
    }
}

bool pop(Node *L,int *res){
    if(ifempty(L)){
        printf("栈空无法出栈\n");
        return false;
    }
    else{
        Node *q=L->next;
        *res=q->data;
        L->next=q->next;
        free(q);
        printf("成功出栈%d\n",*res);
        return true;
    }
}

int main(){
    Node *L = initNode(); // 接收头结点指针，和链表一致
    int val; // 普通变量接出栈值

    // 压栈测试
    push(L, 10);
    push(L, 20);
    push(L, 30);

    // 出栈测试
    pop(L, &val);
    pop(L, &val);
    pop(L, &val);
    pop(L, &val); // 测试空栈出栈

    return 0;
}