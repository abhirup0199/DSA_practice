#include<stdio.h>

int count = 0;

void count_sort(int arr[], int n, int m) {
    int i, j;
    int c[m+1]; // Count array to hold frequency of each element.
    int b[n];   // Output array to hold the sorted elements.
    
    // Initialize the count array to 0.
    for(i = 0; i <= m; i++) {
        c[i] = 0;
    }
    
    // Store the frequency of each element in the count array.
    for(j = 0; j < n; j++) {
        c[arr[j]] = c[arr[j]] + 1;
    }
    
    // Update the count array such that each element at index i stores the sum
    // of previous counts. This gives us the position of each element in the output array.
    for(i = 1; i <= m; i++) {
        c[i] = c[i] + c[i-1];
        count++;  // Adding to the count array (O(M)).
    }
    
    // Build the output array using the count array.
    for(j = n-1; j >= 0; j--) {
        b[c[arr[j]]-1] = arr[j];
        c[arr[j]]--;
        count++;  // Filling the output array (O(N)).
    }
    
    printf("The sorted array is: \n");
    for(int k = 0; k < n; k++) {
        printf("%d\n", b[k]);
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    for(int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    
    count_sort(arr, n, max);
    
    // Print the time complexity based on operations
    printf("Time complexity : %d\n", count);
    return 0;
}
