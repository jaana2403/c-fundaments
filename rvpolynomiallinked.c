//Polynomial Multiplication using Singly Linked List
#include <stdio.h>
#include<stdlib.h>

struct node
{
    int coe,pow;
    struct node * add;
};
typedef struct node * NODE;
NODE insertend(NODE start,int coe,int pow ){
    NODE temp,cur;
    temp=(NODE)malloc(sizeof(struct node));
    temp->coe=coe;
    temp->pow=pow;
    temp->add=NULL;
    if(start==NULL){
        return temp;
    }
    cur=start;
    while(cur->add!=NULL)
    cur=cur->add;
    cur->add=temp;
    return start;
}
void display(NODE start){
    NODE temp;
    if(start==NULL)
    printf("empty");
    else{
        temp=start;
        while(temp->add!=NULL){
            printf("%d*x^%d + ",temp->coe,temp->pow);
            temp=temp->add;
        }
        printf("%d*x^%d ",temp->coe,temp->pow);
    }
}

NODE additem(NODE res,int coe,int pow){
    NODE temp,cur,start;
    int flag=0;
    temp=(NODE)malloc(sizeof(struct node));
    temp->coe=coe;
    temp->pow=pow;
    temp->add=NULL;
    if(res==NULL){
        return temp;
    }
    cur=res;
    while(cur!=NULL){
        if(cur->pow==pow){
            cur->coe=cur->coe+coe;
            flag=1;
        }
        cur=cur->add;
    }
    if(flag==0){
        cur=start;
        while(cur!=NULL)
        cur=cur->add;
        cur->add=temp;
    }
    return res;
}
NODE multipoly(NODE poly1,NODE poly2){
    NODE first, second,res=NULL;
    for(first=poly1;first!=NULL;first=first->add){
        for (second = poly2; second != NULL; second=second->add)
        {
            /* code */
            res=additem(res,first->coe*second->coe,first->pow+second->pow);
        }
        
        
    }
    return res;
}
int main()
{
    NODE poly1=NULL, poly2=NULL,res;
    int i ,n,coe,pow;
    printf("read no. of term\n");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        /* code */
        printf("Eter power and coefficients");
        scanf("%d %d",&coe,&pow);
        poly1=insertend(poly1,coe,pow);
    }
    printf("first poly ");
    display(poly1);
    printf("read no. of term\n");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        /* code */
        printf("Eter power and coefficients");
        scanf("%d %d",&coe,&pow);
        poly1=insertend(poly2,coe,pow);
    }
    printf("second poly ");
    display(poly2);
    res=multipoly(poly1,poly2);
    display(res);
    return 0;
}