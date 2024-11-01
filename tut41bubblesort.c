#include <stdio.h>
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void bubblesort(int a[],int n){
    int i,j;
    int flag=0;
    for ( i = 0; i < n-1; i++)
    {
        /* code */
        
        for (j = 0; j < n-1-i; j++)
        {
            /* code */
            if(a[j]>a[j+1]){
                swap(&a[j],&a[j+1]);
                flag=1;
            }
        }
       
    } if(flag==1){
            printf("swapping didnot take place \n");
        }
    
}
void print(int a[],int n){
    for (int i = 0; i < n; i++)
    {
        /* code */
        printf("%d \n",a[i]);

    }
    
}
int main()
{
    int a[]={1,2,3,4,5,6,7,8,9};
    
    bubblesort(a,9);
    print(a,9);
    return 0;
}