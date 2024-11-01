#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*top=NULL;
void push(int x){
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL)
    printf("stack overflow \n");
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}
void display(){
    struct node *p;
    if(p==NULL)
    printf("stack empty");
    else{while(p!=NULL){
         printf("%d ",p->data);
            p=p->next;
        }
        
    }
}
int pop(){
    struct node *t;
    if(top==NULL){
        printf("stack underflow");
    }
    else{
        t=top;
        top=top->next;
        return t->data;
        free(t);
    }
}
void search(int x){
    struct node *p=top;
    while(p!=NULL){
        if(p->data==x){
            printf("element found ");
        }
        p=p->next;
    }
    
}
int main()
{
    push(10);
    push(20);
     push(30);
      push(40);
       push(50);
       display();
       search(10);
    printf("%d ",pop());
    return 0;
}