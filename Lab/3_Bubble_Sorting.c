// Write a program to implement the Bubble sort algorithm.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void BubbleSort(int *arr,int *size);
int main()
{
    clock_t start, end;
    double time;
    printf("-----BUBBLE SORT--------\n");
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
    BubbleSort(arr,&size);
    end = clock();
    printf("\nSORTED ARRAY\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n\n");
    time=((double)(end-start)*1000000) / CLOCKS_PER_SEC;
    printf("Time=%lf micro", time);
}
void swap(int *first,int *second)
{
    int temp;
    temp=*first;
    *first=*second;
    *second=temp;
}
void BubbleSort(int *arr,int *size)
{
    int temp,counter=1;
    while (counter<*size)
    {
        for (int i = 0; i < *size-counter; i++)
        {
            if(arr[i]>arr[i+1])
            {
                swap(&arr[i],&arr[i+1]);
            }
        }
        counter++;
    }
}