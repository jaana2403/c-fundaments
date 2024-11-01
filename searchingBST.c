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
void inorder(struct node * root){
     if(root!=NULL){
        inorder(root->lc);
        printf("%d\n",root->data);
        inorder(root->rc);
        
    }
}
//checking
int isBST(struct node *root){
    static struct node *prev =NULL;
    if(root!=NULL){
        if(!isBST(root->lc)){
            return 0;
        }
        if(prev!=NULL&& root->data <= prev->data){
            return 0;
        }
        prev=root;
        return isBST(root->rc);
    }
    else
    return 1;//empty tree ko bst maan sakte h 
}
struct node * search(struct node * root, int key){
   /* if(root==NULL)
    return NULL;
    else if(key==root->data)
    return root;
    else if(root->data > key)
    return search(root->lc,key);
    else
    return search(root->rc,key);
    */
   while(root!=NULL){
    if(key ==root->data)
    return root;
    else if(key<root->data)
    root=root->lc;
    else
    root=root->rc;
   }
   return NULL;//if root==NULL
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
//  inorder(p);
//  printf("%d",isBST(p));
    struct node * n=search(p,11);
    if(n!=NULL)
    printf("%d found",p->data);
    else
    printf("not found");

    return 0;
}