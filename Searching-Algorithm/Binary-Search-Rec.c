//Binary search Recursive

#include <stdio.h>


int binary_search(int a[], int search, int low, int high) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;
    if (a[mid] == search) {
        return mid;
    }
    else if (a[mid] > search) {
        return binary_search(a, search, low, mid - 1);
    }
    else {
        return binary_search(a, search, mid + 1, high);
    }
}

int main() {
    int size;
    printf("Enter the number of elements in the sorted array: ");
    scanf("%d", &size);

    int sorted_array[size];
    printf("Enter the elements of the sorted array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &sorted_array[i]);
    }

    int target_value;
    printf("Enter the target value to search for: ");
    scanf("%d", &target_value);
    int result = binary_search(sorted_array, target_value, 0, size - 1);
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
