#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

struct Stack {
    int stack[MAX_SIZE];
    int top;
};

typedef struct Stack* stack;

stack initializeStack() {
    stack s = (stack)malloc(sizeof(struct Stack));
    s->top = 0;
    return s;
}

bool isEmpty(stack s) {
    return s->top == 0;
}

bool isFull(stack s) {
    return s->top == MAX_SIZE;
}

void push(stack s, int value) {
    if (isFull(s)) {
        printf("\nStack Overflow!");
    } else {
        s->stack[s->top++] = value;
        printf("\n%d pushed into the stack", value);
    }
}

void pop(stack s) {
    if (isEmpty(s)) {
        printf("\nStack Underflow!");
    } else {
        printf("\nPopped %d from stack", s->stack[--s->top]);
    }
}

int peek(stack s) {
    int value;
    if(isEmpty(s)) {
        value = 0;
        printf("\nStack Underflow!");
    } else {
        value = s->stack[s->top-1];
    }
    return value;
}

void display(stack s) {
    if (isEmpty(s)) {
        printf("\nStack Underflow!");
        return;
    } else {
        printf("\nStack Elements: ");
        for (int i = 0; i < s->top; i++) {
            printf("%d, ", s->stack[i]);
        }
        printf("\b\b \n");
    }
}

int main() {
    stack s = initializeStack();

    push(s, 12);
    push(s, 23);
    push(s, 1);
    push(s, 768);
    push(s, 8);
    push(s, 99);
    display(s);

    pop(s);
    pop(s);
    display(s);

    printf("\nPeek Top: %d", peek(s));

    printf("\nIs stack empty? -> ");
    printf(isEmpty(s) ? "Yes" : "No");
    printf("\nIs stack full? -> ");
    printf(isFull(s) ? "Yes" : "No");

    free(s);
    return 0;
}