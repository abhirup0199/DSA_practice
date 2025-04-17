#include <stdio.h>
#include <stdlib.h>

long long operationCount = 0; // For amortized analysis

int main() {
    int maxInputs;
    printf("Enter the maximum number of inputs: ");
    scanf("%d", &maxInputs);

    int capacity = 1;                  // Start with capacity 1
    int size = 0;                      // Current number of elements
    int *arr = (int *)malloc(capacity * sizeof(int));
    operationCount++;                 // malloc operation

    printf("Start entering %d integers:\n", maxInputs);

    for (int i = 0; i < maxInputs; i++) {
        int input;
        scanf("%d", &input);

        if (size == capacity) {
            // Double the capacity
            int newCapacity = 2 * capacity;
            int *newArr = (int *)malloc(newCapacity * sizeof(int));
            operationCount++; // malloc

            // Copy existing elements
            for (int j = 0; j < capacity; j++) {
                newArr[j] = arr[j];
                operationCount++; // each copy is one operation
            }

            free(arr);
            operationCount++; // free old array

            arr = newArr;
            capacity = newCapacity;
            operationCount += 2; // assignment operations
        }

        arr[size++] = input;
        operationCount++; // inserting element
    }

    printf("\nFinal Array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // Amortized Analysis: Aggregate Method
    printf("\n\nTotal actual operations: %lld\n", operationCount);
    printf("Amortized time per operation ≈ %.2f\n", (double)operationCount / maxInputs);

    free(arr);
    operationCount++;

    return 0;
}
