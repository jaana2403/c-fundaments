//deletion in a Binary Search Tree
//Searching in a Binary Search Trees (Search Operation)
//binary search tree
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
void insert(struct node * root, int key){
    struct node * prev=NULL;
    while(root!=NULL){
        prev=root;
        if(key==root->data)
        return;
        else if(key<root->data){
            root=root->lc;
        }
        else
        root=root->rc;
    }
    struct node * new = createnode(key);
    if(key<prev->data){
        prev->lc=new;
    }
    else
    prev->rc=new;
}
void inorder(struct node * root){
    if(root!=NULL){
        inorder(root->lc);
        printf("%d ",root->data);
        inorder(root->rc);
    }
}
struct node * inorderpredecessor(struct node * root){
   //left sub tree ka right most child
    root=root->lc;
    while(root->rc!=NULL)
    root=root->rc;
    return root;
}
struct node * deletion(struct node * root, int key){
    struct node * ipre;
    if(root==NULL)
    return NULL;
    if(root->rc==NULL&& root->lc==NULL){
    free(root);
    return NULL;
    }
    //search for element to be delete 
    if(key< root->data)
    root->lc=deletion(root->lc,key);//
    else if(root->rc)
    root->rc=deletion(root->rc,key);
    //deletion strategy 
    else{
        ipre=inorderpredecessor(root);
        root->data=ipre->data;
        root->lc=deletion(root->lc,ipre->data);//leaf node ko delete krunga uski value copy krli h root data mei 
 //node ko deelte krne ke baad NULL fix krne ke liye root->lc ==nyll likhna padega
    }
    return root;
}
int main()
{
    struct node *p=createnode(10);
   struct node *p1=createnode(1);
   struct node *p2=createnode(12);
   struct node *p3=createnode(15);
   struct node *p4=createnode(11);
   struct node *p5=createnode(7);
    //linking with root node;
    p->lc=p1;
    p->rc=p2;
    p1->rc=p5;
    p2->lc=p4;
    p2->rc=p3;
    inorder(p);
    deletion(p,10);
    inorder(p);

    return 0;
}