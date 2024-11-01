#include <stdio.h>

void dijkstra(int n, int cost[10][10], int s, int dist[10]) {
    int vis[10], count = 1, min, v;
    for (int i = 1; i <= n; i++) {
        vis[i] = 0; // Initialize all vertices as unvisited
        dist[i] = cost[s][i]; // Initialize distances with cost from the source
    }

    vis[s] = 1; // Mark the source as visited
    dist[s] = 0; // Distance from source to itself is 0

    while (count < n) { // Loop until all nodes are processed
        min = 999;
        for (int i = 1; i <= n; i++) {
            if (dist[i] < min && !vis[i]) { // Find the unvisited node with the smallest distance
                min = dist[i];
                v = i;
            }
        }

        vis[v] = 1; // Mark the selected node as visited
        count++;    // Increment the count of visited nodes

        // Update distances of adjacent vertices of the selected vertex
        for (int i = 1; i <= n; i++) 
            if (!vis[i] && dist[i] > dist[v] + cost[v][i]) 
                dist[i] = dist[v] + cost[v][i];
    }
}

int main() {
    int n, s, cost[10][10], dist[10];

    printf("\nRead the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j) // Set cost to 999 for non-edges
                cost[i][j] = 999;
        }
    }

    printf("\nEnter the source node: ");
    scanf("%d", &s);

    dijkstra(n, cost, s, dist);

    printf("\nShortest distances from node %d are:\n", s);
    for (int i = 1; i <= n; i++) {
        if (i != s)
            printf("%d -> %d = %d\n", s, i, dist[i]);
    }

    return 0;
}
