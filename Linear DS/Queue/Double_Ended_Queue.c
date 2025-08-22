#include <stdio.h>
#include<stdlib.h>

#define SIZE 10

typedef struct Deque deque;

struct Deque {
    int items[SIZE];
    int front;
    int rear;
};

void initialize(deque *dq) {
    for (int i = 0; i < SIZE; i++) {
        dq->items[i] = 0;
    }
    
    dq->front = -1;
    dq->rear = -1;
}

int isFull(deque *dq) {
    return ((dq->front == 0 && dq->rear == SIZE - 1) || (dq->front == dq->rear + 1));
}

int isEmpty(deque *dq) {
    return (dq->front == -1);
}

void enqueFront(deque *dq, int value) {
    if (isFull(dq)) {
        printf("\nDequeue is full!");
    } else {
        if (isEmpty(dq)) {
            dq->front = dq->rear = 0;
        } else if (dq->front == 0) {
            dq->front = SIZE - 1;
        } else {
            dq->front--;
        }
        dq->items[dq->front] = value;
    }
    // printf("\n(%d, %d) -> %d", dq->front, dq->rear, value);
}

void enqueRear(deque *dq, int value) {
    if (isFull(dq)) {
        printf("\nDequeue is full!");
    } else {
        if (isEmpty(dq)) {
            dq->front = dq->rear = 0;
        } else if (dq->rear == SIZE - 1) {
            dq->rear = 0;
        } else {
            dq->rear++;
        }
        dq->items[dq->rear] = value;
    }
    // printf("\n(%d, %d) -> %d", dq->front, dq->rear, value);
}

void display(deque *dq) {
    if(isEmpty(dq)) {
        printf("\nDeque is Empty!");
    } else {
        printf("\nDeque elements are: ");
        int i = dq->front;
        while(1) {
            printf("%d, ", dq->items[i]);
            if (i == dq->rear) break;
            i = (i+1) % SIZE;
        }
    }
}

// DEQUEUE
int main() {
    deque dq;
    initialize(&dq);

    display(&dq);

    enqueRear(&dq, 10);
    enqueRear(&dq, 20);
    enqueRear(&dq, 30);
    enqueRear(&dq, 40);
    enqueRear(&dq, 50);
    display(&dq);

    enqueFront(&dq, 99);
    enqueFront(&dq, 98);
    enqueFront(&dq, 97);
    display(&dq);

    return 0;
}