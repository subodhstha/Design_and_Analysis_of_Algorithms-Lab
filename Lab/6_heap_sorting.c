#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int heap[], int n, int parent) {
    int largest = parent;
    int leftChild = 2 * parent + 1;
    int rightChild = 2 * parent + 2;

    if (leftChild < n && heap[leftChild] > heap[largest])
        largest = leftChild;

    if (rightChild < n && heap[rightChild] > heap[largest])
        largest = rightChild;

    if (largest != parent) {
        // Swap and continue heapifying
        int temp = heap[parent];
        heap[parent] = heap[largest];
        heap[largest] = temp;
        heapify(heap, n, largest);
    }
}

void heapSort(int heap[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(heap, n, i);
    }

    // Extract elements one by one from the heap
    for (int i = n - 1; i >= 0; i--) {
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;

        heapify(heap, i, 0);
    }
}

int main() {
    int heap[500000], no, i, randNum;
    double time;
    clock_t start, end;

    printf("-----HEAP SORT--------\n");

    printf("\nEnter the number of elements: ");
    scanf("%d", &no);

    start = clock();
    for (i = 0; i < no; i++) {
        randNum = (rand() % 10000);
        heap[i] = randNum;
    }

    // Perform Heap Sort
    heapSort(heap, no);

    printf("\nSorted array: ");
    for (i = 0; i < no; i++) {
        printf("%d\t", heap[i]);
    }

    end = clock();
    time = ((double)(end - start) * 1000000) / CLOCKS_PER_SEC;
    printf("\nTime=%lf microseconds", time);

    return 0;
}
