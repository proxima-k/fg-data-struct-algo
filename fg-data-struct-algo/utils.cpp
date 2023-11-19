#include "utils.h"
#include <iostream>
#include <random>
#include <string>


void Utils::IO::print_message(const char* message, bool printNewLine)
{
    std::cout << message;
    if (printNewLine)
        std::cout << std::endl;
}

void Utils::IO::print_new_line()
{
    std::cout << std::endl;
}

void Utils::IO::print_array(const int* array, int arraySize, bool printNewLine)
{
    for (int i = 0; i < arraySize; i++)
    {
        std::cout << array[i] << " ";
    }
    if (printNewLine)
        std::cout << std::endl;
}

int Utils::IO::get_int_input(const char* prompt)
{
    int input = -1;
    bool validInput = false;

    std::cout << prompt << ">>> ";
    while (!validInput) {
        try {
            std::cin >> input;
            validInput = true;
        } catch (std::exception& e) {
            std::cout << "Invalid integer. Please try again.\n>>> " << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    return input;
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

