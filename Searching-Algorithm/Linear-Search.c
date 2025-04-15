#include <stdio.h>

int c = 0;

int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        c++;
        if(arr[i] == key)
            return i;  // Element found at index i
    }
    return -1; // Element not found
}

int main() {
    int n, key;

    printf("Enter size of the array (N): ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int result = linearSearch(arr, n, key);

    if(result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in the array.\n");

    printf("Time Complexity: %d\n",c);

    return 0;
}
