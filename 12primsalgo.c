#include <stdio.h>
#define INF 999

void prims(int n, int cost[10][10]) {
    int i, j, u = 0, v = 0, min, mincost = 0, vis[10], ne = 1;
    
    // Initialize the visited array to mark nodes as unvisited initially
    for (i = 1; i <= n; i++) {
        vis[i] = 0;
    }

    // Prim's algorithm starts from the first node
    vis[1] = 1;
    
    printf("\nEdges included in the MST are:\n");
    
    while (ne < n) {
        min = INF;  // Initialize minimum cost as infinity for comparison
        
        for (i = 1; i <= n; i++) {
            if (vis[i]) {  // Look for the edge connecting a visited node to an unvisited one
                for (j = 1; j <= n; j++) {
                    if (!vis[j] && cost[i][j] < min) {  // Choose the smallest edge
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        
        // Mark the selected node as visited and include the edge in the MST
        vis[v] = 1;
        printf("Edge %d: %d -> %d, cost = %d\n", ne++, u, v, min);
        mincost += min;
        
        // Set the cost of the used edge to infinity to avoid revisiting
        cost[u][v] = cost[v][u] = INF;
    }
    
    printf("Total cost of constructing the MST is: %d\n", mincost);
}

int main() {
    int i, j, n, cost[10][10];
    
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    
    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = INF;  // Replace 0 with infinity (INF) for non-edges
            }
        }
    }
    
    // Run Prim's algorithm
    prims(n, cost);
    
    return 0;
}
