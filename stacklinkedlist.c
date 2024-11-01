// Implement Stack Using Linked List
#include <stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};
void linkedlinsttraversal(struct node * ptr){
    while(ptr!=0){
        printf("\n element of linked list %d",ptr->data);
        ptr=ptr->next;
    }
}
int isempty(struct node * top){
    if(top==NULL)
    return 1;
    return 0;
}
int isfull(struct node * top){
    struct node * p = (struct node *)malloc(sizeof(struct node));
    if(p==NULL);
    return 1;
    return 0;
}
struct node * push(struct node * top ,int x){
    if(!isfull(top)){
        printf("Stack overflow");
    }
    else{
        struct node * p= (struct node * )malloc(sizeof(struct node));
        p->data=x;
        p->next=top;
        top=p;
        return top;
    }
}
int pop(struct node * top){
    struct node *p =top;
    top=top->next;
    int x = p->data;
    free(p);
    return x;
}
int main()
{
    struct node * top=NULL;
    top=push(top,75);
    top=push(top,5);
    top=push(top,4);
    top=push(top,7);
    top=push(top,99);
    top=push(top,8);
    linkedlinsttraversal(top);
    int ele;
    ele=pop(top);
    printf("popped element %d",ele);
    return 0;
}