#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
}*rear=NULL,*front=NULL;
void enqueue(int x){
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL){
        printf("heap is full memory not allocated \n");
    } 
    t->data=x;
    t->next=NULL;
    
        if(front==NULL){   
        front=rear=t;
        }
        else{
            rear->next=t;
            rear=t;
        }
    }

int dequeue(){
    int x=-1;
    struct node *p;
    if(front==NULL){
        printf("queue is empty");
    }
    else{
        p=front;
        front=front->next;
        x=p->data;
        free(p);
    }
    return x;
}
int main()
{
    enqueue(10);
    enqueue(500);
    enqueue(30);
    printf("elemnt that is delete %d ",dequeue()); 
//    printf("%d ",dequeue());
//    printf("%d ",dequeue());
//    printf("%d ",dequeue());
    return 0;
}