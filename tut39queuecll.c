#include <stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
}*root=NULL;
void create(int x){
    struct node *t ,*p;
    t=(struct node *)malloc(sizeof(struct node));
    if(t==NULL){
        printf("memory allocation failed");
    }
    t->data=x;
    if(root==NULL){
        t->next=t;
        root=t;
    }
    else{
        p=root;
        while(p->next!=root)
        p=p->next;
        p->next=t;
        t->next=root;
    }
}
int delete(){
    struct node *t=root,*p=root;
    int x=0;
    if(root==NULL){
        printf("queue is empty \n");
        return 0;
    }
    else {
        while(p->next!=root)
        p=p->next;
        p->next=root->next;
        root=root->next;
        
        x= t->data;
        free(t);
    }
    return x;
}
void display(){
    struct node *t=root;
    while(t->next!=root){
        printf("%d ",t->data);
        t=t->next;
    }
    printf("%d \n",t->data);
}
int main()
{
    create(10);
    create(20);
    create(30);
    create(40);
    create(50);
    display();
    printf("elemet delete from queue is %d \n",delete());
    printf("elemet delete from queue is %d \n",delete());
    return 0;
}