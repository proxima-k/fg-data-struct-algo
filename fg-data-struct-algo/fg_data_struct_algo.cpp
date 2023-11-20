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
    long long min;
    long long max;
    
    ~SortResult()
    {
        // delete [] timeTakenArray;
        // timeTakenArray = nullptr;
    }
};

double get_average(long long* array, int arraySize);
double get_median(long long* array, int arraySize, bool isSorted = false);
long long get_min(long long* array, int arraySize);
long long get_max(long long* array, int arraySize);
void generate_csv_file(std::list<SortResult> sortResultArray, int arraySize, std::string fileName);


int main()
{
    std::string reply;

    std::list<SortResult> sortResultList = std::list<SortResult>();
    int arraySizes[] = { 10, 50, 100, 500, 1000, 5000 };
    do
    {
        std::string sortName;
        sort_func sort = get_sort_func(sortName);
        
        for (int i=0; i<6; i++)
        {
            int arraySize = arraySizes[i];
            int iterationCount = 10;
            
            std::cout << "Sorting " << arraySize << " elements...\n";
            long long* resultArray = get_sort_time_taken_array(sort, arraySize, iterationCount);

            double averageTimeTaken = get_average(resultArray, iterationCount);
            double medianTimeTaken = get_median(resultArray, iterationCount);
            
            SortResult sortResult;
            sortResult.sortName = sortName;
            sortResult.arraySize = arraySize;
            sortResult.averageTimeTaken = averageTimeTaken;
            sortResult.medianTimeTaken = medianTimeTaken;
            sortResult.min = get_min(resultArray, iterationCount);
            sortResult.max = get_max(resultArray, iterationCount);

            sortResultList.push_back(sortResult);
            
            delete [] resultArray;
            resultArray = nullptr;
        }
        sort = nullptr;

        IO::print_new_line();
        std::cout << "Try again? (y/n)\n>>> ";
        
        std::cin >> reply;
    } while (reply == "y");
    
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
    csvFile.precision(2);
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

long long get_min(long long* array, int arraySize)
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

long long get_max(long long* array, int arraySize)
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