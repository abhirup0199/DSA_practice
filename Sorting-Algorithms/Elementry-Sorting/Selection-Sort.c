#include <stdio.h>

int c = 0; // Global variable to count comparisons

// Function to perform Selection Sort in ascending order
void selection_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        c++; // Count the comparison below

        for (int j = i + 1; j < n; j++)
        {
            c++; // Count the comparison below
            if (a[j] < a[min])
                min = j;
        }

        // Swap only if needed
        if (min != i)
        {
            int tmp = a[i];
            a[i] = a[min];
            a[min] = tmp;
            c+= 3; // Count the three assignments in the swap
        }
        c++; // Count the comparison for the swap check
    }

    // Display the sorted array
    printf("\nThe sorted array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");

    // Display comparison count
    printf("Total number of comparisons: %d\n", c);

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
