//BST (Binary Search Tree)

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert(struct Node **root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
    } else if (data < (*root)->data) {
        insert(&((*root)->left), data);
    } else {
        insert(&((*root)->right), data);
    }
}

void inorderTraversal(struct Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node *root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node *root = NULL;
    int n, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value to insert: ");
        scanf("%d", &data);
        insert(&root, data);
    }

    int choice;
    printf("Choose traversal method:\n1. Inorder\n2. Preorder\n3. Postorder\n");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        inorderTraversal(root);
        break;
    case 2:
        preorderTraversal(root);
        break;
    case 3:
        postorderTraversal(root);
        break;
    default:
        printf("Invalid choice\n");
        break;
    }
    printf("\n");

    return 0;
}