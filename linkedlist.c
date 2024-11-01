//creation and insertion of nodes in linked list
#include <stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node * next;
};
void linkedlinsttraversal(struct node * ptr){
    while(ptr!=0){
        printf("\n element of linked list %d",ptr->data);
        ptr=ptr->next;
    }
}
struct node * insertatbeg(struct node * head, int data){
    struct node * ptr = (struct node * )malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
struct node * insertatbtw(struct node * head , int data , int index){
    struct node * ptr = (struct node * )malloc(sizeof(struct node));
    struct node * temp =head;
    int i =0;
    while(i!=index-1){
        temp = temp->next;
        i++;
    }
    ptr->next = temp->next;
    temp->next=ptr;
    ptr->data=data;
    return ptr;
}
struct node * insertatend(struct node * head, int data){
    struct node * ptr = (struct node * )malloc(sizeof(struct node));
    struct node * p =head;
    ptr->data=data;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;

    return ptr;
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
    fourth->next=NULL;
    linkedlinsttraversal(head);
  //  head = insertatbeg(head,55);
   // linkedlinsttraversal(head);
    // printf("\nenter index\n");
    // scanf("%d",pos);
    // head= insertatbtw(head,75,pos);
    head=insertatend(head,99);

    linkedlinsttraversal(head);
    return 0;
}