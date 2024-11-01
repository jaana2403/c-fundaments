#include <stdio.h>
#include<stdlib.h>
struct node{
    struct node *lc;
    int data;
    struct node *rc;
}*root=NULL;
struct queue{
    int size;
    int front;
    int rear;
    struct node **Q;
};
void createq(struct queue *q){
    printf("enter size \n");
    scanf("%d",&q->size);
    q->Q=(struct node **)malloc((q->size)*sizeof(struct node));
    q->front=q->rear=-1;
}
void enqueue(struct queue *q,struct node *x){
    if(q->front==(q->rear+1)%q->size){
        printf("queue is full");
    }
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
struct node *dequeue(struct queue *q){
    struct node *x=NULL;
    if(q->front==q->rear){
        printf("queue is empty");
    }
    else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
return x;
}
int isempty(struct queue *q){
    return q->front==q->rear;
}
void create(){
    struct node *p,*t;
    int x;
    struct queue q;
    createq(&q);
    printf("Enter root value \n");
    scanf("%d",&x);
    root=(struct node *)malloc(sizeof(struct node));
    root->data=x;
    root->lc=root->rc=NULL;
    enqueue(&q,root);
    while(!isempty(&q)){
        p=dequeue(&q);
        printf("enter left child \n");
        scanf("%d",&x);
        if(x!=-1){
            t=(struct node *)malloc(sizeof(struct node));
            t->data=x;
             t->lc=t->rc=NULL;
             p->lc=t;
             enqueue(&q,t);
        }
         printf("enter right child \n");
        scanf("%d",&x);
        if(x!=-1){
            t=(struct node *)malloc(sizeof(struct node));
            t->data=x;
             t->lc=t->rc=NULL;
             p->rc=t;
             enqueue(&q,t);
        }
    }
}
void preorder(struct node *p){
    if(p){
        printf("%d ",p->data);
        preorder(p->lc);
        preorder(p->rc);
    }
}
int main()
{
    create();
    preorder(root);

    return 0;
}