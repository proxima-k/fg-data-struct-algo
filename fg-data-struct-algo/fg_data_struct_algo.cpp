#include <iostream>
#include "sorting_algo.h"
#include "utils.h"

int* quick_sort(int* array, int arraySize)
{
    
    return nullptr;
}

int main()
{
    int* array = new int[10] { 9, 7, 5, 3, 10, 8, 6, 4, 2, 1};
    Utils::print_message("Unsorted array: ", false);
    Utils::print_array(array, 10);

    merge_sort(array, 10);

    Utils::print_new_line();
    Utils::print_message("Sorted array: ", false);
    Utils::print_array(array, 10);
    
    
    return 0;
}