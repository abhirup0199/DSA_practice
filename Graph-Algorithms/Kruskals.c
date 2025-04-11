#include<stdio.h>
#include<stdlib.h>

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct subset {
    int parent;
    int rank;
};

int find(struct subset subsets[], int i) {
    if(subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if(subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if(subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void KruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V];
    int e = 0;
    int i = 0;
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);
    struct subset* subsets = (struct subset*)malloc(V * sizeof(struct subset));
    for(int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while(e < V - 1 && i < graph->E) {
        struct Edge next_edge = graph->edge[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if(x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    printf("Edge \tWeight\n");
    for(i = 0; i < e; ++i)
        printf("%d - %d \t%d\n", result[i].src, result[i].dest, result[i].weight);
}

void inputAdjacencyMatrix(int **matrix, int V) {
    printf("\nEnter the adjacency matrix (enter 0 for no edge):\n");
    printf("Format: For each vertex pair (i,j), enter the edge weight.\n");
    printf("Note: The matrix is symmetric (edge i->j same as j->i)\n\n");
    
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

int matrixToEdgeList(int **matrix, int V, struct Edge* edgeList) {
    int E = 0;
    for(int i = 0; i < V; i++) {
        for(int j = i + 1; j < V; j++) { // Only upper triangular to avoid duplicates
            if(matrix[i][j] != 0) {
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
    int V, E;
    int choice;
    
    printf("KRUSKAL'S ALGORITHM IMPLEMENTATION\n");
    printf("----------------------------------\n");
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    // Allocate matrix dynamically
    int **matrix = (int **)malloc(V * sizeof(int *));
    for(int i = 0; i < V; i++)
        matrix[i] = (int *)malloc(V * sizeof(int));

    printf("\nChoose input method:\n");
    printf("1. Edge list (source, destination, weight)\n");
    printf("2. Adjacency matrix (enter weights for all edges)\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->edge = (struct Edge*)malloc(V*(V-1)/2 * sizeof(struct Edge)); // Max edges in undirected graph

    if(choice == 1) {
        printf("\nEnter number of edges: ");
        scanf("%d", &E);
        graph->E = E;
        printf("\nEnter edges in format: source destination weight\n");
        printf("(Vertex numbering starts from 0)\n");
        for(int i = 0; i < E; i++) {
            printf("Edge %d: ", i+1);
            scanf("%d %d %d", &graph->edge[i].src, &graph->edge[i].dest, &graph->edge[i].weight);
        }
    } 
    else if(choice == 2) {
        inputAdjacencyMatrix(matrix, V);
        graph->E = matrixToEdgeList(matrix, V, graph->edge);
    }
    else {
        printf("Invalid choice. Exiting.\n");
        return 1;
    }

    // Free matrix memory
    for(int i = 0; i < V; i++)
        free(matrix[i]);
    free(matrix);

    printf("\nCalculating Minimum Spanning Tree...\n");
    KruskalMST(graph);
    
    free(graph->edge);
    free(graph);
    return 0;
}
