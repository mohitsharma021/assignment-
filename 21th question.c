#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in AVL Tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

// Function to get the height of the node
int height(struct Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// Function to get maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Right Rotate
struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *
