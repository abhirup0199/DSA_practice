// BFS (Bredth First Search)
#include <stdio.h>

int main()
{
    int vertices;
    int front = 0, rear = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    int matrix[vertices][vertices];
    int cpy[vertices][vertices];
    int queue[vertices];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf("Matrix[%d][%d]:", i, j);
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
    queue[rear++] = 0;

    while (front < rear)
    {
        int current = queue[front++];
        
        for (int i = 0; i < vertices; i++)
        {
            if (cpy[current][i] == 1)
            {
                cpy[current][i] = 0;
                cpy[i][current] = 0;
                queue[rear++] = i;
            }
            for(int k=0;k< vertices;k++)
            {
                cpy[k][i]=0;
            }
        }
    }
   
    printf("BFS Traversal: ");
    
    for (int j = 0; j < vertices; j++)
    {
        printf("%d ", queue[j]);
    }
    printf("\n");

    return 0;
}
