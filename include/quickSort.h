#include <stdio.h>

int partition(int *v, int ini, int end)
{
    int pIndex = ini;
    int pivot = v[end];
    for (int i = ini; i < end; i++)
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

void quickSort(int *v, int ini, int end)
{
    if (end > ini)
    {
        int indexPivot = partition(v, ini, end);
        quickSort(v, ini, indexPivot - 1);
        quickSort(v, indexPivot + 1, end);
    }
}