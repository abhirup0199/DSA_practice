#include<stdio.h>
int main()
{
    int n, first = 0, second = 1, next;

    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    int com =0;
    for (int i = 0; i < n; i++) 
    {
        if (i <= 1) 
        {
            next = i;
        } 
        else 
        {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
        com++;
    }
    printf("\nComplexity:-%d\n",com);
    return 0;
}