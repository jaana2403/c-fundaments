//Deletion in a Linked List | Deleting a node from Linked List Data Structure
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
struct node * deleteatbeg(struct node * head){
    struct node * temp = head;
    head=head->next;
    free(temp );
    return head;
}
struct node * deleteatpos(struct node * head,int pos){
    struct node * p=head;
    struct node * q=head->next;
    int i =0;
    while(i=!pos-1){
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    free(q);
    return head;
}
struct node * deleteatend(struct node * head){
    struct node * p=head;
    struct node * q=head->next;
    int i =0;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=NULL;
    free(q);
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
    fourth->next=NULL;
  printf("deletion of nodes\n");
//   head=deleteatbeg(head);
//   linkedlinsttraversal(head);
//head=deleteatpos(head,1);
head=deleteatend(head);
linkedlinsttraversal(head);
    return 0;
}