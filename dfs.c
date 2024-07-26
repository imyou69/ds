#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n, a[10][10], visited[10];

void dfs(int u) {
    int v;
    visited[u] = 1;
    for (v = 1; v <= n; v++) {
        if (a[u][v] == 1 && visited[v] == 0) {
            dfs(v);
        }
    }
}

int main() {
    int i, j;
    printf("Enter the number of vertices of the graph: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix.....\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    for (i = 1; i <= n; i++) {
        visited[i] = 0;
    }
    
    for (i = 1; i <= n; i++) {
        dfs(i);
        for (j = 1; j <= n; j++) {
            if (visited[j] != 1) {
                printf("%d is not reachable from %d\n", j, i);
                printf("So graph is not connected\n");
                return 0;
            }
        }
        for (j = 1; j <= n; j++) {
            visited[j] = 0;
        }
    }
    
    printf("Graph is connected\n");
    return 0;
}
