#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int *e, int sizeE, int *d, int sizeD)
{
    int indexV = 0;
    int indexE = 0;
    int indexD = 0;

    while (indexE < sizeE && indexD < sizeD)
    {
        if (e[indexE] <= d[indexD])
        {
            v[indexV] = e[indexE];
            indexE++;
        }
        else
        {
            v[indexV] = d[indexD];
            indexD++;
        }
        indexV++;
    }
    while (indexE < sizeE)
    {
        v[indexV] = e[indexE];
        indexE++;
        indexV++;
    }
    while (indexD < sizeD)
    {
        v[indexV] = d[indexD];
        indexD++;
        indexV++;
    }
}

void mergeSort(int *v, int sizeV)
{
    if (sizeV > 1)
    {
        int middle = sizeV / 2;

        int sizeV1 = middle;
        int *v1 = (int *)malloc(sizeV1 * sizeof(int));
        for (int i = 0; i < middle; i++)
        {
            v1[i] = v[i];
        }

        int sizeV2 = sizeV - middle;
        int *v2 = (int *)malloc(sizeV2 * sizeof(int));
        for (int i = middle; i < sizeV; i++)
        {
            v2[i - middle] = v[i];
        }

        mergeSort(v1, sizeV1);
        mergeSort(v2, sizeV2);
        merge(v, v1, sizeV1, v2, sizeV2);

        free(v1);
        free(v2);
    }
}