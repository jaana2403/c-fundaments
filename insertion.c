#include <stdio.h>
void printarray(int *a,int n){
    for (int i = 0; i < n; i++)
    {
        /* code */
        printf("%d ",a[i]);
    }
    printf("\n");
    
}
void insertion(int *a,int n){
    //loop for passes
    int key,j;
    for (int i = 1; i <= n-1; i++)
    {
        key=a[i];
        j=i-1;
        /* loop for each pass */
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;   
    }
}
int main()
{
    int a[]={12,15,8,7,99};
    int n=5;
    printarray(a,n);
    insertion(a,n);
    printf("Ascending order - descending order a[j]<key \n");
    printarray(a,n);
    return 0;
}