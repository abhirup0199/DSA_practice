#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
long long operationCount = 0;
typedef struct
{
    int data[MAX];
    int top;
} Stack;
void init(Stack *s)
{
    s->top = -1;
    operationCount++;
}
int isEmpty(Stack *s)
{
    operationCount++;
    return s->top == -1;
}

int isFull(Stack *s)
{
    operationCount++;
    return s->top == MAX - 1;
}
void push(Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack overflow!\n");
        return;
    }
    s->data[++(s->top)] = value;
    operationCount += 2;
}
int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow!\n");
        return -1;
    }
    operationCount++;
    return s->data[(s->top)--];
}
void multiPop(Stack *s, int k)
{
    printf("MultiPop(%d):\n", k);
    for (int i = 0; i < k && !isEmpty(s); i++)
    {
        int popped = pop(s);
        printf("Popped: %d\n", popped);
        operationCount++;
    }
}
void printStack(Stack *s)
{
    printf("Current Stack: ");
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}
int main()
{
    Stack s;
    init(&s);
    int n;
    printf("Enter number of elements to push: ");
    scanf("%d", &n);
    operationCount++;
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        push(&s, val);
        operationCount++;
    }
    printStack(&s);
    int k;
    printf("Enter value of k for MultiPop(k): ");
    scanf("%d", &k);
    multiPop(&s, k);
    printStack(&s);
    printf("The Timecomplexity of the amortized analysis using accounting method is: %lld\n", operationCount);
    return 0;
}
