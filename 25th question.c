#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to compare two edges (for qsort)
int compareEdges(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

// Find function with path compression
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

// Union function by rank
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to implement Kruskal's Algorithm
void kruskal(struct Edge edges[], int V, int E) {
    struct Edge result[V]; // To store the resultant MST
    int e = 0; // Count of edges in MST
    int i = 0; // Initial index of sorted edges

    // Step 1: Sort edges based on their weights
    qsort(edges, E, sizeof(edges[0]), compareEdges);

    // Allocate memory for creating V subsets
    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));

    // Initialize subsets
    for (int v = 0; v < V; v++)
