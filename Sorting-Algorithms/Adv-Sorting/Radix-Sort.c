#include <stdio.h>

// Global variable to count the number of key operations
int count = 0;

// Function to get the maximum value in the array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        count++;  // Comparison operation
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// A function to do counting sort of arr[] according to the digit represented by exp
void countingSort(int arr[], int n, int exp) {
    int output[n]; // Output array
    int count_arr[10] = {0};

    // Count occurrences of digits
    for (int i = 0; i < n; i++) {
        count++; // Counting digit access
        count_arr[(arr[i] / exp) % 10]++;
    }

    // Calculate position of each digit
    for (int i = 1; i < 10; i++) {
        count++; // Addition operation
        count_arr[i] += count_arr[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        count++; // Rearranging elements
        output[count_arr[(arr[i] / exp) % 10] - 1] = arr[i];
        count_arr[(arr[i] / exp) % 10]--;
    }

    // Copy sorted numbers back to original array
    for (int i = 0; i < n; i++) {
        count++; // Assignment
        arr[i] = output[i];
    }
}

// Main function to sort arr[] of size n using Radix Sort
void radixSort(int arr[], int n) {
    int m = getMax(arr, n);

    // Do counting sort for every digit (exp = 1, 10, 100, ...)
    for (int exp = 1; m / exp > 0; exp *= 10) {
        count++; // Loop condition check
        countingSort(arr, n, exp);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main program
int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array:\n");
    printArray(arr, n);

    // Perform radix sort
    radixSort(arr, n);

    printf("\nSorted array in ascending order:\n");
    printArray(arr, n);

    // Print the operation count as a proxy for time complexity
    printf("\nTime complexity (number of key operations): %d\n", count);

    return 0;
}
