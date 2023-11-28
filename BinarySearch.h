#ifndef binarySearch_h
#define binarySearch_h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int* array, int low, int high, int key);
void readArrayFromFile(FILE *fptr,int* array, int inputSize);
double binarySearchRunner(FILE *fptr, int inputSize, int key);

#endif