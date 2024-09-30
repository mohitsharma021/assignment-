#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct Node {
    int data;               // Data stored in the node
    struct Node* next;      // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the front of the linked list
void insertAtFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head; // Link new node to the previous head
    *head = newNode;       // Update head to the new node
    printf("%d inserted at the front.\n", data);
}

// Function to insert a node at the end of the linked list
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
    printf("%d inserted at the end.\n", data);
}

// Function to insert a node in ascending order
void insertInOrder(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL || (*head)->data >= data) {
        newNode->next = *head; // Insert at the front if empty or data is smaller
        *head = newNode;
        printf("%d inserted in order.\n", data);
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next; // Find the position to insert
    }
    newNode->next = current->next; // Link new node
    current->next = newNode; // Insert new node
    printf("%d inserted in order.\n", data);
}

// Function to delete the first node
void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head; // Store the current head
    *head = (*head)->next; // Move head to the next node
    free(temp); // Free the old head
    printf("First node deleted.\n");
}

// Function to delete a node before a specified position
void deleteBeforePosition(struct Node** head, int position) {
    if (*head == NULL || position <= 1) {
        printf("Invalid position.\n");
        return;
    }
    struct Node* current = *head;
    struct Node* prev = NULL;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        prev = current; // Keep track of the previous node
        current = current->next;
    }
    if (prev == NULL) {
        printf("No node to delete before the specified position.\n");
        return;
    }
    if (prev == *head) {
        // If the node to delete is the head
        deleteFirstNode(head);
    } else {
        struct Node* toDelete = prev->next; // Node to be deleted
        prev->next = toDelete->next; // Link previous to the next of toDelete
        free(toDelete); // Free the deleted node
        printf("Node before position %d deleted.\n", position);
    }
}

// Function to delete a node after a specified position
void deleteAfterPosition(struct Node** head, int position) {
    if (*head == NULL || position < 1) {
        printf("Invalid position.\n");
        return;
    }
    struct Node* current = *head;
    for (int i = 1; i < position && current != NULL; i++) {
        current = current->next; // Traverse to the specified position
    }
    if (current == NULL || current->next == NULL) {
        printf("No node to delete after position %d.\n", position);
        return;
    }
    struct Node* toDelete = current->next; // Node to be deleted
    current->next = toDelete->next; // Link to next of toDelete
    free(toDelete); // Free the deleted node
    printf("Node after position %d deleted.\n", position);
}

// Function to traverse the linked list
void traverseList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
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
        printf("3. Insert in ascending order\n");
        printf("4. Delete first node\n");
        printf("5. Delete before specified position\n");
        printf("6. Delete after specified position\n");
        printf("7. Traverse list\n");
        printf("8. Exit\n");
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
                printf("Enter value to insert in order: ");
                scanf("%d", &value);
                insertInOrder(&head, value); // Insert in order
                break;
            case 4:
                deleteFirstNode(&head); // Delete first node
                break;
            case 5:
                printf("Enter position before which to delete: ");
                scanf("%d", &position);
                deleteBeforePosition(&head, position); // Delete before position
                break;
            case 6:
                printf("Enter position after which to delete: ");
                scanf("%d", &position);
                deleteAfterPosition(&head, position); // Delete after position
                break;
            case 7:
                traverseList(head); // Traverse the list
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 8);

    // Free allocated memory (not implemented for simplicity)
    return 0;
}
