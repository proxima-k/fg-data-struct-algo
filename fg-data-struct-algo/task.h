#ifndef TASK_H
#define TASK_H

#include <string>

// ===== SORTING ALGORITHMS ======
// automatically generate measurements and save to csv file
void auto_generate_sort_measurements();
// prompts user for sort function and display a summary of the measurements
void manual_measure_sort();

// ===== GRAPH SEARCH =====
// loads graph from file and perform depth first search and breadth first search and display summary of the measurements
void load_from_file_graph(std::string fileName = "NodesData1.txt");


#endif // TASK_H