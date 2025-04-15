#include <stdio.h>

int main() 
{
    int vertices;
    int top = -1;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    int matrix[vertices][vertices];
    int stack[vertices];
    int visited[vertices];
    int traversal[vertices];
    int index = 0;

    for (int i = 0; i < vertices; i++) 
        visited[i] = 0;

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) 
    {
        for (int j = 0; j < vertices; j++) 
        {
            printf("Matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    int start;
    printf("Enter the starting node (0 to %d): ", vertices - 1);
    scanf("%d", &start);

    stack[++top] = start;
    visited[start] = 1;

    while (top >= 0) 
    {
        int current = stack[top--];
        traversal[index++] = current;

        for (int i = vertices - 1; i >= 0; i--) 
        {
            if (matrix[current][i] == 1 && !visited[i]) 
            {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\nDFS Traversal: ");
    for (int i = 0; i < index; i++) 
        printf("%d ", traversal[i]);

    printf("\n");
    return 0;
}
