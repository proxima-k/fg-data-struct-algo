#include <iostream>

// merge sort function

int* merge_sort(int* array, int arraySize)
{
    if (arraySize == 1)
    {
        return array;
    }
    const int leftSize = arraySize / 2;
    const int rightSize = arraySize - leftSize;

    const int* leftArray = merge_sort(array, leftSize);
    const int* rightArray = merge_sort(array + leftSize, rightSize);

    // merge left and right
    int leftIndex = 0;
    int rightIndex = 0;
    int combinedIndex = 0;
    while (leftIndex < leftSize && rightIndex < rightSize)
    {
        if (leftArray[leftIndex] <= rightArray[rightIndex])
        {
            array[combinedIndex] = leftArray[leftIndex];
            leftIndex++;
        } else
        {
            array[combinedIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        combinedIndex++;
    }

    while (leftIndex < leftSize)
    {
        array[combinedIndex] = leftArray[leftIndex];
        leftIndex++;
        combinedIndex++;
    }

    while (rightIndex < rightSize)
    {
        array[combinedIndex] = rightArray[rightIndex];
        rightIndex++;
        combinedIndex++;
    }

    // delete leftArray;
    // delete rightArray;
    // leftArray = nullptr;
    // rightArray = nullptr;
    
    return array;
}   

int main()
{
    int* unsort = new int[10] { 9, 7, 5, 3, 1, 2, 4, 6, 8, 10};

    merge_sort(unsort, 10);
    std::cout << "Sorted array: ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << unsort[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}