#include <stdio.h>
#include <stdlib.h>
#include<iostream>

using namespace std;

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

int partitionRandom(int *v, int beg, int end){
    int random = beg + rand()%(end-beg);
    //cout << "pivo: " << random << endl; 

    swap(v, random, end);

    return partition(v, beg,end);
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
