#include<stdio.h>
#include<stdlib.h>

typedef struct Node node;

struct Node {
    int data;
    node* left;
    node* right;
};

node* createNode(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(node** root, int data) {
    if(*root == NULL) {
        *root = createNode(data); 
    } else if (data < (*root)->data) {
        insert(&((*root)->left), data);
    } else if (data > (*root)->data) {
        insert(&((*root)->right), data);
    }
}

void preorder(node* root) {
    if (root != NULL) {
        printf("%d, ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node* root) {
    if (root != NULL) {
        preorder(root->left);
        printf("%d, ", root->data);
        preorder(root->right);
    }
}

void postorder(node* root) {
    if (root != NULL) {
        preorder(root->left);
        preorder(root->right);
        printf("%d, ", root->data);
    }
}

node* search(node* root, int value) {
    if (root == NULL || root->data == value) return root;
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int height(node* root) {
    if (root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void levelOrderTraversal(node* root) {
    if (root == NULL) return;

    node* queue[10];
    int f=0, r=0;

    queue[r++] = root;

    printf("\nLevel Order Traversal: ");
    while (f<r) {
        node* current = queue[f++];
        printf("%d, ", current->data);
        if (current->left != NULL) queue[r++] = current->left;
        if (current->right != NULL) queue[r++] = current->right;
    }
}

void deleteNode(node** root, int data) {
    if (*root == NULL) {
        printf("\nTree is empty!");
        return;
    }

    if (data < (*root)->data) {
        deleteNode(&(*root)->left, data);
    } else if (data > (*root)->data) {
        deleteNode(&(*root)->right, data);
    } else {
        if ((*root)->left == NULL) {
            node* temp = (*root)->right;
            free(*root);
            *root = temp;
        } else if ((*root)->right == NULL) {
            node* temp = (*root)->left;
            free(*root);
            *root = temp;
        } else {
            node* temp = (*root)->right;
            while(temp->left != NULL) {
                temp = temp->left;
            }
            (*root)->data = temp->data;
            deleteNode(&(*root)->right, temp->data);
        }
    }
}

void printTree(node* root, int space) {
    if (root == NULL) {
        return;
    }
    space += 4;
    printTree(root->right, space);
    for (int i = 4; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    printTree(root->left, space);
}

int main() {
    node* root = NULL;

    insert(&root, 8);
    insert(&root, 3);
    insert(&root, 10);
    insert(&root, 1);
    insert(&root, 6);
    insert(&root, 14);
    insert(&root, 4);
    insert(&root, 7);
    insert(&root, 13);
    insert(&root, 9);

    // printf("\nPreorder Traversal: ");
    // preorder(root);
    // printf("\nInorder Traversal: ");
    // inorder(root);
    // printf("\nPostorder Traversal: ");
    // postorder(root);

    // int data;
    // printf("\nEnter value to search: ");
    // scanf("%d", &data);

    // if (search(root, data) != NULL) {
    //     printf("\nKey %d exist in the tree.", data);
    // } else {
    //     printf("\nKey %d doesn't exist in the tree.", data);
    // }

    // printf("\nHeight of the tree is %d", height(root));

    // levelOrderTraversal(root);

    printTree(root, 0);

    deleteNode(&root, 3);

    printTree(root, 0);

    return 0;
}