#include <stdio.h>
#include<stdlib.h>
struct node{
    struct node *left;
    struct node *right;
    int data;
};
struct node * create(int x){
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    if(t==NULL)
    printf("memory allocation failed ");
    t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    t->left=t->right=NULL;
    return t;
}
void preorder(struct node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
void inorder(struct node *root){
    if(root!=NULL){
        preorder(root->left);
        printf("%d ",root->data);
        preorder(root->right);
    }
}
struct node *insert(struct node *root,int item){
    struct node *t;
    t=create(item);
    if(root==NULL){
        return t;
    }
    else if(item < root->data)
    root->left=insert(root->left,item);
    else root->right=insert(root->right,item);
return root;
}
struct node * insuccessor(struct node *root){
    struct node *cur=root;
    while(cur->left!=NULL)
    cur=cur->left;
    return cur;
}
struct node * prece(struct node *root){
    struct node *pre=root;
    while(pre->right!=NULL)
    pre=pre->right;
    return pre;
}
struct node *delete(struct node *root){
    if(root==NULL)
    return NULL;
    else if( root->left==NULL && root->right==NULL)
    free(root);
}
int main()
{
    return 0;
}