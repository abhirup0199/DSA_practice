//DFS
#include <stdio.h>

int main() 
{
    int vertices;
    int top = -1;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    int matrix[vertices][vertices];
    int cpy[vertices][vertices];
    int stack[vertices];
    int traversal[vertices];
    int index = 0;

    for (int i = 0; i < vertices; i++) 
    {
        for (int j = 0; j < vertices; j++) 
        {
            cpy[i][j] = 0;
        }
    }

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) 
    {
        for (int j = 0; j < vertices; j++) 
        {
            printf("Matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
            cpy[i][j] = matrix[i][j];
        }
    }

    printf("\nThe adjacency matrix is:\n");
    for (int i = 0; i < vertices; i++) 
    {
        for (int j = 0; j < vertices; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    stack[++top] = 0;

    while (top >= 0) 
    {
        int current = stack[top--];
        traversal[index++] = current;

        for (int i = 0; i < vertices; i++) 
        {
            if (cpy[current][i] == 1) 
            {
                cpy[current][i] = 0;
                cpy[i][current] = 0;
                stack[++top] = i;
            }
        }
    }

    printf("\nDFS Traversal : ");
    for (int i = 0; i < index; i++) 
    {
        printf("%d ", traversal[i]);
    }

    printf("\n");
    return 0;
}
