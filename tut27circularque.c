#include <stdio.h>
#include<stdlib.h>
struct queue{
    int rear,front ;
    int size;
    int *Q;
};
//circular queue 
void create(struct queue *t){
    printf("enter size");
    scanf("%d",&t->size);
    t->Q=(int *)malloc(t->size*sizeof(int));
    t->front=t->rear=-1;
}
void enqueue(struct queue *q ,int x){
    if((q->rear+1)%q->size==q->front)
    printf("queue is full \n");
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
int dequeue(struct queue *q ){
    int x=0;
    if(q->front==q->rear)
    printf("empty queue\n");
    else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
void display(struct queue *q){

}
int main()
{
    struct queue m;
    create(&m);
    enqueue(&m,10);
    enqueue(&m,20);
    enqueue(&m,30);
    enqueue(&m,40);
    enqueue(&m,50);
    printf("%d ",dequeue(&m));
    printf("%d ",dequeue(&m));
    printf("%d ",dequeue(&m));
    printf("%d ",dequeue(&m));
    printf("%d ",dequeue(&m));
    printf("%d ",dequeue(&m));
    enqueue(&m,100);
    printf("%d ",dequeue(&m));
    return 0;
}