#include <stdio.h>
#define MAX_SIZE 1000

long long operationCount = 0;  // To count operations as a proxy for time complexity

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// To heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;          // Initialize largest as root
    int left = 2 * i + 1;     // left child index
    int right = 2 * i + 2;    // right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
        operationCount++;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
        operationCount++;
    }

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);  // Recursively heapify the affected sub-tree
    }
}

// Main function to perform heap sort
void heapSort(int arr[], int n) {
    // Build a maxheap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
        operationCount++;
    }

    // One by one extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);    // Move current root to end
        heapify(arr, i, 0);        // Call max heapify on the reduced heap
        operationCount++;
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[MAX_SIZE], n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        operationCount++;
    }

    printf("Original array:\n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array (ascending order):\n");
    printArray(arr, n);

    printf("Operation count (approximate time complexity for N = %d): %lld\n", n, operationCount);
    return 0;
}
