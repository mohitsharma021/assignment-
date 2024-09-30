#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the circular linked list
struct Node {
    int data;               // Data stored in the node
    struct Node* next;      // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode; // Point to itself to make it circular
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode; // If list is empty, new node is the head
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next; // Traverse to the last node
        }
        temp->next = newNode; // Link the last node to the new node
    }
    newNode->next = *head; // Complete the circular link
    printf("%d inserted at the end.\n", data);
}

// Function to insert a node before a specified position
void insertBeforePosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    if (position <= 1) {
        // Insert at the front if position is 1 or less
        newNode->next = *head;

        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next; // Find the last node
        }
        temp->next = newNode; // Link last node to new node
        *head = newNode; // Update head to the new node
        printf("%d inserted before position %d.\n", data, position);
        return;
    }

    struct Node* current = *head;
    for (int i = 1; i < position - 1 && current->next != *head; i++) {
        current = current->next; // Find the node before the specified position
    }
    newNode->next = current->next; // Link new node to the next node
    current->next = newNode; // Link the current node to the new node
    printf("%d inserted before position %d.\n", data, position);
}

// Function to delete the first node
void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = *head;
    if (temp->next == *head) {
        // Only one node in the list
        free(temp);
        *head = NULL;
    } else {
        // More than one node
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next; // Find the last node
        }
        last->next = temp->next; // Link last node to the second node
        *head = temp->next; // Update head to the second node
        free(temp); // Free the old head
    }
    printf("First node deleted.\n");
}

// Function to delete a node after a specified position
void deleteAfterPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* current = *head;
    for (int i = 1; i < position && current->next != *head; i++) {
        current = current->next; // Traverse to the specified position
    }
    
    if (current->next == *head) {
        printf("No node to delete after position %d.\n", position);
        return;
    }
    
    struct Node* toDelete = current->next; // Node to be deleted
    current->next = toDelete->next; // Bypass the node to be deleted
    free(toDelete); // Free the deleted node
    printf("Node after position %d deleted.\n", position);
}

// Function to traverse the circular linked list
void traverseList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* current = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", current->data); // Print the data
        current = current->next; // Move to the next node
    } while (current != head);
    printf("(head)\n");
}

// Main function
int main() {
    struct Node* head = NULL; // Initialize the head of the list
    int choice, value, position;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at end\n");
        printf("2. Insert before specified position\n");
        printf("3. Delete first node\n");
        printf("4. Delete node after specified position\n");
        printf("5. Traverse list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // User input for choice

        switch (choice) {
            case 1:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value); // Insert at end
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position before which to insert: ");
                scanf("%d", &position);
                insertBeforePosition(&head, value, position); // Insert before position
                break;
            case 3:
                deleteFirstNode(&head); // Delete first node
                break;
            case 4:
                printf("Enter position after which to delete: ");
                scanf("%d", &position);
                deleteAfterPosition(&head, position); // Delete after position
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
