#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int partition(int *v, int beg, int end)
{
    int pIndex = beg;
    int pivot = v[end];
    for (int i = beg; i < end; i++)
    {
        if (v[i] <= pivot)
        {
            swap(v, i, pIndex);
            pIndex++;
        }
    }

    swap(v, pIndex, end);
    return pIndex;
}

/* int partition(int *arr, int low, int high)
{
    // pivot
    int pivot = arr[high];

    // Index of smaller element
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller
        // than or equal to pivot
        if (arr[j] <= pivot)
        {

            // increment index of
            // smaller element
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return (i + 1);
} */

void quickSort(int *v, int beg, int end)
{
    //cout << end << endl;
    if (end > beg)
    {
        int indexPivot = partition(v, beg, end);
        quickSort(v, beg, indexPivot - 1);
        quickSort(v, indexPivot + 1, end);
    }
}

/* int partitionRandom(int *v, int beg, int end){
    int pIndex = beg;
    int pivot = v[beg + rand() % (end-beg)];

    for(int i= beg; i<end; i++){
        if(v[i] <= pivot)
        {
            swap(v, i, pIndex);
            pIndex++;
        }
    }
    swap(v,pIndex,end);
    return pIndex;
} */

int partitionRandom(int *v, int beg, int end)
{
    int random = beg + rand() % (end - beg);
    //cout << "pivo: " << random << endl;

    swap(v, random, end);

    return partition(v, beg, end);
}

void quickSortRandom(int *v, int beg, int end)
{
    if (end > beg)
    {
        int indexPivot = partitionRandom(v, beg, end);
        //cout << "AAA: " << indexPivot << endl;
        quickSortRandom(v, beg, indexPivot - 1);
        quickSortRandom(v, indexPivot + 1, end);
    }
}
