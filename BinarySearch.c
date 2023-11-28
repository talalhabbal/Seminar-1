#include "Quicksort.h"
#include "BinarySearch.h"

double binarySearchRunner(FILE *fptr, int inputSize, int key) {
    clock_t t;
    int* array = (int*)malloc(inputSize * sizeof(int));
    readArrayFromFile(fptr, array, inputSize);
    quickSortIterative(array, 0, inputSize - 1, medianOfThree);
    t = clock();
    int result = binarySearch(array, 0, inputSize - 1, key);
    t = clock() - t;
    double time_taken = (((double)t)/ CLOCKS_PER_SEC) * 1000000; //time in microseconds
    printf("Time Taken: %.1f\n", time_taken);
    if(result != -1) {
        printf("The element was found at index: %d\n", result);
    }
    else {
        printf("Element was not found in the array\n");
    }
    fseek(fptr, 0, SEEK_SET);
    free(array);
    return time_taken;
}
//array - array to search through
//low - lower index of the array
//high - upper index of the array
//key - number to find in the array
//return the index of element if found, return -1 if not found
int binarySearch(int* array, int low, int high, int key) {
    if(high >= low) {
        int mid = low + (high - low) / 2;
        if(key == array[mid]) {
            return mid;
        }
        else if(key < array[mid]) {
            return binarySearch(array, low, mid - 1, key);
        }
        else if(key > array[mid]) {
            return binarySearch(array, mid + 1, high, key);
        }
    }
    return -1;
}

void readArrayFromFile(FILE *fptr, int* array, int inputSize) {
    for(int i = 0; i < inputSize; i++) {
        fscanf(fptr, "%d", &array[i]);
    }
}
