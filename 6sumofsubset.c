#include <stdio.h>

int w[10], x[10], d;

// Function to find and print subsets with a sum equal to `d`
void sum_subset(int s, int k, int r) {
    int i;
    static int b = 1;  // Counter for subset number
    x[k] = 1;

    // If a subset with the required sum is found
    if (s + w[k] == d) {
        printf("Subset %d: ", b++);
        for (i = 0; i <= k; i++) {
            if (x[i] == 1) {
                printf("%d\t", w[i]);
            }
        }
        printf("\n");  // Print the subset on a new line
    }
    
    // Recursive case to explore subsets including w[k+1]
    else if (s + w[k] + w[k + 1] <= d) {
        sum_subset(s + w[k], k + 1, r - w[k]);
    }

    // Explore the next element (without including w[k])
    x[k] = 0;
    if (s + r - w[k] >= d && s + w[k + 1] <= d) {
        sum_subset(s, k + 1, r - w[k]);
    }
}

int main() {
    int n, i, sum = 0;

    // Read number of elements
    printf("Read number of elements: ");
    scanf("%d", &n);

    // Read the elements of the array
    printf("Read elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        sum += w[i];
    }

    // Read the maximum sum for the subsets
    printf("Read the subset max value: ");
    scanf("%d", &d);

    // Check for no solution case
    if (sum < d || w[0] > d) {
        printf("No solution\n");
    } else {
        sum_subset(0, 0, sum);  // Start subset sum calculation
    }

    return 0;
}
