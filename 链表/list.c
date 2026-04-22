#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
    
}Node;

Node* initlist(){
    Node *p=malloc(sizeof(Node));
    p->next=NULL;
    return p;
}

void addNode(Node *L, int value){
    Node *p= malloc(sizeof(Node));
    p->data=value;
    p->next=NULL;
    Node *q=L;
    while(q->next!=NULL){
        q=q->next;
    }
    q->next=p;
    
}
void printNode(Node *L){
    Node *q=L->next;
    while (q!=NULL)
    {
        printf("%d",q->data);
        q=q->next;
        printf("\n");
    }
}
void freeNode(Node *L){
    Node*p=L;
    Node *q=NULL;
    while(p!=NULL){
        q=p->next;
        free(p);
        p=q;
    }
    printf("finish free");
}
void insertNode(Node *L,int pos ,int value){
    Node *q=L;
    if(q==NULL||pos<1){
        printf("Error");
        return;
    }
    printf("begin to insert pos %d ,value %d \n",pos,value);
    Node *p;
    for(int i=1;i<pos;i++){
        q=q->next;
    }
    if(q==NULL||pos<1){
        printf("error");
        return;
    }
    p=q->next;
    Node *new=malloc(sizeof(Node));
    new->data=value;
    q->next=new;
    new->next=p;
    printf("success to insert\n");

}


void deleteNode(Node *L, int pos){
    Node *p=L;
    //p是 pos-1
    if(pos<1||p==NULL){
        printf("error");
        return;
    }
    printf("begin to delete\n");
    for(int i=1;i<pos;i++){
        p=p->next;
        if(p==NULL){
            printf("你找的位置超出了链表长度\n");
            return;
        }
    }
    Node *q=p->next;
    //q是 pos
    if(p->next==NULL){
        printf("error");
        return;
    }
    p->next=q->next;
    free(q);
    printf("finish delete\n");

}
Node *searchNode(Node *L,int value){
    Node *p=L->next;
    int i=1;
    while(p!=NULL&&p->data!=value){
        i++;
        p=p->next;
    }
    if(p==NULL){
            printf("链表里没有你想要的值\n");
            return NULL;
        }
    printf("已经找到了你要的值，它是在第%d个位置\n",i);
    return p;
}

void deleteByvalue(Node *L,int value){
    if(L->next==NULL){
        printf("你的链表还是空的删不了");
        return;
    }
    int i=1;
    Node *p=L->next;
    Node *q=L;
    while(p!=NULL&&p->data!=value){
        i++;
        q=q->next;
    //这里 q 就是p 上一个位置
        p=p->next;
    }
    if(p==NULL){
        printf("没有你要的删不了\n");
        return;
    }
    q->next=p->next;
    free(p);
    printf("你要删除的值在第%d个位置，已经成功删除\n",i);

}

int main(){
    Node *L=initlist();
    addNode(L,10);
    addNode(L,20);
    addNode(L,32);
    printNode(L);
    insertNode(L,2,21);
    printNode(L);
    deleteNode(L,3);
    printNode(L);
    searchNode(L,32);
    searchNode(L,99);
    freeNode(L);
    return 0;

}


