#include<stdio.h>
#include<stdlib.h>

typedef struct Node node;

struct Node {
    node* prev;
    int data;
    node* next;
};

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("\nMemory allocation failed!\n");
        return NULL;
    }
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

int getLength(node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void insertAtFront(node** head, int value) {
    node* newNode = createNode(value);

    if (*head != NULL) {
        newNode->next = *head;
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insertAtEnd(node** head, int value) {
    node* newNode = createNode(value);

    if(*head == NULL) {
        *head = newNode;
    } else {
        node* temp = *head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertAtPosition(node** head, int value, int position) {
    if (head == NULL || position == 1) {
        insertAtFront(head, value);
    } else if ((position <= 0) || (getLength(*head) < position)) {
        printf("Insertion at %d position is not possible\n", position);
    } else {
        node* newNode = createNode(value);
        node* temp = *head;
        for (int i = 1; i < position - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next->prev = newNode;
        newNode->prev = temp;
        temp->next = newNode;
    }
}

void deleteFromFront(node** head) {
    if (*head == NULL) {
        printf("\nList is already empty. Nothing to delete.\n");
    } else {
        node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
    }
}

void deleteAtEnd(node** head) {
    if (*head == NULL) {
        printf("\nList is already empty. Nothing to delete.\n");
    } else if ((*head)->next == NULL) {
        deleteFromFront(head);
    } else {
        node* temp = *head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void deleteAtPosition(node** head, int position) {
    if (*head == NULL) {
        printf("\nList is already empty. Nothing to delete.\n");
    } else if (position == 1) {
        deleteFromFront(head);
    } else if (position < 1 || position > getLength(*head)) {
        printf("\nPosition %d does not exist in the list.\n", position);
    } else {
        node* curr = *head;
        int currPosition = 1;
        while (curr != NULL && currPosition < position) {
            curr = curr->next;
            currPosition++;
        }

        if (curr->prev != NULL) {
            curr->prev->next = curr->next;
        }

        if (curr->next != NULL) {
            curr->next->prev = curr->prev;
        }
        free(curr);
    }
}

void reverseList(node** head) {
    if (*head != NULL && (*head)->next != NULL) {
        node* curr = *head;
        node* temp = NULL;

        // Swapping prev and next
        while (curr != NULL) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
        
            curr = curr->prev;
        }

        // Adjusting head
        if (temp != NULL) {
            *head = temp->prev;
        }
    }
}

void printList(node* head) {
    printf("\nList > \tNULL <-> ");
    while(head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n\n");
}

int main() {
    node* head = NULL;

    // insertAtFront(&head, 20);
    // insertAtFront(&head, 110);
    // insertAtFront(&head, 1);
    // insertAtFront(&head, 789);
    // insertAtFront(&head, 7);

    insertAtEnd(&head, 345);
    insertAtEnd(&head, 35);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 35);
    insertAtEnd(&head, 234);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 234);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 90);
    insertAtEnd(&head, 77);
    printList(head);
    
    // insertAtPosition(&head, 999, 1);
    // insertAtPosition(&head, 999, 12);

    // deleteFromFront(&head);
    // deleteFromFront(&head);
    // deleteFromFront(&head);
    // deleteAtEnd(&head);
    // deleteAtEnd(&head);
    // deleteAtEnd(&head);
    // deleteAtPosition(&head, 2);
    // printList(head);
    // deleteAtPosition(&head, -1);
    // deleteAtPosition(&head, 90);
    // deleteAtPosition(&head, 6);

    reverseList(&head);

    printList(head);
}