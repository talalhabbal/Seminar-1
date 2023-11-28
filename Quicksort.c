#include "Quicksort.h"

//Arg1 is the array
//arg2 is the index of the lower bound of the array
//arg3 is the index of the upper bound of the array
//arg4 is how we choose the pivot
int partition(int* array, int low, int high, int pivotMode) {
    //getPivot returns the index of the pivot based on way we want to choose the pivot
    int index = getPivot(array, low, high, pivotMode);
    if(index == -1) {
        exit(EXIT_FAILURE);
    }
    int pivotValue = array[index];
    swap(&pivotValue, &array[high]);
    int lp = low - 1;

    for(int rp = low; rp <= high; rp++) {
        if(array[rp] < array[high]) {
            lp++;
            swap(&array[lp], &array[rp]);
        }
    }
    swap(&array[lp + 1], &array[high]);
    return lp + 1;
}

//Arg1 is the array
//arg2 is the index of the lower bound of the array
//arg3 is the index of the upper bound of the array
//arg4 is how we choose the pivot
void quickSortRecursive(int* array, int low, int high, int pivotMode) {
    if(low < high) {
    int pivotIndex = partition(array, low, high, pivotMode);
    quickSortRecursive(array, low, pivotIndex - 1, pivotMode);
    quickSortRecursive(array, pivotIndex + 1, high, pivotMode);
    }
}

void quickSortIterative(int* array, int low, int high, int pivotMode) {
    int* stack = (int*)malloc((high + 1) * sizeof(int));
    int top = -1;
    stack[++top] = low;
    stack[++top] = high;
    while(top >= 0) {
        high = stack[top--];
        low = stack[top--];
        int pivotIndex = partition(array, low, high, pivotMode);
        if(pivotIndex - 1 > low) {
            stack[++top] = low;
            stack[++top] = pivotIndex - 1;
        }
        if(pivotIndex + 1 < high) {
            stack[++top] = pivotIndex + 1;
            stack[++top] = high;
        }
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

double quickSortRunner(FILE* fptr, char mode, int inputSize, int pivotMode) {
    clock_t t;
    double time_taken;
    int* array;
    array = (int*)malloc(inputSize * sizeof(int));
    for(int i = 0; i < inputSize; i++) {
        fscanf(fptr, "%d", &array[i]);
    }
    t = clock();
    if(mode == 'i') {
        quickSortIterative(array, 0, inputSize - 1, pivotMode);
    }
    else if(mode == 'r') {
        quickSortRecursive(array, 0, inputSize - 1, pivotMode);
    }
    t = clock() - t;
    time_taken = (((double)t)/ CLOCKS_PER_SEC) * 1000; //time taken in ms
    printf("Time taken: %.1f ms\n", time_taken);
    free(array);
    fseek(fptr, 0, SEEK_SET);
    return time_taken;
}

//Arg1 is the array
//arg2 is the index of the lower bound of the array
//arg3 is the index of the upper bound of the array
//arg4 is how we choose the pivot
int getPivot(int* array, int low, int high, int pivotMode) {
    switch (pivotMode)
    {
        case firstElement:
        {
            return low;
        }
        case random:
        {
            int num = rand() % (high - low) + low;
            return num;
        }
        case medianOfThree:
        {
            int lowValue = array[low];
            int highValue = array[high];
            int midValue = array[(high - low) / 2];
            if(lowValue > midValue) {
                if(midValue > highValue) {
                    return (high - low) / 2;
                }
                else if(lowValue > highValue) {
                    return high;
                }
                else {
                    return low;
                }
            }
            else {
                if(lowValue > highValue) {
                    return low;
                }
                else if(midValue > highValue) {
                    return high;
                }
                else {
                    return (high - low) / 2;
                }
            }
            break;
        }
        default:
        {
            return -1;
        }
    }
}