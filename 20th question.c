#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the binary search tree
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

// Function to insert a node in the binary search tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data); // If tree is empty, return a new node
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data); // Insert in left subtree
    } else {
        root->right = insertNode(root->right, data); // Insert in right subtree
    }
    return root;
}

// In-Order Traversal
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);  // Traverse left subtree
        printf("%d ", root->data);      // Visit node
        inOrderTraversal(root->right); // Traverse right subtree
    }
}

// Pre-Order Traversal
void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);      // Visit node
        preOrderTraversal(root->left);  // Traverse left subtree
        preOrderTraversal(root->right); // Traverse right subtree
    }
}

// Post-Order Traversal
void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);   // Traverse left subtree
        postOrderTraversal(root->right);  // Traverse right subtree
        printf("%d ", root->data);         // Visit node
    }
}

// Main function
int main() {
    struct Node* root = NULL; // Initialize the root of the BST
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert node\n");
        printf("2. In-Order Traversal\n");
        printf("3. Pre-Order Traversal\n");
        printf("4. Post-Order Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // User input for choice

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value); // Insert the node
                printf("%d inserted.\n", value);
                break;
            case 2:
                printf("In-Order Traversal: ");
                inOrderTraversal(root); // Perform in-order traversal
                printf("\n");
                break;
            case 3:
                printf("Pre-Order Traversal: ");
                preOrderTraversal(root); // Perform pre-order traversal
                printf("\n");
                break;
            case 4:
                printf("Post-Order Traversal: ");
                postOrderTraversal(root); // Perform post-order traversal
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    // Free allocated memory (not implemented for simplicity)
    return 0;
}
