#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node
{
    int data;
    struct Node *next;
}Node;

typedef struct queue
{
    Node *front;
    Node *rear;
}Queue;

Queue *initQueue(){
    Node *p=malloc(sizeof(Node));
    Queue *Q=(Queue*)malloc(sizeof(Queue));
    p->next=NULL;
    Q->front=p;
    Q->rear=p;
    return Q;
}

bool ifempty(Queue *Q){
    return Q->front==Q->rear;
}
void enQueue(Queue *Q,int value){
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=value;
    p->next=NULL;
    Q->rear->next=p;
    Q->rear=p;
    return;
}
 void outQueue(Queue *Q,int *res){
    *res=Q->front->data;
    Node *p=Q->front;
    Q->front=Q->front->next;
    free(p);
    return;
 }