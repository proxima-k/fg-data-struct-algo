#include "sorting_algo.h"

int* merge_sort(int* array, int arraySize)
{
    
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