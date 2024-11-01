#include <stdio.h>
#include<stdlib.h>
struct node {
    struct node *lc;
    int data;
    struct node *rc;
}*root=NULL;
void insert( int key){
    struct node *t=root;
    struct node *r,*p;
    if(root==NULL){
        p=(struct node*)malloc(sizeof(struct node));
        p->data=key;
        p->lc=p->rc=NULL;
        return;
    }
    while(t!=NULL){
        r=t;
    if(key< t->data){
        t=t->lc;
        else if(key> t->data)
        t=t->rc;
    else return;
    }
    p=(struct node*)malloc(sizeof(struct node));
        p->data=key;
        p->lc=p->rc=NULL;
    if(key<r->data)
    r->lc=p;
    else r->rc=p;
}}
void inorder(struct node *p){
    if(p){
        inorder(p->lc);
        printf("%d ",p->data);
        inorder(p->rc);
    }
}
int main()
{
   insert(5);
   insert(25);
   insert(9);
    insert(10);
    insert(20);
    insert(50);
    inorder(&root);
    return 0;
}