#include <stdio.h>
#include<stdlib.h>
struct node {
    struct node *lc;
    int data;
    struct node *rc;
}*root=NULL;
struct node *rinsert(struct node *p,int key){
    struct node *t= NULL;
    if(p==NULL){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=key;
        t->lc=t->rc=NULL;
        return t;
    }
    if(key < p->data){
        p->lc=rinsert(p->lc,key);
    }
    else if(key > p->data)
    p->rc=rinsert(p->rc,key);
    return p;
}
void inorder(struct node *p){
    if(p){
        inorder(p->lc);
        printf("%d ",p->data);
        inorder(p->rc);
    }
}
int height(struct node *q){
    int x,y;
    if(q==NULL)
    return 0;
    x=height(q->lc);
    y=height(q->rc);
    return x>y?x+1:y+1;
}
struct node * inpre(struct node *p){
    while(p &&p->rc!=NULL)
    p=p->rc;
    return p;
}
struct node * insucc(struct node *p){
    while(p &&p->lc!=NULL)
    p=p->lc;
    return p;
}
struct node *delete(struct node *p,int key){
    struct node *q;
    if(p==NULL){
    return NULL;
    if(p->lc==NULL && p->rc==NULL)
    if(p==root)
    root==NULL;   
    free (p);
    return NULL;
    }
    if(key < p->data)
    p->lc=delete(p->lc,key);
    else if(key > p->data)
    p->rc=delete(p->rc,key);
    else {
        if (height(p->lc)>height(p->rc)){
            q=inpre(p->lc);
            p->data=q->data;
            p->lc=delete(p->lc,q->data);
        }
        else {
            q=insucc(p->lc);
            p->data=q->data;
            p->rc=delete(p->rc,q->data);
        }

    }
}
int main()
{
    struct node *root;
    root=rinsert(root,10);
    rinsert(root,15);
    rinsert(root,25);
    rinsert(root,90);
    rinsert(root,66);
    inorder(root);
    return 0;
}