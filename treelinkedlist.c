// tree repesentation using linked list
#include <stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *rc;
    struct node *lc;
};
struct node * createnode(int data){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->lc=NULL;
    newnode->rc=NULL;
    newnode->data=data;
    return newnode;
}
void preorder(struct node * root){
    if(root!=NULL){
        printf("%d\n",root->data);
        preorder(root->lc);
        preorder(root->rc);
    }
}
void postorder(struct node * root){
     if(root!=NULL){
        postorder(root->lc);
        postorder(root->rc);
        printf("%d\n",root->data);
    }
}
void inorder(struct node * root){
     if(root!=NULL){
        inorder(root->lc);
        printf("%d\n",root->data);
        inorder(root->rc);
        
    }
}
int main()

{/*
    //constructing the root node 
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->lc=NULL;
    p->rc=NULL;
    //constructing first node 
    struct node *p1;
    p1=(struct node *)malloc(sizeof(struct node));
    p1->lc=NULL;
    p1->rc=NULL;
    //constructing second node
    struct node *p2;
    p2=(struct node *)malloc(sizeof(struct node));
    p2->lc=NULL;
    p2->rc=NULL;
    //linking with root node;
    p->lc=p1;
    p->rc=p2;

    */
   //creating node using functions
  // struct node *p,*p1,*p2, *p3, *p4, *p5;
   struct node *p=createnode(10);
   struct node *p1=createnode(1);
   struct node *p2=createnode(9);
   struct node *p3=createnode(5);
   struct node *p4=createnode(11);
   struct node *p5=createnode(7);
    //linking with root node;
    p->lc=p1;
    p->rc=p2;
    p1->lc=p5;
    p2->lc=p4;
    p2->rc=p3;
 //   preorder(p);
// postorder(p);
 inorder(p);
    return 0;
}