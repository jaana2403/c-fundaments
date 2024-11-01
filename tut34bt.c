#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create(int x){
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    if(t==NULL){
        printf("memory allocation failed \n");
    }
    t->data=x;
    t->left=t->right=NULL;
    return t;
}
struct node *insertleft(struct node *root,int left){
    root->left=create(left);
    return root->left;
}
struct node *insertright(struct node *root, int right){
    root->right=create(right);
    return root->right;
}
int count(struct node *root){
    int x,y;
    if(root==NULL)
    return 0;
    else
    x=count(root->left);
    y=count(root->right);
    return x+y+1;
}
int height(struct node *root){
    int lefth, righth;
    if(root==NULL)
    return 0;
    else {
        lefth=height(root->left);
        righth=height(root->right);
        if(lefth>righth)
        return lefth +1;
        else 
        return righth+1;
    }
}
int leafnode(struct node *root){
    if(root=NULL){
        return 0;
    }
    else if(root->left==NULL && root->right==NULL)
    return 1;
    else{
        return leafnode(root->left)+ leafnode(root->right)+1;
    }
}
void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int main()
{
   struct node *root=NULL;
 root=create(45);
 insertleft(root,39);
 insertright(root,78);
 insertleft(root->right,54);
 insertright(root->right,79);
 insertright(root->right->left,55);
 insertright(root->right->right,80);
 printf("\n The tree(inorder) is\n");
 inorder(root);
 printf("\n");
 printf("\n The total number of nodes is %d\n",count(root));
 printf("\n The height of the tree is %d\n",height(root));
 printf("\n The total number of leaf nodes is %d\n",leafnode(root));
    return 0;
}