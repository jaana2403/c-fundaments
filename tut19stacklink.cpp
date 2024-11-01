#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
}; 
class stack{
    private:
    node *top;
    public:
    stack(){top=NULL;}
    void push(int x);
    int pop();
    void display();
};
void stack::push(int x){
    node *t=new node;
    if(t==NULL)
    cout<<"stack is full \n";
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}
int stack::pop(){
    if(top==NULL)
    cout<<"stack is empty";
    else{
        node *t;
        t=top;
        top=top->next;
        return t->data;
        delete t;
    }
}
int main(){
    stack st;
    st.push(10);
    int x=st.pop();
    cout<<" "<<x;
return 0;
}