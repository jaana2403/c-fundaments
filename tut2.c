//Coding Insertion Operation in Array in Data Structures in C language
#include <stdio.h>
void display(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",arr[i]);
    }
}
void insertion(int arr[],int element , int index,int cap,int size){
    if(index>=cap){
        printf("no insertion");
    }
    else{
        for (int i = size-1; i >=index ; i--)
        {
            /* code */
            arr[i+1]=arr[i];
        }
        arr[index]=element;
    }
}
int main()
{
    int arr[100]={1,2,3,78};
    int size=4;
    display(arr,size);
    int ele=45;
    int index=1;
    printf("insertion to be done\n");
    insertion(arr,ele,index,100,size);
    size+=1;
    display(arr,size);
    return 0;
}