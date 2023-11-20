#ifndef SORTING_ALGO_H
#define SORTING_ALGO_H
#include <string>

template <typename T>
void swap(T* a, T* b);

bool is_sorted(int* array, int arraySize);

typedef int* (*sort_func)(int* array, int arraySize);
sort_func get_sort_func(std::string& sortName);


// simple
int* selection_sort(int* array, int arraySize);

int* insertion_sort(int* array, int arraySize);

int* bubble_sort(int* array, int arraySize);

// advanced
int* merge_sort(int* array, int arraySize);

int* quick_sort(int* array, int arraySize);

// performance measuring
long long* get_sort_time_taken_array(sort_func sort, int arraySize, int iterationCount);
long long quick_sort(long long* array, int arraySize);


#endif // SORTING_ALGO_H