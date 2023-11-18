#ifndef UTILS_H
#define UTILS_H

namespace Utils
{
    void print_message(const char* message, bool printNewLine = true);
    void print_new_line();

    void print_array(const int* array, int arraySize, bool printNewLine = true);
}

#endif // UTILS_H