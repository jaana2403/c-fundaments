//static global variable
#include <stdio.h>
int fun(int n ){
    int static x=0;
    if(n>0){
        x++;
        return fun(n-1)+n;
    }
    return 0;
}
int main()
{
    int t;
    t=fun(5);
    printf("%d",t);
    return 0;
}