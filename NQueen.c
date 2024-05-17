#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 4 // Change N to the desired board size

int X[N+1]; // Solution array, X[i] represents the column position of the queen in the i-th row

bool place(int k, int i) {
    for (int j = 1; j < k; j++) {
        if (X[j] == i || abs(X[j] - i) == abs(j - k)) { // Check if the current position conflicts with any previous queen
            return false; // Conflict found, not a safe position
        }
    }
    return true; // No conflicts found, safe position
}

void NQueens(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) { // Check if it's safe to place a queen at position (k, i)
            X[k] = i; // Place the queen in the k-th row at column i
            if (k == n) { // Base case: All queens are placed
                printf("Solution: ");
                for (int j = 1; j <= n; j++) {
                    printf("%d ", X[j]);		
                }
                printf("\n");
            } else {
                NQueens(k + 1, n); // Recur for the next row
            }
        }
    }
}

int main() {
    NQueens(1, N); // Start with the first row
    return 0;
}

