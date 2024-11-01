#include <stdio.h>
void TOH(int n ,char A,char B ,char C){
    if(n>0){
        TOH(n-1,A,C,B);
        printf("from %c to %c \n", A,C);
        TOH(n-1,B,A,C);
    }
}
int main()
{
    TOH(4,'m','n','o');
    return 0;
}