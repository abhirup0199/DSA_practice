#include <stdio.h>

int count = 0; // Counter to track time complexity (loop operations)

void bubble_sort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        count++; // Outer loop count
        for(int j = 0; j < n - i - 1; j++)
        {
            count++; // Inner loop count
            if(arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = 1;
                count++; // Swap operation count
            }
        }
        if(flag == 0)
            break;
    }

    printf("\nThe sorted array is ----\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    printf("\nTotal count (approximate operations): %d\n", count);
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int array[n];
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; i++)
    {
        printf("Array[%d] = ", i);
        scanf("%d", &array[i]);
    }

    bubble_sort(array, n);

    return 0;
}
