#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomizedQuickSort(int *arr, int l, int r);
void swap(int *first, int *second);
int randomizedPartition(int *arr, int l, int r);

int main() {
    clock_t start, end;
    double time;

    printf("-----RANDOMIZED QUICK SORT--------\n");

    int size, arr[500000], num;

    printf("\nEnter size of array\n");
    scanf("%d", &size);

    printf("%d numbers\n", size);

    for (int i = 0; i < size; i++) {
        num = rand() % 10000;
        arr[i] = num;
    }

    start = clock();
    randomizedQuickSort(arr, 0, (size - 1));
    end = clock();

    printf("\nSORTED ARRAY\n");

    for (int i = 0; i < size; i++) {
        printf("%d  ", arr[i]);
    }

    printf("\n\n");
    time = ((double)(end - start) * 1000000) / CLOCKS_PER_SEC;
    printf("Time=%lf micro", time);

    return 0;
}

void swap(int *first, int *second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}

int partition(int *arr, int l, int r) {
    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j <= (r - 1); j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[r]);
    return (i + 1);
}

int randomizedPartition(int *arr, int l, int r) {
    int k = (l + (rand() % (r - l + 1)));
    swap(&arr[l], &arr[k]);
    return partition(arr, l, r);
}

void randomizedQuickSort(int *arr, int l, int r) {
    if (l < r) {
        int pi = randomizedPartition(arr, l, r);
        randomizedQuickSort(arr, l, (pi - 1));
        randomizedQuickSort(arr, (pi + 1), r);
    }
}