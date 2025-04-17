#include <stdio.h>

// Function to perform insertion sort and return operation count
int insertionSort(int arr[], int n)
{
    int count = 0;

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
            count += 2; // counting shifts
        }

        arr[j + 1] = key;
        count++; // for inserting key
    }

    return count;
}

int main()
{
    int N;
    printf("Enter the size of the array (N): ");
    scanf("%d", &N);

    int arr[N];
    printf("Enter %d elements of the array:\n", N);
    for (int i = 0; i < N; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal array: ");
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);

    // Call the sorting function
    int complexity = insertionSort(arr, N);

    printf("\nSorted array in ascending order: ");
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);

    printf("\n\nTime Complexity (approx. operation count): %d\n", complexity);

    return 0;
}
