#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void divide(int arr[],int si,int ei);
int main()
{
    clock_t start, end;
    double time;
    printf("-----Merge SORT--------\n");
    int size, arr[500000], num;
    printf("\nEnter size of array\n");
    scanf("%d",&size);
    printf("\nEnter %d numbers\n",size);
    for (int i = 0; i < size; i++)
    {
        num = (rand()%10000);
        arr[i] = num;
    }
    start = clock();
    divide(arr,0,(size-1));
    end = clock();
    divide(arr,0,(size-1));
    printf("\nSORTED ARRAY\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n\n");
    time = ((double)(end-start)*10000) / CLOCKS_PER_SEC;
    printf("Time=%lf micro", time);
}

void conquor(int arr[], int si, int mid, int ei)
{
    int n1 = mid - si + 1;
    int n2 = ei - mid;
    int L[n1], M[n2];

    //copy two divided arr si->mid and mid+1->ei
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[si + i];
    }
    for (int j = 0; j < n2; j++)
    {
        M[j] = arr[mid + 1 + j];
    }
    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = si;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void divide(int arr[],int si,int ei)
{
    if(si>=ei)
    {
        return;
    }
    int mid = si+(ei-si)/2;   // In (si+ei)/2, (si+ei) can be greater than int 's casiacity
    divide(arr,si,mid);
    divide(arr,mid+1,ei );
    conquor(arr, si, mid, ei);
}