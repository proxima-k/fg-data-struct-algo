#include <iostream>
#include <string>
#include "sorting_algo.h"
#include "utils.h"

int main()
{
    const int arraySize = 10;
    int* array = new int[arraySize] { 9, 7, 1, 3, 10, 8, 6, 4, 2, 5};
    Utils::print_message("Unsorted array: ", false);
    Utils::print_array(array, arraySize);

    // merge_sort(array, arraySize);
    quick_sort(array, arraySize);

    Utils::print_new_line();
    Utils::print_message("Sorted array  : ", false);
    Utils::print_array(array, arraySize);
    
    
    return 0;
}