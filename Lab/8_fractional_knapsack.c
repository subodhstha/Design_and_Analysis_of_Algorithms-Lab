#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void knapsack(int n, float weight[], float profit[], float capacity)
{
    float x[20], tp = 0;
    int i, j, u;
    u = capacity;
    for (i = 0; i < n; i++) 
    {
        x[i] = 0.0;
    }
    for (i = 0; i < n; i++) {
        if (weight[i] > u)
            {
                break;
            }
        else
        {
            x[i] = 1.0;
            tp = tp + profit[i];
            u = u - weight[i];
        }
    }
    if (i < n) 
    {
        {
            x[i] = u / weight[i];
        }
    }
    tp = tp + (x[i] * profit[i]);
    printf("\nMaximum profit using Fractional Knapsack is: %f", tp);
}

int main() 
{
    printf("-----Fractional Knapsack--------\n");
    float weight[1000], profit[1000], capacity;
    int n, i, j, randNum1, randNum2;
    float ratio[1000], temp;
    double time;
    clock_t start, end;

    printf("Enter the number of objects: ");
    scanf("%d", &n);
    printf("Enter the capacity of knapsack: ");
    scanf("%f", &capacity);

    start = clock();
    for (i = 0; i < n; i++) 
    {
        randNum1 = (rand() % 1000);
        weight[i] = randNum1;
        randNum2 = (rand() % 1000);
        profit[i] = randNum2;
        printf("Object %d - Weight: %f, Profit: %f\n", i + 1, weight[i], profit[i]);
    }

    // Sorting based on profit-to-weight ratio in descending order
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;
                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    knapsack(n, weight, profit, capacity);
    end = clock();
    time = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("\nTime taken: %lf milliseconds", time);

    return 0;
}
