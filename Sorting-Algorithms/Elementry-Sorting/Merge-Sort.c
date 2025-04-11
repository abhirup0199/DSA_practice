#include <stdio.h>
int count=0;
void merge(int arr[], int low, int mid, int high)
{
    count++;
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2)
    {
        count++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        count++;
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int size;
    printf("Give the size of the array:-");
    scanf("%d", &size);
    int arr[size];
    printf("Give the elements of the array--------\n");
    for (int i = 0; i < size; i++)
    {
        printf("Array[%d]=", i);
        scanf("%d", &arr[i]);
    }
    printf("Given array is ------------\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    count++;
    mergeSort(arr, 0, size - 1);
    printf("\nSorted array is -------------\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\nComplexity = %d\n", count);
    return 0;
}