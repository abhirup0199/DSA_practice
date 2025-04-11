//Greedy Knapsack

#include <stdio.h>

void sortItems(int n, int profits[], int weights[], float ratios[]) {
    // Simple bubble sort based on the ratio
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratios[j] < ratios[j + 1]) {
                // Swap ratios
                float tempRatio = ratios[j];
                ratios[j] = ratios[j + 1];
                ratios[j + 1] = tempRatio;

                // Swap profits
                int tempProfit = profits[j];
                profits[j] = profits[j + 1];
                profits[j + 1] = tempProfit;

                // Swap weights
                int tempWeight = weights[j];
                weights[j] = weights[j + 1];
                weights[j + 1] = tempWeight;
            }
        }
    }
}

// Function to implement the greedy knapsack algorithm
float knapsack(int n, int capacity, int profits[], int weights[]) {
    float totalProfit = 0.0;
    float ratios[n];

    // Calculate profit/weight ratio
    for (int i = 0; i < n; i++) {
        ratios[i] = (float)profits[i] / weights[i];
    }

    // Sort items by profit/weight ratio in descending order
    sortItems(n, profits, weights, ratios);

    // Greedily add items to the knapsack
    for (int i = 0; i < n; i++) {
        if (capacity == 0) {
            break; // Knapsack is full
        }
        if (weights[i] <= capacity) {
            // Take the whole item
            totalProfit += profits[i];
            capacity -= weights[i];
        } else {
            // Take the fraction of the item
            totalProfit += profits[i] * ((float)capacity / weights[i]);
            capacity = 0; // Knapsack is full
        }
    }
    return totalProfit;
}

int main() {
    int n, capacity;

    // User input for number of objects and capacity
    printf("Enter the number of objects: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    int profits[n], weights[n];

    // User input for profits and weights
    printf("Enter the profits of the objects:\n");
    for (int i = 0; i < n; i++) {
        printf("Profit of object %d: ", i + 1);
        scanf("%d", &profits[i]);
    }

    printf("Enter the weights of the objects:\n");
    for (int i = 0; i < n; i++) {
        printf("Weight of object %d: ", i + 1);
        scanf("%d", &weights[i]);
    }

    // Calculate maximum profit
    float maxProfit = knapsack(n, capacity, profits, weights);
    printf("Maximum profit that can be obtained: %.2f\n", maxProfit);

    return 0;
}