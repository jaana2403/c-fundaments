#include <stdio.h>
#include<stdlib.h>
struct node{
   char data;
    struct node *next;
}*top=NULL;
void push(char x){
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
    else{
        do{
            printf("%d ",p->data);
            p=p->next;
        }while(p->next!=NULL);
        printf("%d ",p->data);
    }
}
char pop(){
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
int isbalance(char *exp){
    for (int i = 0; exp[i]!= '\0'; i++)
    {
        /* code */
        if(exp[i]=='('){
            push(exp[i]);
        }
        else if(exp[i]==')'){
            if(top==NULL)
            return 0;
            pop();
        }
    }
    if(top==NULL)
    return 1;
    else
    return 0;
    
}
int main()
{
    char *exp="((a+b)*(c/d)))";
    printf("%d ",isbalance(exp));
    return 0;
}