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
#include "countingSort.h"

using namespace std;

void testingFunction(int *arr, int size, void (*func)(int *, int), double *resultArray, int testCase)
{

    for (int i = 0; i < 30; i++)
    {
        if (testCase == 1)
        {
            populateArrayAscending(arr, size);
        }
        else if (testCase == 2)
        {
            populateArrayDescending(arr, size);
        }
        else if (testCase == 3)
        {
            populateArrayRandom(arr, size, i);
        }

        double time_spent_TEST = 0.0;

        clock_t begin_TEST = clock();

        func(arr, size);

        clock_t end_TEST = clock();

        time_spent_TEST += (double)(end_TEST - begin_TEST) / CLOCKS_PER_SEC;

        resultArray[i] = time_spent_TEST;
    }
}

void testingCountingSort(int *arr, int size, void (*func)(int **, int), double *resultArray, int testCase)
{

    for (int i = 0; i < 30; i++)
    {
        if (testCase == 1)
        {
            populateArrayAscending(arr, size);
        }
        else if (testCase == 2)
        {
            populateArrayDescending(arr, size);
        }
        else if (testCase == 3)
        {
            populateArrayRandom(arr, size, i);
        }

        double time_spent_TEST = 0.0;

        clock_t begin_TEST = clock();

        func(&arr, size);

        clock_t end_TEST = clock();

        time_spent_TEST += (double)(end_TEST - begin_TEST) / CLOCKS_PER_SEC;

        resultArray[i] = time_spent_TEST;
    }
}

void testingQuickSort(int *arr, int size, void (*func)(int *, int, int), double *resultArray, int testCase)
{
    for (int i = 0; i < 30; i++)
    {
        if (testCase == 1)
        {
            populateArrayAscending(arr, size);
        }
        else if (testCase == 2)
        {
            populateArrayDescending(arr, size);
        }
        else if (testCase == 3)
        {
            populateArrayRandom(arr, size, i);
        }

        double time_spent_TCS = 0.0;

        clock_t begin_TCS = clock();

        func(arr, 0, size - 1);

        clock_t end_TCS = clock();

        time_spent_TCS += (double)(end_TCS - begin_TCS) / CLOCKS_PER_SEC;

        resultArray[i] = time_spent_TCS;
    }
}

void testRun(int size, int testCase)
{
    double resultsSelectionSortIP[30];
    double resultsBubbleSort[30];
    double resultsInsertionSort[30];
    double resultsMergeSort[30];
    double resultsCountingSort[30];
    double resultsQuickSort[30];
    double resultsQuickSortRandom[30];

    string fileName = "Arrays tamanho " + to_string(size) + ".txt";

    ofstream f;
    f.open(fileName);
    f << "\n";

    int *ssip = (int *)calloc(size, sizeof(int));

    testingFunction(ssip, size, &selectionSortIP, resultsSelectionSortIP, testCase);

    free(ssip);

    f << "Media SSIP (tamanho " << size << "): " << meanTime(resultsSelectionSortIP, 30) << endl;

    f << "Mediana SSIP (tamanho " << size << "): " << medianTime(resultsSelectionSortIP, 30) << endl;

    int *bbs = (int *)calloc(size, sizeof(int));

    testingFunction(bbs, size, &bubbleSort, resultsBubbleSort, testCase);

    free(bbs);

    f << "Media BBS (tamanho " << size << "): " << meanTime(resultsBubbleSort, 30) << endl;
    f << "Mediana BBS (tamanho " << size << "): " << medianTime(resultsBubbleSort, 30) << endl;

    int *is = (int *)calloc(size, sizeof(int));

    testingFunction(is, size, &insertionSort, resultsInsertionSort, testCase);

    free(is);

    f << "Media IS (tamanho " << size << "): " << meanTime(resultsInsertionSort, 30) << endl;
    f << "Mediana IS (tamanho " << size << "): " << medianTime(resultsInsertionSort, 30) << endl;

    int *ms = (int *)calloc(size, sizeof(int));

    testingFunction(ms, size, mergeSort, resultsMergeSort, testCase);

    free(ms);

    f << "Media MS (tamanho " << size << "): " << meanTime(resultsMergeSort, 30) << endl;
    f << "Mediana MS (tamanho " << size << "): " << medianTime(resultsMergeSort, 30) << endl;

    int *cs = (int *)calloc(size, sizeof(int));

    testingCountingSort(cs, size, &countingSort, resultsCountingSort, testCase);

    free(cs);

    f << "Media CS (tamanho " << size << "): " << meanTime(resultsCountingSort, 30) << endl;
    f << "Mediana CS (tamanho " << size << "): " << medianTime(resultsCountingSort, 30) << endl;

    //inicio quick sort

    int *qs = (int *)calloc(size, sizeof(int));

    testingQuickSort(qs, size, &quickSort, resultsQuickSort, testCase);

    free(qs);

    f << "Media QS (tamanho " << size << "): " << meanTime(resultsQuickSort, 30) << endl;
    f << "Mediana QS (tamanho " << size << "): " << medianTime(resultsQuickSort, 30) << endl;

    //fim quick sort

    //inicio quick sort random
    int *qsr = (int *)calloc(size, sizeof(int));

    testingQuickSort(qsr, size, &quickSortRandom, resultsQuickSortRandom, testCase);

    free(qsr);

    f << "Media QSR (tamanho " << size << "): " << meanTime(resultsQuickSortRandom, 30) << endl;
    f << "Mediana QSR (tamanho " << size << "): " << medianTime(resultsQuickSortRandom, 30) << endl
      << endl;

    f.close();
}

int main()
{

    cout << "Executando Testes com array ordenado" << endl;
    testRun(10, 1);
    testRun(1000, 1);
    testRun(100000, 1);

    cout << endl;

    cout << "Executando testes com array em ordem decrescente" << endl;
    testRun(10, 2);
    testRun(1000, 2);
    testRun(100000, 2);

    cout << endl;

    cout << "Executando testes com array aleatório" << endl;
    testRun(10, 3);
    testRun(1000, 3);
    testRun(100000, 3);

    cout << endl;

    cout << "Fim da execucao" << endl;
}