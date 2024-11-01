#include <stdio.h>
void insert(int a[],int n){
    int i=n,temp;
    temp=a[i];
    while(i>1 && temp>a[i/2]){
        a[i]=a[i/2];
        i=i/2;
    }
    a[i]=temp;
}
int delete(int a[],int n){
    int temp;
    int i,j,x;
    int val=a[1];
    x=a[n];
    a[1]=a[n];
    a[n]=val;//stroing deleted element to last space to get sorted element 
    i=1;
    j=i*2;
    while(j<n-1){
        if(a[j+1]>a[j])
        j=j+1;
        if(a[i]<a[j]){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i=j;
            j=2*j;
        }
        else
        break;
    }
    return val;
}
int main()
{
    int h[]={0,5,7,8,9,4,1,18};
// insert(h,2);
// insert(h,3);
// insert(h,4);
// insert(h,5);
// insert(h,6);
// insert(h,7);
for (int i = 2; i <= 7; i++)
{
    /* code */
    insert(h,i);
}
//this is heap sort 
// printf("%d delete value \n",delete(h,7));
// printf("%d delete value \n",delete(h,6));
// printf("%d delete value \n",delete(h,5));
// printf("%d delete value \n",delete(h,4));
// printf("%d delete value \n",delete(h,3));
// printf("%d delete value \n",delete(h,2));
// printf("%d delete value \n",delete(h,1));
for (int i = 7; i >1; i--)
{
    /* code */
    delete(h,i);
    
}

for (int i = 1; i <= 7; i++)
{
    /* code */
    printf("%d ",h[i]);
}

    return 0;
}