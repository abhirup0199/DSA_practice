#include <stdio.h>

void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}

void buildHeap(int a[], int n) {
    int i;
    for (i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int a[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    buildHeap(a, n);

    printf("Heap after building:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
