#ifndef main_h
#define main_h

#define FALSE 0
#define TRUE 1
#define InsertionSort 1
#define Quicksort 2
#define TestRun 3
#define BinarySearch 4
#define BinarySearchTest 5
#define Exit 6
#define firstElement 1
#define random 2
#define medianOfThree 3
int printMenu();
int getInputSize();
char getMode();
int getPivotMode();
int getKey();
void menuOption(int choice, FILE *fptr);
void printArray(double* array, int size);
void quickSortTest(FILE *fptr);
void insertionSortTest(FILE *fptr);
void binarySearchTest(FILE *fptr);
#endif