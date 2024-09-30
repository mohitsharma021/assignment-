#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the doubly linked list
struct Node {
    int data;               // Data stored in the node
    struct Node* next;      // Pointer to the next node
    struct Node* prev;      // Pointer to the previous node
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the front of the doubly linked list
void insertAtFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head != NULL) {
        newNode->next = *head; // Link new node to the current head
        (*head)->prev = newNode; // Update the previous head's previous pointer
    }
    *head = newNode; // Update head to the new node
    printf("%d inserted at the front.\n", data);
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode; // If list is empty, new node is the head
        printf("%d inserted at the end.\n", data);
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next; // Traverse to the last node
    }
    temp->next = newNode; // Link new node at the end
    newNode->prev = temp; // Update the new node's previous pointer
    printf("%d inserted at the end.\n", data);
}

// Function to delete the last node of the doubly linked list
void deleteLastNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next; // Traverse to the last node
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL; // Unlink the last node
    } else {
        // If the list only has one node
        *head = NULL;
    }
    free(temp); // Free the deleted node
    printf("Last node deleted.\n");
}

// Function to delete a node before a specified position
void deleteBeforePosition(struct Node** head, int position) {
    if (*head == NULL || position <= 1) {
        printf("Invalid position.\n");
        return;
    }
    struct Node* current = *head;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next; // Find the node before the specified position
    }
    if (current == NULL || current->prev == NULL) {
        printf("No node to delete before position %d.\n", position);
        return;
    }
    struct Node* toDelete = current->prev; // Node to be deleted
    if (toDelete == *head) {
        // If the node to delete is the head
        *head = current; // Move head to the current node
        current->prev = NULL; // Update previous pointer of new head
    } else {
        current->prev = toDelete->prev; // Link current's prev to toDelete's prev
    }
    if (toDelete->prev != NULL) {
        toDelete->prev->next = current; // Link previous node to current
    }
    free(toDelete); // Free the deleted node
    printf("Node before position %d deleted.\n", position);
}

// Function to traverse the doubly linked list
void traverseList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    printf("Doubly Linked List: ");
    while (current != NULL) {
        printf("%d <-> ", current->data); // Print the data
        current = current->next; // Move to the next node
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL; // Initialize the head of the list
    int choice, value, position;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Delete last node\n");
        printf("4. Delete node before specified position\n");
        printf("5. Traverse list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // User input for choice

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertAtFront(&head, value); // Insert at front
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value); // Insert at end
                break;
            case 3:
                deleteLastNode(&head); // Delete last node
                break;
            case 4:
                printf("Enter position before which to delete: ");
                scanf("%d", &position);
                deleteBeforePosition(&head, position); // Delete before position
                break;
            case 5:
                traverseList(head); // Traverse the list
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    // Free allocated memory (not implemented for simplicity)
    return 0;
}
