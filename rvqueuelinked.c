//C Program to Implement Queue using Singly Linked List
#include <stdio.h>
#include<stdlib.h>
#define N 5
int count =0;
struct node {
    int data ;
    struct node * add;
};
typedef struct node * NODE;
NODE enqueue(NODE start, int item){
    NODE cur,temp;
    if(count>=N){
        printf("\n queue is full");
        return start;
    }
    temp=(NODE )malloc(sizeof(struct node));
    temp->data=item;
    temp->add=NULL;
    cur=start;
    while(cur->add!=NULL){
        cur=cur->add;
    }
    cur->add=temp;
    count++;
    return start;
}
NODE dequeue(NODE start){
    NODE temp;
    if(start==NULL){
        printf("queue is empty");
        return NULL;
    }
    temp=start;
    start=start->add;
    free(temp);
    count--;
    return start;
}
void display(NODE start){
    NODE temp;
    if(start==NULL){
        printf("\n queue is empty");
    }
    else{
        printf("contents are\n");
        temp=start;
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->add;
        }
    }
}
int main()
{
    NODE start=NULL;
    int ch,item;
    for(;;){
        printf("1 enqueue \n 2 dequeue \n 3 display \n 4 exit");
        printf("enter number\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: printf("elemnt to be pushed\n");
        scanf("%d",&item);
        start=enqueue(start,item);
            break;
        case 2: start=dequeue(start);
        break;
        case 3:
        display(start);
        break;
        default:exit(0);
            break;
        }
    }
    return 0;
}