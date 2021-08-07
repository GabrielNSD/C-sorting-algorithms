#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <fstream>

#include "selectionSort.h"
#include "bubbleSort.h"
#include "insertionSort.h"
#include "mergeSort.h"
#include "quickSort.h"

using namespace std;

void testingFunction(int *arr, int size, void (*func)(int *, int), double *resultArray, int testCase)
{

    for (int i = 0; i < 30; i++)
    {
        switch (testCase)
        {
        case 1:
            populateArrayAscending(arr, size);
            break;
        case 2:
            break;
        case 3:
            populateArrayRandom(arr, size, i);

        default:
            break;
        }

        //populateArrayRandom(arr, size, i);

        double time_spent_TEST = 0.0;

        clock_t begin_TEST = clock();

        func(arr, size);

        clock_t end_TEST = clock();

        time_spent_TEST += (double)(end_TEST - begin_TEST) / CLOCKS_PER_SEC;

        resultArray[i] = time_spent_TEST;
    }
}

void testRun(int size)
{
    double resultsSelectionSortIP[30];
    double resultsBubbleSort[30];
    double resultsInsertionSort[30];
    double resultsMergeSort[30];
    double resultsQuickSort[30];
    double resultsQuickSortRandom[30];

    int *ssip = (int *)calloc(size, sizeof(int));

    testingFunction(ssip, size, &selectionSortIP, resultsSelectionSortIP, 1);

    free(ssip);

    cout << "media SSIP (tamanho " << size << "): " << meanTime(resultsSelectionSortIP, 30) << endl;

    int *bbs = (int *)calloc(size, sizeof(int));

    testingFunction(bbs, size, &bubbleSort, resultsBubbleSort, 1);

    free(bbs);

    cout << "media BBS (tamanho " << size << "): " << meanTime(resultsBubbleSort, 30) << endl;

    int *is = (int *)calloc(size, sizeof(int));

    testingFunction(is, size, &insertionSort, resultsInsertionSort, 1);

    free(is);

    cout << "media IS (tamanho " << size << "): " << meanTime(resultsInsertionSort, 30) << endl;

    int *ms = (int *)calloc(size, sizeof(int));

    testingFunction(ms, size, mergeSort, resultsMergeSort, 1);

    free(ms);

    cout << "media MS (tamanho " << size << "): " << meanTime(resultsMergeSort, 30) << endl;

    //inicio quick sort

    int *qs = (int *)calloc(size, sizeof(int));

    for (int i = 0; i < 30; i++)
    {
        populateArrayRandom(qs, size, i);
        double time_spent_QS = 0.0;

        clock_t begin_QS = clock();

        quickSort(qs, 0, size - 1);

        clock_t end_QS = clock();

        time_spent_QS += (double)(end_QS - begin_QS) / CLOCKS_PER_SEC;

        resultsQuickSort[i] = time_spent_QS;
    }
    free(qs);

    cout << "Media QS (tamanho " << size << "): " << meanTime(resultsQuickSort, 30) << endl;

    //fim quick sort

    //inicio quick sort random
    int *qsr = (int *)calloc(size, sizeof(int));

    for (int i = 0; i < 30; i++)
    {
        populateArrayRandom(qsr, size, i);
        double time_spent_QSR = 0.0;

        clock_t begin_QSR = clock();

        quickSortRandom(qsr, 0, size - 1);

        clock_t end_QSR = clock();

        time_spent_QSR += (double)(end_QSR - begin_QSR) / CLOCKS_PER_SEC;

        resultsQuickSortRandom[i] = time_spent_QSR;
    }
    free(qsr);

    cout << "Media QSR (tamanho " << size << "): " << meanTime(resultsQuickSortRandom, 30) << endl
         << endl;
}

int main()
{
    testRun(10);
    testRun(1000);
    testRun(100000);
    /* int size = 100000;
    double resultsSelectionSortIP[30];
    double resultsBubbleSort[30];
    double resultsInsertionSort[30];
    double resultsMergeSort[30];
    double resultsQuickSort[30];
    double resultsQuickSortRandom[30];

    int *ssip = (int *)calloc(size, sizeof(int));

    testingFunction(ssip, size, &selectionSortIP, resultsSelectionSortIP);

    free(ssip);

    cout << "media SSIP: " << meanTime(resultsSelectionSortIP, 30) << endl;

    int *bbs = (int *)calloc(size, sizeof(int));

    testingFunction(bbs, size, &bubbleSort, resultsBubbleSort);

    free(bbs);

    cout << "media BBS: " << meanTime(resultsBubbleSort, 30) << endl;

    int *is = (int *)calloc(size, sizeof(int));

    testingFunction(is, size, &insertionSort, resultsInsertionSort);

    free(is);

    cout << "media IS: " << meanTime(resultsInsertionSort, 30) << endl;

    int *ms = (int *)calloc(size, sizeof(int));

    testingFunction(ms, size, mergeSort, resultsMergeSort);

    free(ms);

    cout << "media MS: " << meanTime(resultsMergeSort, 30) << endl;

    //inicio quick sort

    int *qs = (int *)calloc(size, sizeof(int));

    for (int i = 0; i < 30; i++)
    {
        double time_spent_QS = 0.0;

        clock_t begin_QS = clock();

        quickSort(qs, 0, size - 1);

        clock_t end_QS = clock();

        time_spent_QS += (double)(end_QS - begin_QS) / CLOCKS_PER_SEC;

        resultsQuickSort[i] = time_spent_QS;
    }
    free(qs);

    cout << "Media QS: " << meanTime(resultsQuickSort, 30) << endl;

    //fim quick sort

    //inicio quick sort random
    int *qsr = (int *)calloc(size, sizeof(int));

    for (int i = 0; i < 30; i++)
    {
        double time_spent_QSR = 0.0;

        clock_t begin_QSR = clock();

        quickSortRandom(qsr, 0, size - 1);

        clock_t end_QSR = clock();

        time_spent_QSR += (double)(end_QSR - begin_QSR) / CLOCKS_PER_SEC;

        resultsQuickSortRandom[i] = time_spent_QSR;
    }
    free(qsr);

    cout << "Media QSR: " << meanTime(resultsQuickSortRandom, 30) << endl;

    //fim quick sort random
 */
    /* cout << "[";
    for (int i = 0; i < size; i++)
    {

        cout << original[i] << " ";
    }
    cout << "]";
    cout << endl;
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << qsr[i] << " ";
    }
    cout << "]"; */

    /* for (int i = 0; i < 30; i++)
    {
        cout << resultsSelectionSortIP[i] << endl;
    } */
}