#include <stdio.h>

void selection_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        int max = i;

        // Finding the min and max in the unsorted part
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
            if (a[j] > a[max])
                max = j;
        }

        // Swapping min with the first element of the unsorted part
        if (min != i)
        {
            int tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;

            // If max was at i, update max to min's old position
            if (max == i)
                max = min;
        }

        // Swapping max with the last element of the unsorted part
        if (max != n - i - 1)
        {
            int tmp = a[n - i - 1];
            a[n - i - 1] = a[max];
            a[max] = tmp;
        }
    }

    printf("The sorted array is ----\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int array[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Array[%d] = ", i);
        scanf("%d", &array[i]);
    }

    selection_sort(array, n);
    return 0;
}
