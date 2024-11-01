#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;
};
class linkedlist{
    private:
    node *first;
    public:
    linkedlist(){
        first=NULL;
    }
    linkedlist(int a[],int n);
    ~linkedlist();
    void display();
    void insert(int index ,int x);
    int del(int index);
    int length();
    bool detectloop();
    node *getHead();
    node *getTail();
};
node* linkedlist::getHead() {
    return first; // Return pointer to the head node
}

node* linkedlist::getTail() {
    node* tail = first;
    while (tail && tail->next) {
        tail = tail->next;
    }
    return tail; // Return pointer to the tail node
}

bool linkedlist::detectloop(){
    node *p,*q;
    p=q=first;
   while (p && q && q->next){
        p=p->next;
        q=q->next->next;
}
    if(p==q)
    return true;
    return false;
    
}
linkedlist::linkedlist(int a[],int n){
    node *last, *t;
    int i=0;
    first=new node;
    first->data=a[0];
    first->next=NULL;
    last=first;
    for ( i = 1; i < n; i++)
    {
        /* code */
        t=new node;
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    
}
linkedlist::~linkedlist(){
    node *p=first;
    while(first){
        first=first->next;
        delete p;
        p=first;
    }
}
void linkedlist::insert(int index,int x){
    node *t,*p;
    p=first;
    t=new node;
    t->data=x;
    if(index<0|| index>length()){
        cout<<"enter valid position\n";
        return;
    }
    else if (first==NULL)
    {
        /* code */
        first=t;
    }
    else if (index==0)
    {
        /* code */
        t->next=first;
        first=t;
    }
    else{
        for (int i = 0; i < index-1; i++)
        {
            /* code */
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
        
    }
}
void linkedlist::display(){
    node *p;
    p=first;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
}
int linkedlist::length(){
    int c=0;
    node *p;
    p=first;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}
int linkedlist::del(int index){
    int x;
    node *p=first;
    node *q=NULL;
    if(index==1){
        first=first->next;
        x=p->data;
        delete p;
    }
    else{
        for (int i = 0; i < index-1; i++)
        {
            /* code */
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
    }
    return x;
}
int main(){
    int a[]={10,20,30,40,50};
    linkedlist l(a,5);
   l.getTail()->next=l.getHead()->next;
    if(l.detectloop()){
        cout<<"loop detected in the linked lsit \n";
    }
    else{
        cout<<"no loop is detected \n";
    }
    l.display();
return 0;
}