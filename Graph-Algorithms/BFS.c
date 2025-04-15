#include <stdio.h>

int main()
{
    int vertices;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    int matrix[vertices][vertices];
    int visited[vertices];
    int queue[vertices];
    int front = 0, rear = 0;

    // Input adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
        for (int j = 0; j < vertices; j++)
        {
            printf("Matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print adjacency matrix
    printf("\nThe adjacency matrix is:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int start = 0; // Start BFS from vertex 0
    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear)
    {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < vertices; i++)
        {
            if (matrix[current][i] == 1 && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");

    return 0;
}
