#include <stdio.h>

// Global variable to count number of function calls
int c = 0;

// Recursive Fibonacci function
int fibonacci(int n) {
    c++;
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);

    printf("Fibonacci Series up to %d terms:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    printf("\nTotal recursive calls: %d\n", c);

    // Time Complexity Info
    printf("Time Complexity of Recursive Fibonacci: O(2^n)\n");

    return 0;
}
