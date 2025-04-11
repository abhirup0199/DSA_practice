#include <stdio.h>

void insert(int heap[], int *n, int value) {
    int i = *n;
    heap[i] = value;
    while (i > 0 && heap[(i - 1)/2] < heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1)/2];
        heap[(i - 1)/2] = temp;
        i = (i - 1)/2;
    }
    (*n)++;
}

int main() {
    int value, i;
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int heap[n];
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &heap[i]);

    printf("Enter value to insert: ");
    scanf("%d", &value);

    insert(heap, &n, value);

    printf("Heap after insertion:\n");
    for (i = 0; i < n; i++)
        printf("%d ", heap[i]);
    printf("\n");
    return 0;
}
