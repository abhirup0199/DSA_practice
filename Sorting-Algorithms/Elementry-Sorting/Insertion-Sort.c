#include <stdio.h>

int main()
{
    int size;
    int count = 0;
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
    
    for (int step = 1; step < size; step++)
    {

        int key = arr[step];
        int j = step - 1;

        while (j >= 0 && key < arr[j])
        {
            count++;
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
        count++;
    }
    printf("\nSorted array is -------------\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\nComplexity = %d\n", count);
    return 0;
}