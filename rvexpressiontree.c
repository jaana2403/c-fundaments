//Program to Construct a binary tree for a given infix expression
//construct expression tree to perform traversal
#include <stdio.h>
#include<stdlib.h>

struct node {
    char info;
    struct node * left;
    struct node * right;
};
typedef struct node * NODE;
struct stack{
    int data;
    NODE data[10];
};
typedef struct stack STACK;
int preced(char item){
    switch (item)
    {
    case '^' /* constant-expression */:
        /* code */
        return 5;
        break;
    case '*':
    case '/': return 3;
    case '+':
    case '-': return 1;    
    default:
    exit(0);
        break;
    }
}
void preorder(NODE root){
    if(root!=NULL){
        printf("%c\t",root->info);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(NODE root){
    if(root!=NULL){
        inorder(root->left);
        printf("%c\t",root->info);
        inorder(root->right);
    }
}
void postorder(NODE root){
    if(root!=NULL){
        printf("%c\t",root->info);
        postorder(root->left);
        postorder(root->right);
    }
}
void push(STACK *s,temp){
    s->data[++(s->top)]=temp;
}
NODE pop(STACK * s){
    return s->data[(s->top)--];
}
NODE createnode(char item){
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    temp->info=item;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
NODE createExpTree(char expr[20]){//infix expression a+b-c*d/e
    STACK Tree,op;
    Tree.top=-1;
    op.top=-1;
    char symbol;
    int i ;
    NODE temp,t,l,r;
    for ( i = 0; infix[i]!= '\0'; i++)
    {
        symbol=infix[i];
        temp=createnode(symbol);
        if(isalnum(symbol)){
            push(&Tree,temp);
        }
        else{
            if(op.top==-1)//operator stack is empty
            push(&op,temp);
            else{
                while(op.top!=-1&&preced(op.data[op.top]->info)>=preced(symbol)){
                     t=pop(&op);
                     r=pop(&Tree);
                     l=pop(&Tree);
                     t->right=r;
                     t->left=l;
                     push(&Tree,t);
                }
                push(&op,temp);
            }
            while(op.top!=-1){
                t=pop(&op);
                     r=pop(&Tree);
                     l=pop(&Tree);
                     t->right=r;
                     t->left=l;
                     push(&Tree,t);
            }
return pop(&Tree);
        }
    }
}

int main()
{
    NODE root=NULL;
    char expr[20];
    scanf("%s",expr);
    root=createExpTree(expr);
    inorder(root);
    preorder(root);
    postorder(root);
    return 0;
}