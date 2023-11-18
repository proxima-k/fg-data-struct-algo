#include <iostream>
#include "sorting_algo.h"
#include "utils.h"

int* quick_sort(int* array, int arraySize)
{

    int* lastItem = array + (arraySize-1);

    
    return array;
}

int main()
{
    const int arraySize = 10;
    int* array = new int[arraySize] { 9, 7, 5, 3, 10, 8, 6, 4, 2, 1};
    Utils::print_message("Unsorted array: ", false);
    Utils::print_array(array, arraySize);

    // merge_sort(array, arraySize);
    bubble_sort(array, arraySize);

    Utils::print_new_line();
    Utils::print_message("Sorted array: ", false);
    Utils::print_array(array, arraySize);
    
    
    return 0;
}