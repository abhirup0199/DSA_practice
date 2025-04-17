#include <stdio.h>
#define MAX_SIZE 1000

long long operationCount = 0; // To estimate time complexity

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    operationCount++; // Count swap as an operation
}

// Heapify function to maintain max heap property
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
        operationCount++; // Count comparison
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
        operationCount++; // Count comparison
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest); // Recursive call
    }
}

// Heap sort function
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);    // Move current root to end
        heapify(arr, i, 0);        // Call heapify on the reduced heap
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[MAX_SIZE], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array (ascending order):\n");
    printArray(arr, n);

    printf("Estimated operation count (time complexity estimation): %lld\n", operationCount);

    return 0;
}
