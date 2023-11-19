#include <iostream>
#include <string>
#include <chrono>
#include "sorting_algo.h"
#include "utils.h"

using namespace Utils;

int main()
{
    std::string reply;
    
    do
    {
        sort_func sort = get_sort_func();
        
        Logger::print_message("Enter array size:\n>>> ", false);
        int arraySize;
        std::cin >> arraySize;

        int iterations;
        Logger::print_message("Enter number of iterations:\n>>> ", false);
        std::cin >> iterations;

        
        for (int i = 0; i < iterations; i++)
        {
            int* array = DataStructures::create_array_random_values(arraySize);
            
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            
            sort(array, arraySize);
            
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

            auto timeTakenMicroseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
            auto timeTakenNanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();

        
            Logger::print_new_line();
            std::cout << "Iteration " << i + 1 << std::endl;
            std::cout << "Time taken for sort: " << timeTakenMicroseconds << " microseconds, "
                      << timeTakenNanoseconds << " nanoseconds" << std::endl;

            delete [] array;
        }

        sort = nullptr;
        Logger::print_new_line();
        std::cout << "Try again? (y/n)\n>>> ";
        std::cin >> reply;
    } while (reply == "y");
    
    
    return 0;
}