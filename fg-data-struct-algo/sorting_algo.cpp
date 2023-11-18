#include "sorting_algo.h"

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* selection_sort(int* array, int arraySize) {
    // if array size is larger than one, then start checking
    int currentItemIndex = 0;
    while (currentItemIndex < arraySize) {
        int minItemIndex = currentItemIndex;
        for (int i = currentItemIndex; i < arraySize; i++) {
            if (array[i] < array[minItemIndex])
                swap(&array[i], &array[minItemIndex]);
        }
        currentItemIndex++;
    }
    return array;
}

int* insertion_sort(int* array, int arraySize) {
    // if array size is larger than one, then start checking
    int currentItemIndex = 0;
    while (currentItemIndex < arraySize) {
        for (int i=0; i < currentItemIndex; i++) {
            if (array[i] > array[currentItemIndex]) {
                swap(&array[i], &array[currentItemIndex]);
            }
        }
        currentItemIndex++;
    }
    return array;
}

int* bubble_sort(int* array, int arraySize) {
    while (arraySize > 1) {
        for (int i=0; i < arraySize-1; i++) {
            if (array[i] > array[i+1])
                swap(&array[i], &array[i+1]);
        }
        arraySize--;
    }

    return array;
}

int* merge_sort(int* array, int arraySize) {
    
    if (arraySize == 1)
    {
        return array;
    }
    const int leftSize = arraySize / 2;
    const int rightSize = arraySize - leftSize;

    int* leftArray = merge_sort(array, leftSize);
    int* rightArray = merge_sort(array + leftSize, rightSize);
    int* combinedArray = new int[arraySize];
    
    // merge left and right
    int leftIndex = 0;
    int rightIndex = 0;
    int combinedIndex = 0;
    while (leftIndex < leftSize && rightIndex < rightSize)
    {
        if (leftArray[leftIndex] <= rightArray[rightIndex])
        {
            combinedArray[combinedIndex] = leftArray[leftIndex];
            leftIndex++;
        } else
        {
            combinedArray[combinedIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        combinedIndex++;
    }
    
    
    while (leftIndex < leftSize)
    {
        combinedArray[combinedIndex] = leftArray[leftIndex];
        leftIndex++;
        combinedIndex++;
    }

    while (rightIndex < rightSize)
    {
        combinedArray[combinedIndex] = rightArray[rightIndex];
        rightIndex++;
        combinedIndex++;
    }
    
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = combinedArray[i];
    }
    
    leftArray = nullptr;
    rightArray = nullptr;

    delete [] leftArray;
    combinedArray = nullptr;
    
    return array;
}

int* quick_sort(int* array, int arraySize)
{
    if (arraySize <= 1)
    {
        return array;
    }
    
    int pivotIndex = 0;
    int lastIndex = arraySize - 1;

    for (int i=0; i<lastIndex; i++)
    {
        if (array[i] < array[lastIndex])
        {
            swap(&array[i], &array[pivotIndex]);
            pivotIndex++;
        }
    }
    swap(&array[pivotIndex], &array[lastIndex]);

    // std::cout << pivotIndex << std::endl;
    // Utils::print_message(std::to_string(arraySize).c_str());
    // Utils::print_message("Partitioned: ", false);
    // Utils::print_array(array, arraySize);
    //
    quick_sort(array, pivotIndex);
    quick_sort(array+pivotIndex+1, lastIndex-pivotIndex);
    
    return array;
}