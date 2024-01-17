#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionSort(int *arr, int *size);
void swap(int *first, int *second);

int main() {
    clock_t start, end;
    double time;

    printf("-----INSERTION SORT--------\n");

    int size, arr[500000], num;

    printf("\nEnter size of array\n");
    scanf("%d", &size);

    printf("%d numbers\n", size);

    for (int i = 0; i < size; i++) {
        num = (rand() % 10000);
        arr[i] = num;
    }

    start = clock();
    insertionSort(arr, &size);
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

void insertionSort(int *arr, int *size) {
    for (int i = 1; i < *size; i++) {
        int current = arr[i], j = i - 1;

        while (arr[j] >= current && j >= 0) {
            swap(&arr[j], &arr[j + 1]);
            j--;
        }

        arr[j + 1] = current;
    }
}
