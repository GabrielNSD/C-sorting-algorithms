#include <stdio.h>
#include <stdlib.h>

void countingSort(int **v, int size)
{
    //descobrir menor valor e maior valor
    int iSmallerSize = 0;
    int iBiggerSize = 0;

    for (int i = 0; i < size; i++)
    {
        if ((*v)[i] < (*v)[iSmallerSize])
        {
            iSmallerSize = i;
        }
        if ((*v)[i] > (*v)[iBiggerSize])
        {
            iBiggerSize = i;
        }
    }
    // criar novo array contagem com  (vBigger-vSmaller + 1)
    int countSize = (*v)[iBiggerSize] - (*v)[iSmallerSize] + 1;
    int *counting = (int *)calloc(countSize, sizeof(int));

    for (int i = 0; i < size; i++)
    {
        int indexInCounting = (*v)[i] - (*v)[iSmallerSize];
        counting[indexInCounting]++;
    }

    for (int i = 1; i < countSize; i++)
    {
        counting[i] += counting[i - 1];
    }

    int *sorted = (int *)malloc(size * sizeof(int));
    bool *added = (bool *)calloc(size, sizeof(bool));

    for (int i = 0; i < size; i++)
    {
        //int temp = v[i];
        int sortedIndex = counting[(*v)[i] - (*v)[iSmallerSize]] - 1;
        while (added[sortedIndex])
            sortedIndex--;
        sorted[sortedIndex] = (*v)[i];
    }

    (*v) = sorted;

    //free(added);
    //free(counting);
    //free(sorted);
}