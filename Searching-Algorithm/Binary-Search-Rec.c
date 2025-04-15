#include <stdio.h>
#include <math.h>  // For log2()

static int c = 0; // Counter for time complexity

int binary_search(int a[], int search, int low, int high) {
    if (low <= high) {
        c++; // Increment the counter for each recursive call

        int mid = low + (high - low) / 2;
        if (a[mid] == search) {
            return mid;
        } else if (a[mid] > search) {
            return binary_search(a, search, low, mid - 1);
        } else {
            return binary_search(a, search, mid + 1, high);
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter the number of elements in the sorted array (N): ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements of the sorted array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int target;
    printf("Enter the target value to search for: ");
    scanf("%d", &target);

    int res = binary_search(a, target, 0, n - 1);

    if (res != -1) {
        printf("Element found at index: %d\n", res);
    } else {
        printf("Element not found in the array.\n");
    }

    // Time complexity computation
    printf("Actual number of recursive steps taken: %d\n", c);

    return 0;
}
