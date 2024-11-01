#include <stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
}*first;
int count(struct node *p){
    int r=0;
    while(p!=NULL){
        r++;
        p=p->next;
    }
    return r;
}
void display(struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}
void insert(struct node *p,int pos,int key){
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=key;
    if(pos<0||pos>count(p))
    printf("enter valid position");
    else {
        if(pos==0){
            t->next=first;
            first=t;
        }
        else{
            for (int i = 0; i < pos-1; i++)
            {
                p=p->next;
                t->next=p->next;
                p->next=t;
            }
            
        }
    }
} 
int main()
{
    insert(first,0,10);
    insert(first,1,20);
    display(first);
    return 0;
}