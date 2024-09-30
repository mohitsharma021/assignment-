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
