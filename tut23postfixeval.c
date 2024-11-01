#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*top=NULL;
void push(int x){
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
int isoperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/')
    return 0;
    else
    return 1;
}
int eval(char *infix){
    int x1,x2,r,i;
    for ( i = 0; infix[i]!='\0' ; i++)
    {
        /* code */
        if(isoperand(infix[i]))
        push(infix[i]-'0');
        else{
            x2=pop();
            x1=pop();
            switch (infix[i])
            {
            case '+':
            r=x1+x2;
            push(r);
                break;
            case '-':
            r=x1-x2;
            push(r);
                break;
            case '*':
            r=x1*x2;
            push(r);
                break;
            case '/':
            r=x1/x2;
            push(r);
                break;
            }
        }
    }
    return pop();
}
int main()
{
     printf("enter a postfix ");
     int in[100];
    scanf("%s",in);
    printf("%d ",eval(in));
    return 0;
}