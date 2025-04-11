#include<stdio.h>

int count = 0;

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        count++;
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count_arr[10] = {0};
    
    for (int i = 0; i < n; i++) {
        count++;
        count_arr[(arr[i]/exp)%10]++;
    }
    
    for (int i = 1; i < 10; i++) {
        count++;
        count_arr[i] += count_arr[i-1];
    }
    
    for (int i = n-1; i >= 0; i--) {
        count++;
        output[count_arr[(arr[i]/exp)%10] - 1] = arr[i];
        count_arr[(arr[i]/exp)%10]--;
    }
    
    for (int i = 0; i < n; i++) {
        count++;
        arr[i] = output[i];
    }
}

void radixsort(int arr[], int n) {
    int m = getMax(arr, n);
    
    for (int exp = 1; m/exp > 0; exp *= 10) {
        count++;
        countingSort(arr, n, exp);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    
    printf("Original array: \n");
    printArray(arr, n);
    
    radixsort(arr, n);
    
    printf("Sorted array: \n");
    printArray(arr, n);
    printf("Time complexity count: %d\n", count);
    
    return 0;
}
