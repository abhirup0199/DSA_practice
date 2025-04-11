//Sort indices by value

#include <stdio.h>

void sortIndicesByValues(int array[], int n, int indices[]) {
    // Main algorithm (Bubble Sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                // Swap indices
                int tempIndex = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = tempIndex;

                // Swap array values
                int tempValue = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tempValue;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int array[n];
    int indices[n];

    printf("Enter the elements of the array ---------\n");
    for (int i = 0; i < n; i++) {
        printf("array[%d]: ", i);
        scanf("%d", &array[i]);
        indices[i] = i; // Initialize indices
    }

    // Sort indices based on the values in the array
    sortIndicesByValues(array, n, indices);

    // Output the sorted indices
    printf("Indices in ascending order of the elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", indices[i]);
    }
    printf("\n");

    return 0;
}