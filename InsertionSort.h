#ifndef insertionsort_h
#define insertionsort_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InsertionSortIterative(int* array, int size);
void InsertionSortRecursive(int* array, int size);
double InsertionSortRunner(FILE *fptr, char mode, int inputSize);
#endif