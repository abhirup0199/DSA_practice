#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#include<stdlib.h>

int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;
    for(int v = 0; v < V; v++)
        if(mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(int parent[], int **graph, int V) {
    printf("Edge \tWeight\n");
    for(int i = 1; i < V; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int **graph, int V) {
    int *parent = (int *)malloc(V * sizeof(int));
    int *key = (int *)malloc(V * sizeof(int));
    bool *mstSet = (bool *)malloc(V * sizeof(bool));

    for(int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for(int count = 0; count < V-1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;
        for(int v = 0; v < V; v++)
            if(graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, graph, V);

    free(parent);
    free(key);
    free(mstSet);
}

void inputAdjacencyMatrix(int **matrix, int V) {
    printf("\nEnter adjacency matrix (0 for no edge):\n");
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(i == j) {
                matrix[i][j] = 0;
                continue;
            }
            printf("Enter weight for edge %d-%d (0 if no edge): ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void inputEdgeList(int **matrix, int V, int E) {
    printf("\nEnter edges in format: source destination weight\n");
    printf("(Vertex numbering starts from 0)\n");
    for(int i = 0; i < E; i++) {
        int src, dest, weight;
        printf("Edge %d: ", i+1);
        scanf("%d %d %d", &src, &dest, &weight);
        matrix[src][dest] = weight;
        matrix[dest][src] = weight; // Undirected graph
    }
}

int main() {
    int V, E;
    int choice;

    printf("PRIM'S ALGORITHM IMPLEMENTATION\n");
    printf("-------------------------------\n");
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    // Allocate matrix dynamically
    int **graph = (int **)malloc(V * sizeof(int *));
    for(int i = 0; i < V; i++) {
        graph[i] = (int *)malloc(V * sizeof(int));
        for(int j = 0; j < V; j++)
            graph[i][j] = 0; // Initialize with 0 (no edge)
    }

    printf("\nChoose input method:\n");
    printf("1. Edge list\n");
    printf("2. Adjacency matrix\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("\nEnter number of edges: ");
        scanf("%d", &E);
        inputEdgeList(graph, V, E);
    }
    else if(choice == 2) {
        inputAdjacencyMatrix(graph, V);
    }
    else {
        printf("Invalid choice. Exiting.\n");
        return 1;
    }

    printf("\nCalculating Minimum Spanning Tree...\n");
    primMST(graph, V);

    // Free memory
    for(int i = 0; i < V; i++)
        free(graph[i]);
    free(graph);

    return 0;
}
