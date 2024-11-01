#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *top = NULL;

void push(int x) {
    struct node *t;
    t = (struct node*)malloc(sizeof(struct node));
    if (t == NULL) {
        printf("Memory not allocated, heap overflow \n");
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop() {
    struct node *t;
    int popped_value;
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1; // Return -1 if stack is empty
    } else {
        t = top;
        top = top->next;
        popped_value = t->data;
        free(t); // Free memory after extracting data
        return popped_value;
    }
}

int isoperand(char x) {
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

int eval(char *infix) {
    int x1, x2, r, i;
    for (i = 0; infix[i] != '\0'; i++) {
        if (isoperand(infix[i]))
            push(infix[i] - '0');
        else {
            x2 = pop();
            x1 = pop();
            switch (infix[i]) {
                case '+':
                    r = x1 + x2;
                    break;
                case '-':
                    r = x1 - x2;
                    break;
                case '*':
                    r = x1 * x2;
                    break;
                case '/':
                    if (x2 == 0) {
                        printf("Error: Division by zero\n");
                        return -1;
                    }
                    r = x1 / x2;
                    break;
            }
            push(r);
        }
    }
    return pop();
}

int main() {
    printf("Enter a postfix expression: ");
    char in[100];
    scanf("%s", in);
    printf("Result: %d\n", eval(in));
    return 0;
}
