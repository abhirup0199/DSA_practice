#include <stdio.h>

void heapify(int heap[], int n, int i) {
    int largest = i;
    while (1) {
        int l = 2*i + 1;
        int r = 2*i + 2;
        if (l < n && heap[l] > heap[largest])
            largest = l;
        if (r < n && heap[r] > heap[largest])
            largest = r;
        if (largest != i) {
            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            i = largest;
        } else {
            break;
        }
    }
}

int deleteMax(int heap[], int *n) {
    int max = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    heapify(heap, *n, 0);
    return max;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int heap[n];
   
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &heap[i]);

    printf("Deleted elements:\n");
    while (n > 0) {
        int max = deleteMax(heap, &n);
        printf("%d ", max);
    }
    printf("\n");
    return 0;
}
