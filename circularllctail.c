//tail pointer
#include<stdlib.h>
#include <stdio.h>
struct node {
    int data;
    struct node *next;
};
void *createcll(struct node *tail){
    int ch;
    tail==NULL;
    struct node *newnode;
    while(ch){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data \n");
    scanf("%d",newnode->data);
    newnode->next=0;
    if(tail==NULL){
        tail=newnode;
        tail->next=newnode;
    }
    else{
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
    printf("do u want to continue ?\n");
    scanf("%d",&ch);
}

}
void display(struct node *tail){
    struct node *temp=tail;
    if(tail==NULL){
        printf("linked list is empty \n");
    }
    else{
        temp=tail->next;//back to starting pointer
        do{
            printf("%d",temp->data);
            temp=temp->next;
        }while(temp!=tail->next);
    }
}
int main()
{
    struct node *tail;
    createcll(tail);
    display(tail);
    return 0;
}