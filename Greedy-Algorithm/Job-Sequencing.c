// Job sequencing

#include <stdio.h>
#include <stdlib.h>

#define MAX_JOBS 100

// Function to compare two jobs based on profit for qsort
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // Sort in descending order of profit
}

// Function to find the maximum deadline
int maximum(int deadline[], int n) {
    int max = deadline[0];
    for (int i = 1; i < n; i++) {
        if (deadline[i] > max) {
            max = deadline[i];
        }
    }
    return max;
}

// Function to perform job sequencing
void jobSequencing(int jobId[], int deadline[], int profit[], int n) {
    // Sort jobs based on profit using a simple bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (profit[j] < profit[j + 1]) {
                // Swap profits
                int tempProfit = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = tempProfit;

                // Swap deadlines
                int tempDeadline = deadline[j];
                deadline[j] = deadline[j + 1];
                deadline[j + 1] = tempDeadline;

                // Swap job IDs
                int tempId = jobId[j];
                jobId[j] = jobId[j + 1];
                jobId[j + 1] = tempId;
            }
        }
    }

    int maxDeadline = maximum(deadline, n);
    int slot[MAX_JOBS]; // To keep track of free time slots

    // Initialize all slots as free
    for (int i = 0; i < maxDeadline; i++) {
        slot[i] = -1;
    }

    // Iterate through all jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (starting from the last possible slot)
        for (int j = (deadline[i] < maxDeadline ? deadline[i] : maxDeadline) - 1; j >= 0; j--) {
            if (slot[j] == -1) { // If the slot is free
                slot[j] = jobId[i]; // Assign job ID to the slot
                break;
            }
        }
    }

    // Print the scheduled jobs
    printf("Scheduled jobs are:\n");
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i] != -1) {
            printf("Job ID: %d\n", slot[i]);
        }
    }
}

int main() {
    int n;
    int jobId[MAX_JOBS];
    int deadline[MAX_JOBS];
    int profit[MAX_JOBS];

    printf("Enter number of jobs: ");
    scanf("%d", &n);
    
    printf("Enter deadline and profit for each job:\n");
    for (int i = 0; i < n; i++) {
        jobId[i] = i + 1; // Assign job ID
        scanf("%d %d", &deadline[i], &profit[i]);
    }

    jobSequencing(jobId, deadline, profit, n);

    return 0;
}