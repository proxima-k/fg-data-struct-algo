#include "utils.h"
#include <iostream>
#include <string>


void Utils::Logger::print_message(const char* message, bool printNewLine)
{
    std::cout << message;
    if (printNewLine)
        std::cout << std::endl;
}

void Utils::Logger::print_new_line()
{
    std::cout << std::endl;
}

void Utils::Logger::print_array(const int* array, int arraySize, bool printNewLine)
{
    for (int i = 0; i < arraySize; i++)
    {
        std::cout << array[i] << " ";
    }
    if (printNewLine)
        std::cout << std::endl;
}


int* Utils::DataStructures::create_array_random_values(int arraySize, int minValue, int maxValue)
{
    int* array = new int[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = rand() % maxValue + minValue;
    }
    return array;
}