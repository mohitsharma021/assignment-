#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the binary tree
struct Node {
    int data;               // Data stored in the node
    struct Node* left;      // Pointer to the left child
    struct Node* right;     // Pointer to the right child
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;   // Assign data
    newNode->left = NULL;   // Initialize left child as NULL
    newNode->right = NULL;  // Initialize right child as NULL
    return newNode;
}

// Recursive In-Order Traversal
void recursiveInOrder(struct Node* root) {
    if (root != NULL) {
        recursiveInOrder(root->left);  // Traverse left subtree
        printf("%d ", root->data);      // Visit node
        recursiveInOrder(root->right); // Traverse right subtree
    }
}

// Non-Recursive In-Order Traversal
void nonRecursiveInOrder(struct Node* root) {
    struct Node* stack[100]; // Stack to store nodes
    int top = -1;            // Stack pointer
    struct Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current; // Push current node to stack
            current = current->left; // Move to left child
        }
        current = 
