#include "InsertionSort.h"
#include "Quicksort.h"
#include "main.h"
#include "BinarySearch.h"

int main() {
    srand(time(NULL));
    FILE *fptr = fopen("numbers.txt", "r");
    while (TRUE)
    {
        int choice = printMenu();
        menuOption(choice, fptr);
    }
    fclose(fptr);
    return 0;
}

int printMenu() {
    int choice;
    do
    {
        printf("\n");
        printf("Choose an algorithm to run: \n");
        printf("1. InsertionSort\n");
        printf("2. Quicksort\n");
        printf("3. Test Run Algorithms\n");
        printf("4. Binary Search\n");
        printf("5. Binary Search Test\n");
        printf("6. Exit\n");
        printf("Your choice >> ");
        scanf("%d", &choice);
    } while (choice <= 0 || choice >= 7);
    fflush(stdin);
    return choice;
}

void menuOption(int choice, FILE *fptr) {
    int inputSize;
    char mode;
    int pivotMode;
    int key;
    switch(choice)
    {
    case InsertionSort:
        inputSize = getInputSize();
        mode = getMode();
        InsertionSortRunner(fptr, mode, inputSize);
        break;
    case Quicksort:
        pivotMode = getPivotMode();
        inputSize = getInputSize();
        mode = getMode();
        quickSortRunner(fptr, mode, inputSize, pivotMode);
        break;
    case TestRun:
        printf("Testing Quicksort...\n");
        quickSortTest(fptr);
        printf("QuickSort Test complete...\n");
        printf("Testing InsertionSort...\n");
        insertionSortTest(fptr);
        printf("InsertionSort Test complete...\n");
        break;
    case BinarySearch:
        inputSize = getInputSize();
        key = getKey();
        binarySearchRunner(fptr, inputSize, key);
        break;
    case BinarySearchTest:
        printf("Testing Binary Search...\n");
        binarySearchTest(fptr);
        printf("Binary Search Test complete...\n");
        break;
    case Exit:
        printf("Thank you for using this algorithm app! <3");
        exit(EXIT_SUCCESS);
    default:
        break;
    }
}

int getInputSize() {
    int inputSize;
    printf("Set the input size >> ");
    scanf("%d", &inputSize);
    fflush(stdin);
    return inputSize;
}

int getKey() {
    int key;
    printf("Enter Number to find (Key) >> ");
    scanf("%d", &key);
    fflush(stdin);
    return key;
}

char getMode() {
    char mode;
    printf("Which Algorithm do you want to run? i - Iterative | r - Recursive >> ");
    scanf("%c", &mode);
    fflush(stdin);
    return mode;
}

int getPivotMode() {
    int pivotMode;
    printf("What pivot should be used?\n");
    printf("1. Pivot at first element\n");
    printf("2. Random pivot\n");
    printf("3. Median of three pivot\n");
    printf("Your choice >> ");
    scanf("%d", &pivotMode);
    printf("\n");
    fflush(stdin);
    return pivotMode;
}

void binarySearchTest(FILE *fptr) {
    int arraySize = 50;
    int index = 0;
    long* binarySearchArray = (long*)malloc(arraySize * sizeof(double));
    if(binarySearchArray == NULL) {
        printf("Error Allocating memory.. (BinarySearch)\n");
        exit(EXIT_FAILURE);
    }
    for(int inputSize = 100; inputSize <= 1000000; inputSize *= 10) {
        printf("Input Size: %d\n", inputSize);
        for(int i = 0; i < 10; i++) {
            printf("Iteration: %d\n", i + 1);
            int key = rand() % 99 + 1;
            binarySearchArray[index] = binarySearchRunner(fptr, inputSize, key);
            index++;
        }
    }
    printf("Done testing...\n");
    fprintf(stderr, "BinarySearch: ");

    // printArray(binarySearchArray, arraySize);

    fflush(stderr);

    free(binarySearchArray);
}

