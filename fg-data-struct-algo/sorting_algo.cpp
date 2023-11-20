#include "sorting_algo.h"
#include <chrono>
#include "utils.h"
#include <iostream>
using namespace Utils;

template <typename T>
void swap(T* a, T* b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

bool is_sorted(int* array, int arraySize)
{
    for (int i = 0; i < arraySize - 1; i++)
    {
        if (array[i] > array[i + 1])
            return false;
    }
    return true;
}


sort_func get_sort_func(std::string& sortName)
{

    int choice;

    do
    {
        choice = IO::get_int_input("Select sorting algorithm:\n"
                                   "1. Selection sort\n"
                                   "2. Insertion sort\n"
                                   "3. Bubble sort\n"
                                   "4. Merge sort\n"
                                   "5. Quick sort\n");

        if (choice < 1 || choice > 5)
            IO::print_message("Invalid choice. Please try again.");
    } while (choice < 1 || choice > 5);
    
    switch (choice)
    {
    case 1:
        sortName = "Selection sort";
        return selection_sort;
    case 2:
        sortName = "Insertion sort";
        return insertion_sort;
    case 3:
        sortName = "Bubble sort";
        return bubble_sort;
    case 4:
        sortName = "Merge sort";
        return merge_sort;
    case 5:
        sortName = "Quick sort";
        return quick_sort;
    default:
        return nullptr;
    }
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
    
    quick_sort(array, pivotIndex);
    quick_sort(array+pivotIndex+1, lastIndex-pivotIndex);
    
    return array;
}

long long* get_sort_time_taken_array(sort_func sort, int arraySize, int iterationCount)
{
    long long* resultArray = new long long[iterationCount];
    
    for (int i = 0; i < iterationCount; i++)
    {
        int* array = DataStructures::create_array_random_values(arraySize);
        
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
 
        sort(array, arraySize);

        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

        if (!is_sorted(array, arraySize))
        {
            std::cout << "ERROR: ARRAY NOT SORTED" << std::endl;
        }

        long long timeTakenNanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
        
        resultArray[i] = timeTakenNanoseconds;
        
        delete [] array;
        // std::cout << "end of iteration " << i << std::endl;
    }

    
    return resultArray;
}

long long quick_sort(long long* array, int arraySize)
{
    if (arraySize <= 1)
    {
        return array[0];
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
    
    quick_sort(array, pivotIndex);
    quick_sort(array+pivotIndex+1, lastIndex-pivotIndex);
    
    return array[0];
}