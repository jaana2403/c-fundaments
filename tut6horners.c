// #include <stdio.h>
// double e(int x,int n){
//     static double s;
//     if(n==0)
//     return s;
//     s=1+x*s/n;
//     return e(x,n-1);
// }
// int main()
// {
//     printf("%lf ",e(1,10));
//     return 0;
// }

//*****iterative method*********
#include <stdio.h>
double e(int x,int n){
    double s=1;
    int i ;
    double num=1,den=1;
    for (int i = 1; i <= n; i++)
    {
        /* code */
        num*=x;
        den*=i;
        s+=num/den;
    }
    return s;
}
int main()
{
    printf("%lf ",e(1,10));
    return 0;
}