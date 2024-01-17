#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 1000

int max(int a, int b) 
{
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) 
{
    int i, w;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main() 
{
    printf("Algorithm: 0/1 Knapsack Dynamic Programming\n");

    int i, n, val[MAX_ITEMS], wt[MAX_ITEMS], W;
    int randNum1, randNum2;
    double time;
    clock_t start, end;

    printf("Enter number of items:");
    scanf("%d", &n);

    if (n > MAX_ITEMS) 
    {
        printf("Error: Number of items exceeds the maximum limit.\n");
        return 1;
    }

    printf("Enter size of knapsack:");
    scanf("%d", &W);

    start = clock();

    printf("Enter the weight and value for each item:\n");

    for (i = 0; i < n; i++) 
    {
        randNum1 = rand() % 1000;
        wt[i] = randNum1;
        randNum2 = rand() % 1000;
        val[i] = randNum2;
        printf("Item %d: Weight: %d, Value: %d\n", i + 1, wt[i], val[i]);
    }

    printf("Maximum profit:%d", knapsack(W, wt, val, n));

    end = clock();
    time = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("\nTime taken: %lf milliseconds\n", time);

    return 0;
}
