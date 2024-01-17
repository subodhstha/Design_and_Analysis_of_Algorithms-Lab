#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int *arr, int l, int r);
void swap(int *first, int *second);
int partition(int *arr, int l, int r);

int main() {
    clock_t start, end;
    double time;

    printf("-----QUICK SORT--------\n");

    int size, arr[500000], num;

    printf("\nEnter size of array\n");
    scanf("%d", &size);

    printf("%d numbers\n", size);

    for (int i = 0; i < size; i++) {
        num = rand() % 10000;
        arr[i] = num;
    }

    start = clock();
    quickSort(arr, 0, (size - 1));
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

void quickSort(int *arr, int l, int r) {
    if (l < r) {
        int pi = partition(arr, l, r);
        quickSort(arr, l, (pi - 1));
        quickSort(arr, (pi + 1), r);
    }
}
