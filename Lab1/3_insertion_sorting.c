// Write a program to implement the Insertion sort algorithm.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void InsertionSort(int *arr,int *size);
int main()
{
    clock_t start, end;
    double time;
    printf("-----INSERTION SORT--------\n");
    int size, arr[500000], num;
    printf("\nEnter size of array\n");
    scanf("%d",&size);
    printf("%d numbers\n",size);
    for (int i = 0; i < size; i++)
    {
        num = (rand()%10000);
        arr[i] = num;
    }
    start = clock();
    InsertionSort(arr,&size);
    end = clock();
    printf("\nSORTED ARRAY\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n\n");
    time=((double)(end-start)*10000) / CLOCKS_PER_SEC;
    printf("Time=%lf micro", time);
}

void swap(int *first,int *second)
{
    int temp;
    temp=*first;
    *first=*second;
    *second=temp;
}

void InsertionSort(int *arr,int *size)
{
    for (int i = 1; i < *size; i++)
    {
        int current = arr[i] ,j = i-1;
        while (arr[j] >= current && j>=0)
        {
            swap(&arr[j],&arr[j+1]);
            j--;
        }
        arr[j+1]=current;
    }
}