#ifndef PERFORMANCE_H
#define PERFORMANCE_H

#include <list>
#include <string>

struct SortResult
{
    std::string sortName;
    int arraySize;
    // long long* timeTakenArray;
    double averageTimeTaken;
    double medianTimeTaken;
    double min;
    double max;
};

double get_average(long long* array, int arraySize);
double get_median(long long* array, int arraySize, bool isSorted = false);
double get_min(long long* array, int arraySize);
double get_max(long long* array, int arraySize);
void generate_csv_file(std::list<SortResult> sortResultArray, int arraySize, std::string fileName);
double nano_to_milli(double nanoseconds);

#endif // PERFORMANCE_H