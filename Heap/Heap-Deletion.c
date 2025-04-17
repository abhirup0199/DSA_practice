#include <stdio.h>
#define MAX_SIZE 1000

long long operationCount = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyDown(int heap[], int size, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest]) {
        largest = left;
        operationCount++;
    }
    if (right < size && heap[right] > heap[largest]) {
        largest = right;
        operationCount++;
    }

    if (largest != index) {
        swap(&heap[index], &heap[largest]);
        heapifyDown(heap, size, largest);
    }
}

void heapifyUp(int heap[], int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && heap[index] > heap[parent]) {
        swap(&heap[index], &heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
        operationCount += 2;
    }
}

void insertHeap(int heap[], int *size, int value) {
    int i = *size;
    heap[i] = value;
    (*size)++;
    operationCount += 2;
    heapifyUp(heap, i);
}

int deleteElement(int heap[], int *size, int value) {
    int i, found = 0;
    for (i = 0; i < *size; i++) {
        operationCount++;
        if (heap[i] == value) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element %d not found in heap.\n", value);
        return 0;
    }

    printf("Deleting element: %d\n", value);
    heap[i] = heap[*size - 1];
    (*size)--;
    operationCount++;

    if (i > 0 && heap[i] > heap[(i - 1) / 2]) {
        heapifyUp(heap, i);
    } else {
        heapifyDown(heap, *size, i);
    }

    return 1;
}

void printHeap(int heap[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int heap[MAX_SIZE], size = 0, n, deleteCount;

    printf("Enter number of elements in the heap: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        insertHeap(heap, &size, val);
    }

    printf("Initial Heap:\n");
    printHeap(heap, size);

    printf("Enter number of elements to delete: ");
    scanf("%d", &deleteCount);

    int toDelete[MAX_SIZE];
    printf("Enter %d elements to delete:\n", deleteCount);
    for (int i = 0; i < deleteCount; i++) {
        scanf("%d", &toDelete[i]);
    }

    long long initialOperations = operationCount;

    for (int i = 0; i < deleteCount; i++) {
        deleteElement(heap, &size, toDelete[i]);
        printf("Heap after deleting %d:\n", toDelete[i]);
        printHeap(heap, size);
    }
    printf("The Timecomplexity to delete an element from the heap is: %lld\n",operationCount);
    return 0;
}
