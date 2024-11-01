//circular linked list creation 
#include <stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node * next;
};
void linkedlinsttraversal(struct node * head){
    struct node * ptr=head;
    // printf("elements of linked list %d\n",ptr->data);
    // ptr=ptr->next;
    // while(ptr!=head){
    //     printf(" element of linked list %d\n",ptr->data);
    //     ptr=ptr->next;
    // }
    do{
        printf(" element of linked list %d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}
struct node * insertatbeg(struct node * head,int data){
    struct node * ptr=(struct node * )malloc(sizeof(struct node));
     ptr->data=data;
     struct node * p=head->next;
    while(p->next!=head){
        p=p->next;
    }
    //at this point p is point at last node
    p->next=ptr;
    ptr->next=head;
   
    head=ptr;
    return head;
}

int main()
{
    int pos;
    struct node * head;
    head=(struct node * ) malloc(sizeof(struct node));
    struct node * second;
    second=(struct node * ) malloc(sizeof(struct node));
    struct node * third ;
third    =(struct node * ) malloc(sizeof(struct node));
    struct node * fourth;
   fourth =(struct node * ) malloc(sizeof(struct node));
    head->data=10;
    head->next=second;
    second->data=20;
    second->next=third;
    third->data=30;
    third->next=fourth;
    fourth->data=40;
    fourth->next=head;
    linkedlinsttraversal(head);
  head=insertatbeg(head,55);
  linkedlinsttraversal(head);
    return 0;
}