#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the current element
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    int i, n, a[500000], randNum;
    double time;
    clock_t start, end;

    printf("-----SELECTION SORT--------\n");

    printf("Enter the total input size: ");
    scanf("%d", &n);

    // Generate and display the unsorted array
    printf("Unsorted array:\n");
    for (i = 0; i < n; i++) {
        randNum = rand() % 10000;
        a[i] = randNum;
        printf("%d\t", a[i]);
    }

    start = clock();

    // Perform selection sort
    selectionSort(a, n);

    end = clock();

    // Display the sorted array
    printf("\n\nThe sorted list:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }

    time = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("\nTime taken by SELECTION SORT: %lf milliseconds\n", time);

    return 0;
}
