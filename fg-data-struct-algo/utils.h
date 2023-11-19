#ifndef UTILS_H
#define UTILS_H

namespace Utils
{
    namespace Logger
    {
        void print_message(const char* message, bool printNewLine = true);
        void print_new_line();

        void print_array(const int* array, int arraySize, bool printNewLine = true);
    }

    namespace DataStructures
    {
        int* create_array_random_values(int arraySize, int minValue = 1, int maxValue = 100);
    }
}

#endif // UTILS_H