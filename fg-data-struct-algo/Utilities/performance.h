#ifndef PERFORMANCE_H
#define PERFORMANCE_H

#include <list>
#include <string>

struct SortResult
{
    std::string sortName;
    int arraySize;
    double averageTimeTaken;
    double medianTimeTaken;
    double min;
    double max;
};

double get_average(long long* array, int arraySize);
double get_median(long long* array, int arraySize, bool isSorted = false);
double get_min(long long* array, int arraySize);
double get_max(long long* array, int arraySize);
double nano_to_milli(double nanoseconds);

// functions to display/export data
void print_time_taken_summary(long long* resultArray, int arraySize, bool showIterations = false);
void generate_csv_file(std::list<SortResult> sortResultArray, int arraySize, std::string fileName);

#endif // PERFORMANCE_H
