#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;               // Data stored in the node
    struct Node* next;      // Pointer to the next node
};

// Define a queue structure
struct Queue {
    struct Node* front;     // Pointer to the front of the queue
    struct Node* rear;      // Pointer to the rear of the queue
};

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;    // Initialize front to NULL
    queue->rear = NULL;     // Initialize rear to NULL
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == NULL; // Return 1 if queue is empty
}

// Function to enqueue an element into the queue
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;    // Set the data
    newNode->next = NULL;    // The new node will be the last node

    if (queue->rear == NULL) {
        // If the queue is empty, both front and rear will point to the new node
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        // Link the new node at the end of the queue and update rear
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("%d enqueued to queue\n", data);
}

// Function to dequeue an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow\n");
        return -1; // Indicate that the queue is empty
    }
    struct Node* temp = queue->front; // Store the front node
    int dequeuedValue = temp->data;    // Get the data to return
    queue->front = queue->front->next; // Move front to the next node

    if (queue->front == NULL) {
        // If the queue is now empty, update rear to NULL
        queue->rear = NULL;
    }
    free(temp); // Free the dequeued node
    return dequeuedValue; // Return the dequeued value
}

// Function to peek at the front element of the queue
int peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1; // Indicate that the queue is empty
    }
    return queue->front->data; // Return the front value
}

// Function to display the queue contents
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* current = queue->front;
    printf("Queue contents: ");
    while (current) {
        printf("%d ", current->data); // Print the data
        current = current->next; // Move to the next node
    }
    printf("\n");
}

// Main function to implement the menu-driven interface
int main() {
    struct Queue* queue = createQueue(); // Create a new queue
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // User input for choice

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value); // Enqueue value
                break;
            case 2:
                value = dequeue(queue); // Dequeue value
                if (value != -1) {
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                value = peek(queue); // Peek at the front value
                if (value != -1) {
                    printf("Front value: %d\n", value);
                }
                break;
            case 4:
                display(queue); // Display the queue contents
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    // Free the allocated memory for the queue
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue); // Free the queue structure

    return 0;
}
