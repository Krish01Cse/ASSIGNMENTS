#include <stdio.h>

// Function to find the maximum subarray sum under a given constraint
int findMaxSubarraySum(int resources[], int n, int constraint, int* bestStart, int* bestEnd) {
    if (n <= 0 || constraint <= 0) {
        *bestStart = -1;
        *bestEnd = -1;
        return 0;
    }

    int maxSum = 0;
    int currentSum = 0;
    int start = 0;
    *bestStart = -1;
    *bestEnd = -1;

    for (int end = 0; end < n; end++) {
        currentSum += resources[end];

        while (currentSum > constraint && start <= end) {
            currentSum -= resources[start];
            start++;
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            *bestStart = start;
            *bestEnd = end;
        }
    }

    // Handle case where no valid subarray is found
    if (maxSum == 0) {
        int hasZero = 0;
        for (int i = 0; i < n; i++) {
            if (resources[i] == 0 && 0 <= constraint) {
                *bestStart = i;
                *bestEnd = i;
                hasZero = 1;
                break;
            }
        }
        if (!hasZero) {
            *bestStart = -1;
            *bestEnd = -1;
        }
    }

    return maxSum;
}

// Function to run a single test case
void runTestCase(const char* testName, int resources[], int n, int constraint) {
    printf("--- %s ---\n", testName);
    printf("Input: resources = [");
    for (int i = 0; i < n; i++) {
        printf("%d", resources[i]);
        if (i < n - 1) printf(", ");
    }
    printf("], constraint = %d\n", constraint);

    int startIndex, endIndex;
    int maxSum = findMaxSubarraySum(resources, n, constraint, &startIndex, &endIndex);

    printf("Max Sum: %d\n", maxSum);

    if (startIndex != -1) {
        printf("Best Sum SubArray: [");
        for (int i = startIndex; i <= endIndex; i++) {
            printf("%d", resources[i]);
            if (i < endIndex) printf(", ");
        }
        printf("]\n\n");
    } else {
        printf("Best Sum SubArray: No feasible subarray found.\n\n");
    }
}

// Main function to execute all test cases
int main() {
    runTestCase("1. Basic small array", (int[]){2, 1, 3, 4}, 4, 5);
    runTestCase("2. Exact match to constraint", (int[]){2, 2, 2, 2}, 4, 4);
    runTestCase("3. Single element equals constraint", (int[]){1, 5, 2, 3}, 4, 5);
    runTestCase("4. No feasible subarray", (int[]){6, 7, 8}, 3, 5);
    runTestCase("5. Multiple optimal subarrays", (int[]){1, 2, 3, 2, 1}, 5, 5);
    runTestCase("6. Large window valid", (int[]){1, 1, 1, 1, 1}, 5, 4);
    runTestCase("7. Sliding window shrink needed", (int[]){4, 2, 3, 1}, 4, 5);
    runTestCase("8. Empty array", (int[]){}, 0, 10);
    runTestCase("9. Constraint = 0", (int[]){1, 2, 3}, 3, 0);

    return 0;
}