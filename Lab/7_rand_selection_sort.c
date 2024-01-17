#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomized_partition(int a[], int low, int high) {
    int pivot_index = low + rand() % (high - low + 1);
    int temp = a[pivot_index];
    a[pivot_index] = a[high];
    a[high] = temp;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] <= a[high]) {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;
    return i + 1;
}

void randomized_selection_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int k = i; // Find the i-th smallest element
        int pos = randomized_partition(a, k, n - 1);
        if (pos != k) {
            int temp = a[k];
            a[k] = a[pos];
            a[pos] = temp;
        }
    }
}

int main() {
    int i, n, a[500000], randNum;
    double time;
    clock_t start, end;

    printf("-----RANDOMIZED SELECTION SORT--------\n");

    printf("Enter the total input size: ");
    scanf("%d", &n);

    start = clock();

    // Generate and display the unsorted array
    printf("Unsorted array:\n");
    for (i = 0; i < n; i++) {
        randNum = rand() % 10000;
        a[i] = randNum;
        printf("%d\t", a[i]);
    }

    // Perform Randomized Selection Sort
    randomized_selection_sort(a, n);

    // Display the sorted array
    printf("\n\nThe sorted list:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }

    end = clock();
    time = ((double)(end - start) * 1000) / CLOCKS_PER_SEC;
    printf("\nTime taken by RANDOMIZED SELECTION SORT: %lf milliseconds\n", time);

    return 0;
}
