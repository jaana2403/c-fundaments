#include <stdio.h>
void printarray(int *a,int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    
}
void selection(int *a,int n){
    int min;
    int temp;
    for (int i = 0; i < n-1; i++)
    {
        min=i;
        for (int j = i+1; j < n; j++)
        {
         if(a[j]<a[min]){
            min=j;
         }   

        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    
}
int main()
{
     int a[]={12,15,8,7,99};
     //after 1st pass -> 7 15 8 12 99
    int n=5;
    printarray(a,n);
    selection(a,n);
    printarray(a,n);
    return 0;
}