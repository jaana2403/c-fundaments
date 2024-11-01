//circular linked list and its various opeartions
//using tail and head pointer we can do this using only tail pointer
#include <stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};
struct node * create(struct node * head){
    int x,ch;
    struct node *newnode, *tail, *temp;
    head=NULL;
    while(ch){
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter data \n");
    scanf("%d",&x);
    newnode->data=x;
    newnode->next=0;
    if(head==0){
        head=tail=newnode;
        tail->next=newnode;
    }
    else{
        tail->next=newnode;
        tail=newnode;
        tail->next=head;
    }
    printf("do you want to continue (0,1) ? \n");
    scanf("%d",&ch);
    }
    return head;
}
void display(struct node *head){
    struct node *temp;
    temp=head;
    if(head==NULL){
        printf("linked list is empty ...");
    }
    else{
    
        do{
            printf("%d\t",temp->data);
            temp=temp->next;
        }while(temp!=head);
}
}
void insertatbeg(struct node *head){
    struct node *
}
int main()
{
    struct node * head=NULL;
    struct node *p;
p=create(head);
    display(p);
    return 0;
}