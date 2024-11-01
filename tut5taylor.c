// #include <stdio.h>********factorial*******
// int fact(int n ){
//     if(n==0)
//     return 1;
//     return fact(n-1)*n;//infinite calling terminates because of stack overflow
// }
// int main()
// {
//     int r;
//     r=fact(-5);
//     printf("%d",r);
//     return 0;
// }
//*****power function******
// #include <stdio.h>

// int pow1(int m,int n){
//     if(n==0)
//     return 1;
//     return pow1(m,n-1)*m;
// }
// int pow2(int m, int n){
//     if(n==0){
//         return 1;
//     }
//     if(n%2==0)
//     return pow2(m*m,n/2);
//     return m*pow2(m*m,(n-1)/2);
// }
// int main()
// {
//     int r= pow1(2,9);
//     printf("%d",r);
//     return 0;
// }
//***********taylor series ***********
#include <stdio.h>
double e(int x,int n){
    static double p=1,f=1;
    double r;
    if(n==0)
    return 1;
    r=e(x,n-1);
    p=p*x;
    f=f*n;
    return r+p/f;
}
int main()
{
    printf("%lf ",e(1,10));//e^x

    return 0;
}