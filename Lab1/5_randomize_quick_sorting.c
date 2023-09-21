#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void RanquickSort(int *arr,int f,int l);
int main()
{
    clock_t start, end;
    double time;
    printf("-----QUICK SORT--------\n");
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
    RanquickSort(arr,0,(size-1));
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

int partition(int *arr,int l, int r)
{
    int pivot = arr[r];
    int i = l-1;
    for(int j=l ; j<=(r-1);j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return (i+1);
}

int RanPartition(int *arr,int l,int r)
{
    int k;
    k = (l+(rand()%(r-l)));
    printf("%d is Random number is taken as random\n",k);
    swap(&arr[l], &arr[k]);
    return partition(arr, l, r);
}

void RanquickSort(int *arr,int l,int r)
{
    if(l<r)
    {
        int pi = RanPartition(arr,l,r);
        RanquickSort(arr,l,(pi-1));
        RanquickSort(arr,(pi+1),r);
    }
}