#include <stdio.h>
#include<stdlib.h>
struct queue{
    int front ,rear ;
    int size;
    int *q;
};
void create(struct queue *Q){
    printf("enter size \n");
    scanf("%d",&Q->size);
    Q->q=(int *)malloc(Q->size*sizeof(int));
    Q->front=Q->rear=-1;
}
void enqueue(struct queue *Q,int x){
    if(Q->rear==Q->size-1)
    printf("queue is full");
    else{
        Q->rear++;
        Q->q[Q->rear]=x;
    }
}
int dequeue(struct queue *Q){
    int x=-1;
    if(Q->front==Q->rear)
    printf("queue is empty \n");
    else{
        Q->front++;
        x=Q->q[Q->front];
       
    }
    return x;
}
void display(struct queue *Q){
    for (int i = Q->front+1; i <=Q->rear ; i++)
    {
        /* code */
        printf("%d ",Q->q[i]);
    }
    
}
int main()
{
    struct queue Q;
    create(&Q);
    enqueue(&Q,10);
    enqueue(&Q,20);
    enqueue(&Q,30);
    enqueue(&Q,40);
    enqueue(&Q,50);
    display(&Q);
    printf("%d ",dequeue(&Q));
    return 0;
}