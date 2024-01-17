#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int MatrixChainMultiplication(int p[], size_t n);

int main() {
    printf("Algorithm: Matrix Chain Multiplication using Dynamic Programming\n");

    size_t n, i;
    double time;
    clock_t start, end;

    printf("Enter number of matrices\n");
    scanf("%zu", &n);
    n++; // Adjust for array size
    int arr[n];

    printf("Enter dimensions\n");
    start = clock();
    for (i = 0; i < n; i++) {
        printf("Enter d%zu: ", i);
        scanf("%d", &arr[i]);
    }

    // Calculate and display minimum cost
    printf("Minimum number of multiplications: %d\n", MatrixChainMultiplication(arr, n));

    end = clock();
    time = ((double)(end - start) + 1000) / CLOCKS_PER_SEC;
    printf("Time taken: %lf milliseconds\n", time);

    return 0;
}

int MatrixChainMultiplication(int p[], size_t n) {
    int m[n][n];
    size_t i, j, k, L, q;

    for (i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    return m[1][n - 1];
}
