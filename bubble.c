#include <stdio.h>
void printarray(int *a,int n){
    for (int i = 0; i < n; i++)
    {
        /* code */
        printf("%d ",a[i]);
    }
    printf("\n");
    
}
void bubblesort(int *a,int n){
    int temp;
    int flag=0;
    for (int i = 0; i < n-1; i++)//no. of passes (n-1)
    {
        /* code */
        flag=1;
        for (int j = 0; j < n-i-1; j++)
        {
            /* code */
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=0;
            }
        }
        
    }
    if(flag)
    printf("comparision is done\n-adaptive algorithm");
    
}
int main()
{
    int a[]={12,15,8,7,99};
    int n=5;
    printarray(a,n);
    bubblesort(a,n);
    printarray(a,n);
    return 0;
}