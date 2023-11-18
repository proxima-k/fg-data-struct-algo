#include "utils.h"
#include <iostream>
#include <string>


void Utils::print_message(const char* message, bool printNewLine)
{
    std::cout << message;
    if (printNewLine)
        std::cout << std::endl;
}

void Utils::print_new_line()
{
    std::cout << std::endl;
}

void Utils::print_array(const int* array, int arraySize, bool printNewLine)
{
    for (int i = 0; i < arraySize; i++)
    {
        std::cout << array[i] << " ";
    }
    if (printNewLine)
        std::cout << std::endl;
}