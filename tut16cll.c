//madharchod output kyu nahi aa rha hai ????
// #include <stdio.h>
// #include<stdlib.h>
// struct node {
//     int data;
//     struct node *next;
// }*head;
// void create(int a[],int n){
//     int i;
//     struct node *t,*last;
//     head=(struct node*)malloc(sizeof(struct node));
//     head->data=a[0];
//     head->next=head;
//     last=head;
//     for (i = 1; i < n; i++)
//     {
//         /* code */
//         t=(struct node*)malloc(sizeof(struct node));
//         t->data=a[i];
//         t->next=last->next;
//         last=t;
//     }
// }

// void display(struct node *h){
//     do{
//         printf("%d ",h->data);
//         h=h->next;
//     }while(h!=head);
// }
// void rdisplay(struct node *h){
//     static int flag=0;
//     if(h!=head || flag==0){
//         flag=1;
//         printf("%d ",h->data);
//         rdisplay(h->next);
//     }
//     flag=0;
// }
// int main()
// {
//     int a[6]={2,1,4,5,6,7};
//     create(a,6);
//     display(head);
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*head;

void create(int a[], int n) {
    int i;
    struct node *t, *last;
    head = (struct node*)malloc(sizeof(struct node));
    head->data = a[0];
    head->next = head;
    last = head;
    for (i = 1; i < n; i++) {
        t = (struct node*)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = last->next;
        last = t;
    }
}

void display(struct node *h) {
    do {
        printf("%d ", h->data);
        h = h->next;
    } while (h != head);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    create(arr, n);
    printf("Circular Linked List: ");
    display(head);

    return 0;
}
