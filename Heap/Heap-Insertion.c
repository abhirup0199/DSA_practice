#include <stdio.h>

#define MAX_SIZE 1000

long long operationCount = 0; // To track number of operations (for time complexity analysis)

// Swap utility
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up operation for Max-Heap
void heapifyUp(int heap[], int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && heap[index] > heap[parent]) {
        operationCount++; // Comparison
        swap(&heap[index], &heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
    operationCount++; // Final comparison that breaks the loop
}

// Insert a new value into the heap
void insertHeap(int heap[], int *size, int value) {
    if (*size >= MAX_SIZE) {
        printf("Heap is full. Cannot insert.\n");
        return;
    }
    heap[*size] = value;
    (*size)++;
    operationCount++; // Insertion operation
    heapifyUp(heap, *size - 1);
}

// Display heap elements
void printHeap(int heap[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int heap[MAX_SIZE];
    int size = 0, n, value;

    // Input initial size of the heap
    printf("Enter number of initial elements in the heap: ");
    scanf("%d", &n);

    // Input initial elements
    printf("Enter %d elements to build the initial heap:\n", n);
    for (int i = 0; i < n; i++) {
        int element;
        scanf("%d", &element);
        insertHeap(heap, &size, element);
    }

    // Show initial heap
    printf("\nInitial heap:\n");
    printHeap(heap, size);

    // Reset operation count before new insertion
    operationCount = 0;

    // Insert new value into the heap
    printf("\nEnter element to insert into heap: ");
    scanf("%d", &value);
    insertHeap(heap, &size, value);

    // Show updated heap
    printf("\nHeap after insertion:\n");
    printHeap(heap, size);

    // Output operation count to indicate time complexity
    printf("\nNumber of operations during insertion: %lld\n", operationCount);
    return 0;
}
