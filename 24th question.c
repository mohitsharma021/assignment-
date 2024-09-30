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
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // For undirected graph, add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Utility function for DFS to check for cycles
int dfs(struct Graph *graph, int vertex, int visited[], int parent) {
    visited[vertex] = 1; // Mark the current vertex as visited

    struct Node *temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->data;

        // If the adjacent vertex is not visited
        if (!visited[adjVertex]) {
            if (dfs(graph, adjVertex, visited, vertex)) {
                return 1; // Cycle found
            }
        }
        // If the adjacent vertex is visited and not the parent
        else if (adjVertex != parent) {
            return 1; // Cycle found
        }
        temp = temp->next;
    }
    return 0; // No cycle found
}

// Function to check if the graph is cyclic
int isCyclic(struct Graph *graph) {
    int visited[MAX] = {0};

    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            if (dfs(graph, i, visited, -1)) {
                return 1; // Cycle found
            }
        }
    }
    return 0; // No cycle found
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

    if (isCyclic(graph)) {
        printf("The graph is cyclic.\n");
    } else {
        printf("The graph is acyclic.\n");
    }

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
