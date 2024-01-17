#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int *arr, int size);
void swap(int *first, int *second);

int main() {
    clock_t start, end;
    double time;

    printf("-----SELECTION SORT--------\n");

    int size, arr[500000], num;

    printf("\nEnter size of array\n");
    scanf("%d", &size);

    printf("%d numbers\n", size);

    for (int i = 0; i < size; i++) {
        num = rand() % 10000;
        arr[i] = num;
    }

    start = clock();
    selectionSort(arr, size);
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

void selectionSort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}
