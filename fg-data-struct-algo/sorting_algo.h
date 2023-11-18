#ifndef SORTING_ALGO_H
#define SORTING_ALGO_H

void swap(int* a, int* b);

// simple
int* selection_sort(int* array, int arraySize);

int* insertion_sort(int* array, int arraySize);

int* bubble_sort(int* array, int arraySize);

// advanced
int* merge_sort(int* array, int arraySize);

int* quick_sort(int* array, int arraySize);

#endif // SORTING_ALGO_H