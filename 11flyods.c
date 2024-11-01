#include <stdio.h>
#define INF 9999  // Define a large value for unreachable paths

// Function to return the minimum of two values
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to implement Floyd-Warshall algorithm
void floyds(int D[10][10], int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Update the distance if a shorter path is found
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }
}

int main() {
    int n, i, j, D[10][10];

    // Read the number of nodes
    printf("\nRead number of nodes: ");
    scanf("%d", &n);

    // Read the weighted graph
    printf("\nRead weighted graph (use %d for infinity):\n", INF);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &D[i][j]);
        }
    }

    // Apply Floyd-Warshall algorithm
    floyds(D, n);

    // Output the shortest path matrix
    printf("\nThe all-pairs shortest path matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (D[i][j] == INF) {
                printf("INF\t");  // Print "INF" for unreachable paths
            } else {
                printf("%d\t", D[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
