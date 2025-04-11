#include<stdio.h>

int count = 0;

void count_sort(int arr[], int n, int m) {
    int i, j;
    int c[m+1];
    int b[n];
    
    for(i = 0; i <= m; i++) {
        c[i] = 0;
    }
    
    for(j = 0; j < n; j++) {
        c[arr[j]] = c[arr[j]] + 1;
    }
    
    for(i = 1; i <= m; i++) {
        count++;
        c[i] = c[i] + c[i-1];
    }
    
    for(j = n-1; j >= 0; j--) {
        count++;
        b[c[arr[j]]-1] = arr[j];
        c[arr[j]]--;
    }
    
    printf("The sorted array is: \n");
    for(int k = 0; k < n; k++) {
        printf("%d\n", b[k]);
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    for(int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] >= max) {
            max = arr[i];
        }
    }
    
    count_sort(arr, n, max);
    printf("The time complexity of the count sort is: %d\n", count);
    
    return 0;
}
