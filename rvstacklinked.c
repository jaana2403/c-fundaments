//C program to Implement Stack using Singly Linked List
#include <stdio.h>
#include<stdlib.h>
#define SIZE 5
int count =0;
struct node {
    int data;
    struct node * add;
};
typedef struct node * NODE;
NODE push(NODE start, int item){
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    if(count>=SIZE){
        printf("stack overflow\n");
        return start;
    }
    temp->data=item;
    temp->add=start;
    count++;
    return temp;
}
NODE pop(NODE start){
    NODE temp;
    if(start==NULL){
        printf("stack underflow\n");
        return start;
    }
    temp=start;
    start=start->add;
    printf("element popped %d",temp->data);
    free(temp);
    count--;
    return start;
}
void display(NODE start){
    NODE temp;
    if(start==NULL){
        printf("stack is empty");
    }
    else{
        printf("stack contents are \n");
        temp==start;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->add;
        }
    }
}
int main()
{
    NODE start=NULL;
    int ch,item;
    for(;;){
        printf("1 push \n 2 pop \n 3 display \n 4 exit");
        printf("enter number\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: printf("elemnt to be pushed\n");
        scanf("%d",&item);
        start=push(start,item);
            break;
        case 2: start=pop(start);
        break;
        default:exit(0);
            break;
        }
    }
    return 0;
}