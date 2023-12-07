#include "performance.h"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <list>
#include "../SortAlgorithms/sorting_algo.h"

double get_average(long long* array, int arraySize)
{
    long long sum = 0;
    for (int i = 0; i < arraySize; i++)
    {
        sum += array[i];
    }
    return (double)sum / arraySize;
}

double get_median(long long* array, int arraySize, bool isSorted)
{
    if (!isSorted)
    {
        quick_sort(array, arraySize);
    }
    
    if (arraySize % 2 == 0)
    {
        return (double)(array[arraySize / 2 - 1] + array[arraySize / 2]) / 2;
    }

    return (double)array[arraySize / 2];
    
}

double get_min(long long* array, int arraySize)
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

double get_max(long long* array, int arraySize)
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

double nano_to_milli(double nanoseconds)
{
    return nanoseconds / 1000000.0;
}


void generate_csv_file(std::list<SortResult> sortResultArray, int arraySize, std::string fileName)
{
    std::ofstream csvFile;
    csvFile.open(fileName + ".csv");

    if (!csvFile.is_open())
    {
        std::cout << "Error opening file.\n";
        return;
    }
    
    csvFile << "Sort Algorithm, Average, Median, Min, Max\n";
    csvFile << std::fixed;
    csvFile.precision(8);
    for (const auto& sortResult : sortResultArray)
    {
        csvFile << sortResult.sortName << " (" << sortResult.arraySize << "), "
                << sortResult.averageTimeTaken << ", "
                << sortResult.medianTimeTaken << ", "
                << sortResult.min << ", "
                << sortResult.max << "\n";
    }
    csvFile.close();
}

void print_time_taken_summary(long long* resultArray, int arraySize, bool showIterations)
{
    double averageTimeTaken = get_average(resultArray, arraySize);
    double medianTimeTaken = get_median(resultArray, arraySize);
    double min = get_min(resultArray, arraySize);
    double max = get_max(resultArray, arraySize);
            
    averageTimeTaken = nano_to_milli(averageTimeTaken);
    medianTimeTaken = nano_to_milli(medianTimeTaken);
    min = nano_to_milli(min);
    max = nano_to_milli(max);

    std::cout << std::fixed;
    std::cout << std::setprecision(8);
    if (showIterations)
    {
        for (int i=0; i<arraySize; i++)
        {
            std::cout << "Iteration " << std::setw(3) << i+1 << ": " << nano_to_milli(resultArray[i]) << " ms\n";
        }
    }
    std::cout << "Average: " << averageTimeTaken << " ms\n";
    std::cout << "Median: " << medianTimeTaken << " ms\n";
    std::cout << "Min: " << min << " ms\n";
    std::cout << "Max: " << max << " ms\n";
    std::cout << std::endl;
}