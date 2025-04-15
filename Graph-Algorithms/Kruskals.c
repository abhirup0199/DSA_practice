#include <stdio.h>
#include <stdlib.h>

// Edge representation
struct Edge {
    int src, dest, weight;
};

// Graph representation
struct Graph {
    int V, E;
    struct Edge* edge;
};

// Subset for Union-Find
struct subset {
    int parent;
    int rank;
};

// Find with path compression
int find(struct subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union by rank
void Union(struct subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Safe comparator for qsort
int compare(const void* a, const void* b) {
    int w1 = ((struct Edge*)a)->weight;
    int w2 = ((struct Edge*)b)->weight;
    return (w1 > w2) - (w1 < w2);
}

// Kruskal's algorithm implementation
void KruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V];
    int e = 0, i = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);

    struct subset* subsets = (struct subset*)malloc(V * sizeof(struct subset));

    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E) {
        struct Edge next_edge = graph->edge[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    printf("\nMinimum Spanning Tree (Kruskal's Algorithm):\n");
    printf("Edge\t\tWeight\n");
    printf("------------------------\n");
    for (i = 0; i < e; ++i)
        printf("%d - %d\t\t%d\n", result[i].src, result[i].dest, result[i].weight);

    free(subsets);
}

// Adjacency matrix input
void inputAdjacencyMatrix(int **matrix, int V) {
    printf("\nEnter the adjacency matrix (0 = no edge):\n\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) {
                matrix[i][j] = 0;
                continue;
            }
            printf("Enter weight for edge %d-%d: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Convert matrix to edge list
int matrixToEdgeList(int **matrix, int V, struct Edge* edgeList) {
    int E = 0;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (matrix[i][j] != 0) {
                edgeList[E].src = i;
                edgeList[E].dest = j;
                edgeList[E].weight = matrix[i][j];
                E++;
            }
        }
    }
    return E;
}

int main() {
    int V, E, choice;

    printf("KRUSKAL'S ALGORITHM IMPLEMENTATION\n");
    printf("----------------------------------\n");
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int **matrix = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        matrix[i] = (int *)malloc(V * sizeof(int));

    printf("\nChoose input method:\n");
    printf("1. Edge list (source, destination, weight)\n");
    printf("2. Adjacency matrix\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    if (choice == 1) {
        printf("\nEnter number of edges: ");
        scanf("%d", &E);
        graph->E = E;
        graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));

        printf("\nEnter edges (src dest weight):\n");
        for (int i = 0; i < E; i++) {
            printf("Edge %d: ", i + 1);
            scanf("%d %d %d", &graph->edge[i].src, &graph->edge[i].dest, &graph->edge[i].weight);
        }
    } else if (choice == 2) {
        inputAdjacencyMatrix(matrix, V);
        graph->edge = (struct Edge*)malloc(V * (V - 1) / 2 * sizeof(struct Edge)); // max possible
        graph->E = matrixToEdgeList(matrix, V, graph->edge);
    } else {
        printf("Invalid choice. Exiting.\n");
        return 1;
    }

    for (int i = 0; i < V; i++)
        free(matrix[i]);
    free(matrix);

    printf("\nCalculating Minimum Spanning Tree...\n");
    KruskalMST(graph);

    free(graph->edge);
    free(graph);

    return 0;
}
