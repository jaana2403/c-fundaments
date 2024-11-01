#include <stdio.h>

int n, W, v[10], w[10], V[10][10], x[10];

// Function to find the maximum of two values
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the solution (items included in the knapsack)
void solution() {
    int i = n, j = W;
    while (i != 0 && j != 0) {
        if (V[i][j] != V[i-1][j]) {
            x[i] = 1; // Mark item i as included
            j = j - w[i]; // Reduce remaining capacity
        }
        i--; // Move to the previous item
    }
}

// Function to compute the knapsack table using dynamic programming
void knapsack() {
    int i, j;
    
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                V[i][j] = 0; // No items or zero capacity
            } else if (j < w[i]) {
                V[i][j] = V[i-1][j]; // Item i can't be included, retain previous max
            } else {
                V[i][j] = max(V[i-1][j], V[i-1][j-w[i]] + v[i]); // Max of including or excluding item i
            }
            printf("%d ", V[i][j]); // Print the table (optional)
        }
        printf("\n"); // For better formatting of the table
    }
}

int main() {
    int i;
    
    // Read the number of objects
    printf("\nRead number of objects: ");
    scanf("%d", &n);
    
    // Read the capacity of the knapsack
    printf("\nRead knapsack capacity: ");
    scanf("%d", &W);
    
    // Read the weights of the objects
    printf("\nRead weights of objects:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    
    // Read the profits (values) of the objects
    printf("\nRead profits of objects:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }
    
    // Perform the knapsack dynamic programming
    knapsack();
    
    // Find the solution (items included)
    solution();
    
    // Print the solution
    printf("\nObject\tWeight\tProfit\n");
    for (i = 1; i <= n; i++) {
        if (x[i] == 1) {
            printf("%d\t%d\t%d\n", i, w[i], v[i]);
        }
    }
    
    // Print the maximum profit
    printf("\nMaximum profit is %d\n", V[n][W]);
    
    return 0;
}
