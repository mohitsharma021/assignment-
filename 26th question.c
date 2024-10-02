#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

// Function prototypes
void primsAlgorithm(int graph[MAX_VERTICES][MAX_VERTICES], int vertices);

int main() {
    int vertices;
    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primsAlgorithm(graph, vertices);

    return 0;
}

void primsAlgorithm(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    int parent[MAX_VERTICES]; // Array to store constructed MST
    int key[MAX_VERTICES];    // Key values used to pick minimum weight edge
    int mstSet[MAX_VERTICES]; // To represent the set of vertices included in MST

    // Initialize all keys as infinite and mstSet as false
    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
        parent[i] = -1; // No parent for the first vertex
    }

    // Starting with the first vertex
    key[0] = 0; // Make the key of the first vertex as 0

    for (int count = 0; count < vertices - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int minKey = INT_MAX, minIndex;
        for (int v = 0; v < vertices; v++) {
            if (mstSet[v] == 0 && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }

        // Add the picked vertex to the MST set
        mstSet[minIndex] = 1;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < vertices; v++) {
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[minIndex][v] && mstSet[v] == 0 && graph[minIndex][v] < key[v]) {
                parent[v] = minIndex;
                key[v] = graph[minIndex][v];
            }
        }
    }

    // Print the constructed MST
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertices; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}
