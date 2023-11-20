#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <list>
#include "sorting_algo.h"
#include "utils.h"

using namespace Utils;

struct SortResult
{
    std::string sortName;
    int arraySize;
    // long long* timeTakenArray;
    double averageTimeTaken;
    double medianTimeTaken;
    double min;
    double max;
    
    // ~SortResult()
    // {
        // delete [] timeTakenArray;
        // timeTakenArray = nullptr;
    // }
};

double get_average(long long* array, int arraySize);
double get_median(long long* array, int arraySize, bool isSorted = false);
double get_min(long long* array, int arraySize);
double get_max(long long* array, int arraySize);
void generate_csv_file(std::list<SortResult> sortResultArray, int arraySize, std::string fileName);
double nanoseconds_to_milliseconds(double nanoseconds)
{
    return nanoseconds / 1000000.0;
}

int main()
{
    std::string reply;

    std::list<SortResult> sortResultList = std::list<SortResult>();
    const int dataSizes[] = { 10, 50, 100, 500, 1000, 5000 };

    // i need a list of sort_func
    sort_func sortFuncs[] = { selection_sort, insertion_sort, bubble_sort, merge_sort, quick_sort };
    
    for (int i=0; i<5; i++)
    {
        std::string sortName;
        switch (i)
        {
            case 0:
                sortName = "Selection sort";
                break;
            case 1:
                sortName = "Insertion sort";
                break;
            case 2:
                sortName = "Bubble sort";
                break;
            case 3:
                sortName = "Merge sort";
                break;
            case 4:
                sortName = "Quick sort";
                break;
            default:
                break;
        }
        
        // sort_func sort = get_sort_func(sortName);

        std::cout << "Sorting algorithm: " << sortName << "\n";
        for (int j=0; j<6; j++)
        {
            int dataSize = dataSizes[j];
            int iterationCount = 10;
            
            // std::cout << "Sorting " << dataSize << " elements...\n";
            long long* resultArray = get_sort_time_taken_array(sortFuncs[i], dataSize, iterationCount);

            double averageTimeTaken = get_average(resultArray, iterationCount);
            double medianTimeTaken = get_median(resultArray, iterationCount);
            double min = get_min(resultArray, iterationCount);
            double max = get_max(resultArray, iterationCount);
            
            SortResult sortResult;
            sortResult.sortName = sortName;
            sortResult.arraySize = dataSize;
            sortResult.averageTimeTaken = nanoseconds_to_milliseconds(averageTimeTaken);
            sortResult.medianTimeTaken = nanoseconds_to_milliseconds(medianTimeTaken);
            sortResult.min = nanoseconds_to_milliseconds(min);
            sortResult.max = nanoseconds_to_milliseconds(max);

            sortResultList.push_back(sortResult);
            
            delete [] resultArray;
            resultArray = nullptr;
        }
        // sort = nullptr;

        // IO::print_new_line();
        // std::cout << "Try again? (y/n)\n>>> ";
        // std::cin >> reply;
    }
    
    generate_csv_file(sortResultList, sortResultList.size(), "SortResult");
    
    return 0;
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