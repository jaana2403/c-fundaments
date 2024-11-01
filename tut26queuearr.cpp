#include<iostream>
using namespace std;
class queue{
    private:
    int front;
    int rear;
    int size;
    int *Q;
    public:
    queue(){
        front=rear=-1;
        size=5;
        Q=new int[size];
    }
    void enqueue(int x);
    int dequeue();
    void display();
};
void queue::enqueue(int x){
    if(rear==size-1)
    printf("queue is full");
    else{
        rear++;
        Q[rear]=x;
    }
}
int queue::dequeue(){
    int x=0;
    if(front==rear)
    printf("queue is empty ");
    else{
        front++;
        x=Q[front];
    }
    return x;
}
int main(){
    queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    printf("%d ",q.dequeue());
    printf("%d ",q.dequeue());
    printf("%d ",q.dequeue());
    printf("%d ",q.dequeue());
    printf("%d ",q.dequeue());
    printf("%d ",q.dequeue());
    q.enqueue(100);
    printf("%d ",q.dequeue());//cannot add this to queue
return 0;
}