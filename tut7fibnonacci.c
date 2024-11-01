// #include <stdio.h>
// int fib(int n ){
//     if(n<=1)
//     return n;
//     else
//     return fib(n-2)+fib(n-1);
// }
// int main()
// {
//     printf("%d",fib(6));
//     return 0;
// }
//******iterative method******
// #include <stdio.h>
// int fib(int n ){
//     int t0=0,t1=1,s,i;
//     if(n<=1)return n;
//     for(i=2;i<=n;i++){
//         s=t0+t1;
//         t0=t1;
//         t1=s;
//     }
//     return s; }
// int main()
// {
//     printf("%d",fib(6));
//     return 0;
// }
//memorization more efficent code for recursive code 
#include <stdio.h>
int F[10];
int fib(int n ){
    if(n<=1){
        F[n]=n;
    return n;}
    else{
        if(F[n-2]==-1){
            F[n-2]=fib(n-2);
        }
        if(F[n-1]==-1){
            F[n-1]=fib(n-1);
        }
        return F[n-2]+F[n-1];
    }
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        /* code */
        F[i]=-1;
    }
    
    printf("%d",fib(6));
    return 0;
}