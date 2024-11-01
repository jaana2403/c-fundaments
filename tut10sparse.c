#include <stdio.h>
#include<stdlib.h>
struct element{
    int i ,j,x;
};
struct sparse{
    int m,n,num;
    struct element *e;
};
void create(struct sparse *s){
    printf("enter dimension \n");
    scanf("%d%d",&s->m,&s->n);// no. of rows and no. of columns of sparse matrix 
    printf("enter no. of non zero elements\n");
    scanf("%d",&s->num);
    //dynamically allocate memory to element array
    s->e=(struct element *)malloc(s->num*sizeof(struct element));
   printf("enter non zero elements \n");
    for (int i = 0; i < s->num; i++)
    {
        /* code */
        scanf("%d%d%d",&s->e[i].i,&s->e[i].j,&s->e[i].x);
    }
    
}
void dispaly(struct sparse s){
    int i,j,k=0;
    for(i=0;i<s.m;i++){
        for ( j = 0; j<s.n; j++)
        {
            /* code */
            if(i==s.e[k].i && j==s.e[k].j)
            printf("%d ",s.e[k++].x);//display non zero elements
            else printf("0 ");
        }
        printf("\n");
    }
}
struct sparse *add(struct sparse *s1,struct sparse *s2){
    struct sparse *sum;
    sum=(struct sparse *)malloc(sizeof(struct sparse));
    //this line will create array for sum matrix
    sum->e=(struct element *)malloc((s1->num+s2->num)*sizeof(struct element));
    int i=0,j=0,k=0;
    while(i<s1->num && j<s2->num){
        if(s1->e[i].i<s2->e[j].i)
        sum->e[k++]=s1->e[i++];
        else  if(s1->e[i].i>s2->e[j].i)
        sum->e[k++]=s2->e[j++];
        else{
             if(s1->e[i].j<s2->e[j].j)
        sum->e[k++]=s1->e[i++];
        else  if(s1->e[i].j>s2->e[j].j)
        sum->e[k++]=s2->e[j++];
        else{
        sum->e[k]=s1->e[i];
        sum->e[k++].x=s1->e[i++].x+s2->e[j++].x;
        }
        }

    }
    for(;i<s1->num;i++)sum->e[k++]=s1->e[i];
    for(;i<s2->num;j++)sum->e[k++]=s2->e[j];
    sum->m=s1->m;
    sum->n=s1->n;
    sum->num=k;
    return sum;
}
int main()
{
    struct sparse s1;
    create(&s1);
    dispaly(s1);
    struct sparse s2;
    create(&s2);
    dispaly(s2);
    struct sparse *sum ;
    sum=add(&s1,&s2);
    dispaly(*sum);
    return 0;
}