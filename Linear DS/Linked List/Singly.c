#include <stdio.h>
#include<stdlib.h>

typedef struct Node node;

struct Node {
    int data;
    node* next;
};

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("\nMemory allocation failed!");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertAtBeginning(node** head, int data) {
    node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(node** head, int data) {
    node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        node* temp = *head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(node* head) {
    printf("\nList: ==> ");
    while (head != NULL) {
        // printf("(%p, %d, %p)\n", head, head->data, head->next);
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    node* head = NULL;
    
    printList(head);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 40);
    insertAtBeginning(&head, 50);
    insertAtBeginning(&head, 60);
    printList(head);
    insertAtEnd(&head, 99);
    insertAtEnd(&head, 98);
    insertAtEnd(&head, 97);
    printList(head);

    return 0;
}