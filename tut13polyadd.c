// #include <stdio.h>
// #include<stdlib.h>
// struct term{
//     int coeff;
//     int expo;
// };
// struct poly{
//     int n;
//     struct term *t;
// };
// void create(struct poly *p){
//     printf("enter no. of non zero terms \n");
//     scanf("%d",&p->n);
//     p->t=(struct term *)malloc(p->n*sizeof(struct term));
//     for (int i = 0; i < p->n; i++)
//     {
//         /* code */
//         scanf("%d%d",&p->t[i].coeff,&p->t[i].expo);
//     }
// }
// void display(struct poly *p){
//     int s=0;
//     for (int i = 0; i < p->n; i++)
//     {
//         printf("%dx^%d+",p->t[i].coeff,p->t[i].expo);
//     }
    
// }
// struct poly *add(struct poly *p1,struct poly *p2){
//     int i=0 , j=0,k=0;
//     struct poly *sum;
//     sum=(struct poly *)malloc(sizeof(struct poly));
//     sum->t=(struct term *)malloc((p1->n+p2->n)*sizeof(struct term));
//     while(i<p1->n && j<p2->n){
//         if(p1->t[i].expo > p2->t[j].expo){
//             sum->t[k++]=p1->t[i++];
//         }
//         else if(p1->t[i].expo < p2->t[j].expo){
//             sum->t[k++]=p1->t[j++];
//         } 
//         else{
//             sum->t[k].expo=p1->t[i].expo;
//             sum->t[k++].coeff=p1->t[i++].coeff+p2->t[j++].coeff;

//     }

// }
// for(;i<p1->n;i++)sum->t[k++]=p1->t[i];
// for(;j<p2->n;j++)sum->t[k++]=p2->t[j];
// sum->n=k;
// return sum;
// }
// int main()
// {
//     struct poly p1,p2,*p3;
//     create(&p1);
//     display(&p1);
//     create(&p2);
//     display(&p2);
//     p3=add(p1,p2);
//     display(p3);
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

struct term {
    int coeff;
    int expo;
};

struct poly {
    int n;
    struct term *t;
};

void create(struct poly *p) {
    printf("Enter number of non-zero terms: ");
    scanf("%d", &p->n);
    p->t = (struct term *)malloc(p->n * sizeof(struct term));
    for (int i = 0; i < p->n; i++) {
        scanf("%d%d", &p->t[i].coeff, &p->t[i].expo);
    }
}

void display(struct poly *p) {
    for (int i = 0; i < p->n; i++) {
        printf("%dx^%d + ", p->t[i].coeff, p->t[i].expo);
    }
    printf("\n");
}

struct poly *add(struct poly *p1, struct poly *p2) {
    int i = 0, j = 0, k = 0;
    struct poly *sum;
    sum = (struct poly *)malloc(sizeof(struct poly));
    sum->t = (struct term *)malloc((p1->n + p2->n) * sizeof(struct term));

    while (i < p1->n && j < p2->n) {
        if (p1->t[i].expo > p2->t[j].expo) {
            sum->t[k++] = p1->t[i++];
        } else if (p1->t[i].expo < p2->t[j].expo) {
            sum->t[k++] = p2->t[j++];
        } else {
            sum->t[k].expo = p1->t[i].expo;
            sum->t[k++].coeff = p1->t[i++].coeff + p2->t[j++].coeff;
        }
    }

    for (; i < p1->n; i++) {
        sum->t[k++] = p1->t[i];
    }
    for (; j < p2->n; j++) {
        sum->t[k++] = p2->t[j];
    }

    sum->n = k;
    return sum;
}

int main() {
    struct poly p1, p2, *p3;
    create(&p1);
    printf("Polynomial 1: ");
    display(&p1);
    create(&p2);
    printf("Polynomial 2: ");
    display(&p2);
    p3 = add(&p1, &p2);
    printf("Sum of Polynomials: ");
    display(p3);
    return 0;
}
