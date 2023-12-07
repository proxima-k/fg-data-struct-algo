
#include "task.h"
#include "Utilities/utils.h"
using namespace Utils;

void graph_task();

int main()
{


    /*
     * program 1: gets measurements with user input (data size, iteration size, batch size)
     * program 2: gets measurements automatically and saves the data to csv file
     * program 3: loads graph from file and perform depth first search and breadth first search
     *            and display summary of the measurements
     */
    
    // choose one of these program and comment out the rest to try out each program
    // manual_measure_sort();               // program 1
    // auto_generate_sort_measurements();   // program 2
    graph_task();                           // program 3
    
    return 0;
}


void graph_task()
{
    IO::print_message("Create new graph with reachable end node");
    load_from_file_graph("NodesData1.txt");

    IO::print_new_line();
    IO::print_message("Create new graph with non-reachable end node");
    load_from_file_graph("NodesData2.txt");
}
