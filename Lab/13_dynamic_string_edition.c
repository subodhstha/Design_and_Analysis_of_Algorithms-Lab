#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 100

int min(int x, int y, int z);

int editDistDP(char str1[], char str2[], int m, int n);

int main() {
    printf("Algorithm: Minimum Edit Distance using Dynamic Programming\n");

    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    double time;
    clock_t start = clock();

    printf("Enter first string\n");
    scanf("%99s", str1);  // Assuming MAX_LENGTH is 100

    printf("Enter second string\n");
    scanf("%99s", str2);

    // Calculate and display minimum cost
    int m = strlen(str1);
    int n = strlen(str2);
    printf("Minimum number of edits: %d\n", editDistDP(str1, str2, m, n));

    clock_t end = clock();
    time = ((double)(end - start) + 1000) / CLOCKS_PER_SEC;
    printf("Time taken: %lf milliseconds\n", time);

    return 0;
}

int min(int x, int y, int z) {
    return x < y ? (x < z ? x : z) : (y < z ? y : z);
}

int editDistDP(char str1[], char str2[], int m, int n) {
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }

    return dp[m][n];
}
