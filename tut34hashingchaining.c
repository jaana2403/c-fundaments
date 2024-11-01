#include <stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next
};
void sortinsert(struct node *t,int x){
    
}
int hash(int key){
    return key%10;
}
void insert(struct node *h[],int key){
    int index=hash(key);
    sortinsert(&h[index],key);
}
int main()
{
    struct node *h[10];
    struct node *t;
    int i;
    for ( i = 0; i < 10; i++)
    {
        /* code */
        h[i]=NULL;
    }
    insert(h,20);
    insert(h,42);
    insert(h,22);
    t=search(h[hash(22)],22);
    printf("%d ",t->data);
    return 0;
}