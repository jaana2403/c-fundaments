#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char data;
    struct node *next;
}*top=NULL;
void push(char x){
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL){
        printf("memory not allocated heap overflow \n");
    }
        else{
            t->data=x;
            t->next=top;
            top=t;
        }
    }

void display(){
    struct node *p;
    p=top;
    if(p==NULL)
    printf("stack is empty \n");
    else{
        while(top!=NULL){
            printf("%d ",p->data);
            p=p->next;
        }
        printf("%d ",p->data);
    }
}
int pop(){
    struct node *t;
    t=top;
    if(t==NULL){
        printf("stack is empty");
    }
    else{
        top=top->next;
        return t->data;
        free(t);
    }
}
int pre(char x){
    if(x=='+'||x=='-')
    return 1;
    else if (x=='*'||x=='/')
    {
        /* code */
        return 2;
    }
    else
    return 0;
}
int isoperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/')
    return 0;
    else
    return 1;
}

char *convert(char *infix){
    char *postfix=(char *)malloc((strlen(infix)+1)*sizeof(char));
    int i=0,j=0;
    while(infix[i]!='\0'){
        if(isoperand(infix[i]))
        postfix[j++]=infix[i++];
        else{
            if(pre(infix[i])>pre(top->data))//inital stack mepty ie push #
            push(infix[i++]);
            else{
                postfix[j++]=pop();
            }
        }
    }
    while(top!=NULL)
    postfix[j++]=pop();
    postfix[j]='\0';
    return postfix;
}
int main()
{
    char *infix="a+b+c*d/e*f";
    push(' ');
    char *postfix=convert(infix);
    printf("%s ",postfix);
    return 0;
}