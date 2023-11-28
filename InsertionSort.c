#include "InsertionSort.h"

void InsertionSortIterative(int* array, int size) {
    //i is the index we're at
    //j is the index before
    //temp is the value of the current index we're at
    int i, j, key;
    for(i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void InsertionSortRecursive(int* array, int size) {
    if(size <= 2) {
        return;
    }

    InsertionSortRecursive(array, size - 1);
    int key = array[size - 1];
    int j = size - 2;

    while(j >= 0 && array[j] > key) {
        array[j + 1] = array[j];
        j--;
    }
    array[j + 1] = key;
}
//This function is used to call the InsertionSort
//The mode can be used to run either the recursive
//Or iterative method with input size of 100 - 1,000,000
double InsertionSortRunner(FILE *fptr, char mode, int inputSize) {
    clock_t t;
    double time_taken;
    int* array;
    array = (int*)malloc(inputSize * sizeof(int));
    for(int i = 0; i < inputSize; i++) {
        fscanf(fptr, "%d", &array[i]);
    }
    t = clock();
    if(mode == 'i') {
        InsertionSortIterative(array, inputSize);
    }
    else if(mode == 'r') {
        InsertionSortRecursive(array, inputSize);
    }
    t = clock() - t;
    time_taken = (((double)t)/ CLOCKS_PER_SEC) * 1000; //time taken in ms
    printf("Time taken: %.1f ms\n", time_taken);
    free(array);
    fseek(fptr, 0, SEEK_SET);
    return time_taken;
}