void quickSortTest(FILE *fptr) {
    int arraySize = 50;
    int index = 0;
    double* RquickSortFirstElementArray = (double*)malloc(arraySize * sizeof(double));
    double* RquickSortRandomArray = (double*)malloc(arraySize * sizeof(double));
    double* RquickSortMedianArray = (double*)malloc(arraySize * sizeof(double));
    double* IquickSortFirstElementArray = (double*)malloc(arraySize * sizeof(double));
    double* IquickSortRandomArray = (double*)malloc(arraySize * sizeof(double));
    double* IquickSortMedianArray = (double*)malloc(arraySize * sizeof(double));
    if((RquickSortFirstElementArray || RquickSortRandomArray || RquickSortMedianArray
    || IquickSortFirstElementArray || IquickSortRandomArray || IquickSortMedianArray) == NULL) {
        printf("Error allocating memory..(QuickSort)\n");
        exit(EXIT_FAILURE);
    }
    for(int inputSize = 100; inputSize <= 1000000; inputSize *= 10) {
        for(int i = 0; i < 10; i++) {
            RquickSortFirstElementArray[index] = quickSortRunner(fptr, 'r', inputSize, firstElement);
            RquickSortRandomArray[index] = quickSortRunner(fptr, 'r', inputSize, random);
            RquickSortMedianArray[index] = quickSortRunner(fptr, 'r', inputSize, medianOfThree);
            IquickSortFirstElementArray[index] = quickSortRunner(fptr, 'i', inputSize, firstElement);
            IquickSortRandomArray[index] = quickSortRunner(fptr, 'i', inputSize, random);
            IquickSortMedianArray[index] = quickSortRunner(fptr, 'i', inputSize, medianOfThree);
            index++;
        }
    }

    fprintf(stderr, "RQuicksortFirstElement: ");
    printArray(RquickSortFirstElementArray, arraySize);

    fprintf(stderr, "RQuicksortRandom: ");
    printArray(RquickSortRandomArray, arraySize);

    fprintf(stderr, "RQuicksortMedian: ");
    printArray(RquickSortMedianArray, arraySize);

    fprintf(stderr, "IQuicksortFirstElement: ");
    printArray(IquickSortFirstElementArray, arraySize);

    fprintf(stderr, "IQuicksortRandom: ");
    printArray(IquickSortRandomArray, arraySize);

    fprintf(stderr, "IQuicksortMedian: ");
    printArray(IquickSortMedianArray, arraySize);

    fflush(stderr);

    free(RquickSortFirstElementArray);
    free(RquickSortRandomArray);
    free(RquickSortMedianArray);
    free(IquickSortFirstElementArray);
    free(IquickSortRandomArray);
    free(IquickSortMedianArray);
}

void insertionSortTest(FILE *fptr) {
    int arraySize = 50;
    int index = 0;
    double* RinsertionSort = (double*)malloc(arraySize * sizeof(double));
    double* IinsertionSort = (double*)malloc(arraySize * sizeof(double));
    if(RinsertionSort || IinsertionSort == NULL) {
        printf("Error allocating memory..(InsertionSort)\n");
        exit(EXIT_FAILURE);
    }
    for(int inputSize = 100; inputSize <= 1000000; inputSize *= 10) {
        for(int i = 0; i < 10; i++) {
            RinsertionSort[index] = InsertionSortRunner(fptr, 'i', inputSize);
            IinsertionSort[index] = InsertionSortRunner(fptr, 'r', inputSize);
            index++;
        }
    }

    fprintf(stderr, "RinsertionSort: ");
    printArray(RinsertionSort, arraySize);

    fprintf(stderr, "IinsertionSort: ");
    printArray(IinsertionSort, arraySize);

    fflush(stderr);

    free(RinsertionSort);
    free(IinsertionSort);
}

void printArray(double* array, int size) {
    for(int i = 0; i < size; i++) {
        fprintf(stderr, "%.1f ", array[i]);
    }
    fprintf(stderr,"\n");
}