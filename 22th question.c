#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent a node in the adjacency list
struct Node {
    int data;
    struct Node *next;
};

// Structure to represent the graph
struct Graph {
    int numVertices;
    struct Node **adjLists;
};

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

// Function to create a new adjacency list node
struct Node* createNode(int v) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add an edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to perform BFS
void bfs(struct Graph *graph, int startVertex) {
    int visited[MAX] = {0}; // Array to track visited vertices
    int queue[MAX], front = -1, rear = -1;

    // Mark the starting vertex as visited and enqueue it
    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    printf("BFS Traversal starting from vertex %d: ", startVertex);

    while (front < rear) {
        front++;
        int currentVertex = queue[front];
        printf("%d ", currentVertex);

        // Traverse the adjacency list
        struct Node *temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[++rear] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    int vertices, edges, src, dest;
    
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    struct Graph *graph = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startVertex;
    printf("Enter starting vertex for BFS: ");
    scanf("%d", &startVertex);

    bfs(graph, startVertex);

    // Free allocated memory
    for (int i = 0; i < vertices; i++) {
        struct Node *temp = graph->adjLists[i];
        while (temp) {
            struct Node *toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(graph->adjLists);
    free(graph);

    return 0;
}
