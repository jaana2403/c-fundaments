#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to perform DFS and store the topological sort order in a stack
void dfs(int node, int vis[], int* stack, int* stack_index, int adj[][MAX], int V) {
    vis[node] = 1;
    for (int i = 0; i < V; i++) {
        if (adj[node][i] && !vis[i]) {
            dfs(i, vis, stack, stack_index, adj, V);
        }
    }
    stack[(*stack_index)++] = node; // Push node onto stack
}

// Function to return the topological order of vertices
void topoSort(int V, int adj[][MAX], int result[]) {
    int vis[V];
    for (int i = 0; i < V; i++) {
        vis[i] = 0; // Initialize all vertices as unvisited
    }
    
    int stack[MAX];
    int stack_index = 0;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, vis, stack, &stack_index, adj, V);
        }
    }

    // Pop from stack to result array
    for (int i = 0; i < stack_index; i++) {
        result[i] = stack[stack_index - i - 1];
    }
}

int main() {
    int V, E;

    // Input the number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    int adj[MAX][MAX] = {0}; // Initialize the adjacency matrix with 0s

    // Input the edges of the graph
    printf("Enter the edges (format: start_vertex end_vertex):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // Directed edge from u to v
    }

    int result[MAX];
    
    topoSort(V, adj, result);

    // Print topological order
    printf("Topological Sort Order: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
