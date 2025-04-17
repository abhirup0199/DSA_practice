#include <stdio.h>
#include <time.h>

int count = 0;

void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
    count++;
}

int partition(int arr[], int low, int high) 
{
    count++;
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) 
    {
        count++;
        if (arr[j] < pivot) 
        {
            i++;
            swap(&arr[i], &arr[j]);
            count++;
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() 
{
    int size;

    printf("Give the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Give the elements of the array:\n");
    for (int i = 0; i < size; i++) 
    {
        printf("Array[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nGiven array:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    quickSort(arr, 0, size - 1);

    printf("\nSorted array:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Number of operations (comparisons and swaps): %d\n", count);

    return 0;
}
