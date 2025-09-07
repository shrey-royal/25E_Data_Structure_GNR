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

void insertAtPosition(node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid Position.\n");
        return;
    }

    node* newNode = createNode(data);
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    node* temp = *head;
    for (int i = 1; i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position is out of bounds");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromBeginning(node** head) {
    if (*head == NULL) {
        printf("\nList is empty!");
    } else {
        node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void deleteFromEnd(node** head) {
    if (*head == NULL) {
        printf("\nList is empty!");
    } else if((*head)->next == NULL) {
        deleteFromBeginning(head);
    } else {
        node* temp = *head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

int getLength(node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void deleteAtPosition(node** head, int position) {
    int length = getLength(*head);

    if (*head == NULL) {
        printf("\nList is empty!");
    } else if (position < 1 || position > length) {
        printf("Invalid position!\n");
    } else if (position == 1) {
        deleteFromBeginning(head);
    } else {
        node* temp = *head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }
        node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        free(nodeToDelete);
    }
}

void reverseList(node** head) {
    node* curr = *head;
    node* prev = NULL;
    node* following = NULL;
    while(curr != NULL) {
        following = curr->next;
        curr->next = prev;
        prev = curr;
        curr = following;
    }
    *head = prev;
}

int searchByValue(node* head, int key) {
    while(head != NULL) {
        if (head->data == key) {
            return 1;
        }
        head = head->next;
    }
    return 0;
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
    
    // printList(head);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 40);
    insertAtBeginning(&head, 50);
    insertAtBeginning(&head, 60);
    printList(head);
    // insertAtEnd(&head, 99);
    // insertAtEnd(&head, 98);
    // insertAtEnd(&head, 97);
    // printList(head);
    // insertAtPosition(&head, 999, 1);
    // insertAtPosition(&head, 333, 2);
    // insertAtPosition(&head, 666, 3);
    // printList(head);

    // deleteFromBeginning(&head);
    // deleteFromEnd(&head);
    // printList(head);
    // printf("\nLength of the Linked List: %d", getLength(head));
    // reverseList(&head);
    // printList(head);

    if(searchByValue(head, 40) == 1) {
        printf("Key found!\n");
    } else {
        printf("Key not found!\n");
    }

    return 0;
}