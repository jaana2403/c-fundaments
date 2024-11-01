//creation of doubly linked list 
#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
void display(struct node * head){
    struct node * temp;
    temp =head;
    printf("displaying");
    while (temp!=0)
    {
          /* code */
          printf("%d ", temp->data);
          temp=temp->next;
    }
    
}
void deletebeg(struct node *head){
    struct node* temp;
    temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
}
void deleteatpos(struct node *head){
    
    int pos;
    int i=1;
    printf("\nenter postion u want to delte node");
    scanf("%d",&pos);
    struct node *temp;
    temp=head;
    while(i<pos){
        temp=temp->next;
        i++;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    printf("\nsuccessfully deleted\n");
    free(temp);
}
void deleteatend(struct node* tail){
    struct node *temp;
    temp=tail;
    tail->prev->next=NULL;
    tail=tail->prev;
    free(temp);
}
int main()
{
    int ch;
    struct node *head,*newnode,*tail ,*temp;
    head=0;
    while(ch){
    newnode=(struct node*) malloc (sizeof(struct node));
    printf("enter data ");
    scanf("%d",&newnode->data);
    newnode->prev=0;
    newnode->next=0;
    if(head==0){
        head=tail=temp=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
    printf("do you want to continue 0,1 - ");
    scanf("%d",&ch);
    }
   display(head);
  //  deleteatpos(head);
// ERROR   deletebeg(head);
deleteatend(tail);
    display(head);
    return 0;
}