#include <stdio.h>

static int count = 0; // Counts number of comparisons (as a proxy for time complexity)

void merge(int a[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = a[low + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        count++; // Counting comparison
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (i < n1) {
        a[k++] = L[i++];
        count++; // Counting assignment
    }

    while (j < n2) {
        a[k++] = R[j++];
        count++; // Counting assignment
    }
}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    printf("\nOriginal Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    mergeSort(a, 0, n - 1);

    printf("\n\nSorted Array (Ascending Order):\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n\nTime Complexity (approx. comparison count): %d\n", count);

    return 0;
}
