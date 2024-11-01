#include <stdio.h>
void func1(int n){
    if(n>0){
        printf("%d",n);
        func1(n-1);
    }
}
void func2(int n){
    if(n>0){
        func2(n-1);
        printf("%d",n);
    }
}
int main()
{
    int x=3;
    func1(3);
    func2(3);
    return 0;
}