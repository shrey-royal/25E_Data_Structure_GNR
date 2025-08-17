#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Queue queue;

struct Queue {
    int data[MAX_SIZE];
    int front;
    int rear;
};

void enqueue(queue* q, int value) {
    if (q->rear == MAX_SIZE - 1) printf("\nQueue is full, can't add %d", value);
    else {
        if (q->front == -1) q->front = 0;
        q->rear++;
        q->data[q->rear] = value;
    }
}

void dequeue(queue* q) {
    if (q->rear == -1) printf("\nQueue is empty!");
    else {
        printf("\nDequeued element: %d", q->data[q->front]);
        if (q->front == q->rear) q->front = q->rear = -1;
        else q->front++;
    }
}

int peekFront(queue* q) {
    if (q->front == -1) {
        printf("\nQueue is empty");
        return -1;
    } else {
        return q->data[q->front];
    }
}

int peekRear(queue* q) {
    if (q->rear == -1) {
        printf("\nQueue is empty");
        return -1;
    } else {
        return q->data[q->rear];
    }
}

void display(struct Queue *q) {
    if (q->rear == -1) printf("\nQueue is empty!");
    else {
        printf("\nQueue elements are: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d, ", q->data[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Queue q;
    q.front = q.rear = -1;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    enqueue(&q, 70);
    enqueue(&q, 80);
    enqueue(&q, 90);
    enqueue(&q, 200);
    dequeue(&q);
    enqueue(&q, 30);
    display(&q);

    printf("\npeekFront: %d", peekFront(&q));
    printf("\npeekRear: %d", peekRear(&q));

    return 0;
}