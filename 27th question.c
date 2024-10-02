#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

// Function prototypes
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex);

int main() {
    int vertices, startVertex;
    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex (0 to %d): ", vertices - 1);
    scanf("%d", &startVertex);

    dijkstra(graph, vertices, startVertex);

    return 0;
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex) {
    int distance[MAX_VERTICES]; // Output array. distance[i] holds the shortest distance from startVertex to i
    int visited[MAX_VERTICES];   // Visited[i] wil
