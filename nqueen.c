#include <stdio.h>
#include <stdlib.h> // For abs() function

#define MAX 10

int x[MAX];

// Function to check if a queen can be placed at position (k, i)
int place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return 0; // Cannot place queen at (k, i)
        }
    }
    return 1; // Can place queen at (k, i)
}

// Function to solve the N-Queens problem
void nqueens(int k, int n) {
    if (k > n) {
        // All queens are placed, print the solution
        printf("\nSolution:\n");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (x[i] == j) {
                    printf("Q%d\t", i);
                } else {
                    printf("*\t");
                }
            }
            printf("\n");
        }
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i;
            nqueens(k + 1, n); // Recursive call to place the next queen
        }
    }
}

int main() {
    int n;

    printf("\nEnter the number of queens: ");
    scanf("%d", &n);

    if (n == 0 || n == 2 || n == 3) {
        printf("No solutions for %d queens.\n", n);
    } else {
        nqueens(1, n);
    }

    return 0;
}
