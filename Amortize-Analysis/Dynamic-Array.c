#include <stdio.h>
#include <stdlib.h>
long long operationCount = 0;
int main()
{
    int maxInputs;
    printf("Enter the maximum number of inputs: ");
    scanf("%d", &maxInputs);
    int capacity = 1;
    int size = 0;
    int *arr = (int *)malloc(capacity * sizeof(int));
    operationCount++;
    printf("Start entering %d integers:\n", maxInputs);
    for (int i = 0; i < maxInputs; i++)
    {
        int input;
        scanf("%d", &input);
        if (size == capacity)
        {
            int newCapacity = 2 * capacity;
            int *newArr = (int *)malloc(newCapacity * sizeof(int));
            operationCount++;
            for (int j = 0; j < capacity; j++)
            {
                newArr[j] = arr[j];
                operationCount++;
            }
            free(arr);
            operationCount++;
            arr = newArr;
            capacity = newCapacity;
            operationCount += 2;
        }
        arr[size++] = input;
        operationCount++;
    }
    printf("\nFinal Array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nThe time complexity of the amortized analysis - aggregate method is: %lld\n", operationCount);
    free(arr);
    operationCount++;
    return 0;
}
