#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Global operation counter for amortized analysis (accounting method)
long long operationCount = 0;

// Stack structure
typedef struct {
    int data[MAX];
    int top;
} Stack;

// Initialize stack
void init(Stack *s) {
    s->top = -1;
    operationCount++; // For init
}

// Check if stack is empty
int isEmpty(Stack *s) {
    operationCount++; // For checking
    return s->top == -1;
}

// Check if stack is full
int isFull(Stack *s) {
    operationCount++; // For checking
    return s->top == MAX - 1;
}

// Push an element onto the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->data[++(s->top)] = value;
    operationCount += 2; // One for increment, one for assignment
}

// Pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        return -1;
    }
    operationCount++; // For pop
    return s->data[(s->top)--];
}

// MultiPop(k): Pops k elements from the stack (or until empty)
void multiPop(Stack *s, int k) {
    printf("MultiPop(%d):\n", k);
    for (int i = 0; i < k && !isEmpty(s); i++) {
        int popped = pop(s);
        printf("Popped: %d\n", popped);
        operationCount++; // For loop iteration
    }
}

// Print the current contents of the stack
void printStack(Stack *s) {
    printf("Current Stack: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    init(&s);

    int n;
    printf("Enter number of elements to push: ");
    scanf("%d", &n);
    operationCount++;

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        push(&s, val);
        operationCount++;
    }

    printStack(&s);

    int k;
    printf("Enter value of k for MultiPop(k): ");
    scanf("%d", &k);
    operationCount++;

    multiPop(&s, k);

    printStack(&s);

    printf("Total number of operations (Amortized Accounting): %lld\n", operationCount);

    return 0;
}
