//Rank Sort

#include <stdio.h>

void rankElements(int arr[], int n, int ranks[]) {
    int sorted[n];
    
    for (int i = 0; i < n; i++) {
        sorted[i] = arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (sorted[j] > sorted[j + 1]) {
                int temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] == sorted[j]) {
                ranks[i] = j + 1; 
                break;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    int ranks[n];

    printf("Enter the elements of the array ---------\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    rankElements(arr, n, ranks);

    printf("\nElement\tRank\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", arr[i], ranks[i]);
    }

    return 0;
}