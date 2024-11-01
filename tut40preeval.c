// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define n 20
#include<ctype.h>
struct stack{
    int top;
    float data[n];
};
void push(struct stack *s,float item){
    s->data[++s->top]=item;
}
float pop(struct stack *s){
    float pop;
    pop=s->data[s->top--];
    return pop;
}
float operate(char symbol , float op1, float op2){
    switch (symbol){
        case '+': return op1+op2;
        case '-': return op1-op2;
        case '*': return op1*op2;
        case '/': return op1/op2;
        case '^': return pow(op1,op2);
    }
}
// int isdigit(char x){
//     if(x=='+'||x=='-'||x=='*'||x=='/')
//     return 0;
//     else
//     return 1;
// }
float eval(char *prefix){
    struct stack s;
    s.top=-1;
    char symbol;
    float res ;
    float op1,op2;
    for(int i=strlen(prefix)-1;i>=0;i--){
        symbol=prefix[i];
        if(isdigit(symbol)){
            push(&s,(float)(symbol-'0'));
        }
        else {
            op1=pop(&s);
            op2=pop(&s);
            res=operate(symbol,op1,op2);
            push(&s,res);
    }
    
}return pop(&s);
}
int main(){
    char *prefix="*/+8791";
    printf("%f ",eval(prefix));
    return 0;
    
}