#include <stdio.h>

#define INF 999
#define MAX 10

int parent[MAX];

// Function to find the representative of a set
int find(int i) {
    while (parent[i]) {
        i = parent[i];
    }
    return i;
}

// Function to implement Kruskal's algorithm
void kruskal(int cost[MAX][MAX], int n) {
    int mincost = 0, ne = 1;  // Number of edges in MST
    int a, b, u, v, min;

    // Initialize parent array
    for (int i = 0; i < MAX; i++) {
        parent[i] = 0;
    }

    printf("\nThe edges of the minimum spanning tree are: \n");
    
    // Continue until we have n-1 edges in MST
    while (ne < n) {
        min = INF;
        // Find the minimum cost edge
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        // Find the representatives of the sets
        u = find(u);
        v = find(v);

        // If they are in different sets, include this edge in MST
        if (u != v) {
            printf("%d edge(%d,%d)=%d\n", ne++, a, b, min);
            mincost += min;
            parent[v] = u;
        }

        // Remove the edge from consideration
        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nThe minimum cost of spanning tree is %d\n", mincost);
}

int main() {
    int cost[MAX][MAX];
    int n;

    printf("Enter the number of vertices of the graph \n");
    scanf("%d", &n);

    printf("Enter the cost matrix\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = INF;
            }
        }
    }

    kruskal(cost, n);

    return 0;
}
