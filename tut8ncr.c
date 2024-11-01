#include <stdio.h>
int fact(int n){
    if(n<=1){
        return 1;
    }
    else return n*fact(n-1);
}
int c(int n,int r){
    int a,b,c;
    a=fact(n);
    b=fact(r);
    c=fact(n-r);
    return a/(b*c);
}
int main()
{
    printf("%d ",c(5,3));
    return 0;
}