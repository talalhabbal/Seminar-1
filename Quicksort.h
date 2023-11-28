#ifndef quicksort_h
#define quicksort_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define firstElement 1
#define random 2
#define medianOfThree 3
void quickSortIterative(int* array, int low, int high, int pivotMode);
void quickSortRecursive(int* array, int low, int high, int pivotMode);
double quickSortRunner(FILE *fptr, char mode, int inputSize, int pivotMode);
int partition(int* array, int low, int high, int pivotMode);
void swap(int *a, int *b);
int getPivot(int* array, int low, int high, int pivotMode);
#endif