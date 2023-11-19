#include <iostream>
#include <string>
#include <chrono>
#include "sorting_algo.h"
#include "utils.h"

using namespace Utils;

float get_average(long long* array, int arraySize);
float get_median(long long* array, int arraySize, bool isSorted = false);
float get_min(long long* array, int arraySize);
float get_max(long long* array, int arraySize);

int main()
{
    std::string reply;
    
    do
    {
        // sort_func sort = get_sort_func();
        
        // int arraySize = IO::get_int_input("Enter array size:\n");
        // int iterationCount = IO::get_int_input("Enter number of iterations:\n");

        sort_func sort = quick_sort;
        int arraySize = 100000;
        int iterationCount = 10;
        
        long long* resultArray = new long long[iterationCount];

        resultArray = get_sort_time_taken_array(sort, arraySize, iterationCount);

        float averageTimeTaken = get_average(resultArray, iterationCount);
        float medianTimeTaken = get_median(resultArray, iterationCount);
        
        std::cout << std::fixed;
        std::cout.precision(2);
        std::cout << "Average time taken: " << averageTimeTaken << " nanoseconds" << std::endl;
        std::cout << "Median time taken: " << medianTimeTaken << " nanoseconds" << std::endl;
        std::cout << "Min: " << get_min(resultArray, iterationCount) << " nanoseconds" << std::endl;
        std::cout << "Max: " << get_max(resultArray, iterationCount) << " nanoseconds" << std::endl;
        
        std::cout << "First: " << resultArray[0] << " nanoseconds" << std::endl;
        
        sort = nullptr;
        delete [] resultArray;
        resultArray = nullptr;


        IO::print_new_line();
        std::cout << "Try again? (y/n)\n>>> ";
        std::cin >> reply;
    } while (reply == "y");
    
    
    return 0;
}


float get_average(long long* array, int arraySize)
{
    long long sum = 0;
    for (int i = 0; i < arraySize; i++)
    {
        sum += array[i];
    }
    return (float)sum / arraySize;
}

float get_median(long long* array, int arraySize, bool isSorted)
{
    if (!isSorted)
    {
        quick_sort(array, arraySize);
    }
    
    if (arraySize % 2 == 0)
    {
        return (float)(array[arraySize / 2 - 1] + array[arraySize / 2]) / 2;
    }

    return (float)array[arraySize / 2];
    
}

float get_min(long long* array, int arraySize)
{
    long long min = array[0];
    for (int i = 1; i < arraySize; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    return min;
}

float get_max(long long* array, int arraySize)
{
    long long max = array[0];
    for (int i = 1; i < arraySize; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}