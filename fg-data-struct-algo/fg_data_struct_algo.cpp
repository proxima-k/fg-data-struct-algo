#include <iostream>
#include "sorting_algo.h"


int main()
{
    int* unsort = new int[10] { 9, 7, 5, 3, 10, 8, 6, 4, 2, 1};
    std::cout << "Unsorted array: ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << unsort[i] << " ";
    }
    std::cout << std::endl << std::endl;

    merge_sort(unsort, 10);
    
    std::cout << "\nSorted array: ";
    for (int i = 0; i < 10; i++)
    {
        std::cout << unsort[i] << " ";
    }
    std::cout << std::endl;
    
    
    return 0;
    }