#include <chrono>
#include <iostream>
#include <string>
#include <fstream>
#include <list>

#include "task.h"
#include "SortAlgorithms/sorting_algo.h"
#include "Utilities/utils.h"
#include "Utilities/performance.h"
#include "DataStructures/Graph.h"

using namespace Utils;

void manual_measure_sort()
{
    std::string repeat = "y";
    while (repeat == "y")
    {
        // prompt for sort function
        std::string sortFuncName;
        sort_func sort_func = prompt_sort_func(sortFuncName);
        if (sort_func == nullptr)
        {
            std::cout << "Choice not found.\n";
            continue;
        }

        // prompt for data size, iteration count, batch size
        int dataSize = IO::get_int_input("Data size?\n");
        int iterationCount = IO::get_int_input("Iteration count?\n");
        int batchSize = IO::get_int_input("Batch size?\n");

        std::cout << std::endl;
        std::cout << "Performing: " << sortFuncName << "\n";

        // time measurements
        for (int i=0; i<batchSize; i++) {
            long long* resultArray = get_sort_time_taken_array(sort_func, dataSize, iterationCount);
            
            std::cout << "Batch " << i+1 << "\n";

            print_time_taken_summary(resultArray, iterationCount);
            
            delete [] resultArray;
            resultArray = nullptr;
        }
        sort_func = nullptr;
            
        // prompt for repeat
        std::cout << std::endl;
        std::cout << "Do you want to repeat? (y/n): ";
        std::cin >> repeat;
        std::cout << std::endl;
    }
}

void auto_generate_sort_measurements() {
    std::list<SortResult> sortResultList = std::list<SortResult>();
    const int dataSizes[] = { 10, 50, 100, 500, 1000, 5000 };
    int iterationCount = 50;
    
    for (int i=0; i<5; i++)
    {
        std::string sortFuncName;
        sort_func sort_func = get_sort_func(i+1, sortFuncName);
        if (sort_func == nullptr)
        {
            std::cout << "Choice not found.\n";
            continue;
        }
        
        std::cout << "Performing: " << sortFuncName << "\n";
        for (int dataSize : dataSizes)
        {
            long long* resultArray = get_sort_time_taken_array(sort_func, dataSize, iterationCount);

            double averageTimeTaken = get_average(resultArray, iterationCount);
            double medianTimeTaken = get_median(resultArray, iterationCount);
            double min = get_min(resultArray, iterationCount);
            double max = get_max(resultArray, iterationCount);
            
            SortResult sortResult;
            sortResult.sortName = sortFuncName;
            sortResult.arraySize = dataSize;
            sortResult.averageTimeTaken = nano_to_milli(averageTimeTaken);
            sortResult.medianTimeTaken = nano_to_milli(medianTimeTaken);
            sortResult.min = nano_to_milli(min);
            sortResult.max = nano_to_milli(max);

            sortResultList.push_back(sortResult);
            
            delete [] resultArray;
            resultArray = nullptr;
        }
        sort_func = nullptr;
    }
    
    generate_csv_file(sortResultList, sortResultList.size(), "SortResult");
}

void load_from_file_graph(std::string fileName)
{
    Graph graph = Graph();
    Node* startNode = nullptr;
    Node* endNode = nullptr;
    
    std::ifstream file (fileName);

    if (file.is_open())
    {
        std::string line;
        int row = -1;
        int id = 0;
        int width= 0;
        
        while (getline(file, line))
        {
            row++;
            for (int column=0; column < line.length(); column++)
            {
                if (line[column] == 'X')
                {
                    continue;
                }
                Node* node = new Node(vector2(column, row), id);
                graph.add_node(node);
                id++;

                if (line[column] == 'S')
                {
                    startNode = node;
                }
                else if (line[column] == 'G')
                {
                    endNode = node;
                }
                
                if (width < column)
                    width = column;
            }
        }
        file.close();
        
        // connecting nodes as neighbors
        for (Node* node : graph.get_nodes())
        {
            for (Node* otherNode : graph.get_nodes())
            {
                if (otherNode->get_position().x == node->get_position().x - 1 && otherNode->get_position().y == node->get_position().y)
                {
                    node->add_neighbor(otherNode);
                }
                else if (otherNode->get_position().x == node->get_position().x + 1 && otherNode->get_position().y == node->get_position().y)
                {
                    node->add_neighbor(otherNode);
                }
                else if (otherNode->get_position().x == node->get_position().x && otherNode->get_position().y == node->get_position().y - 1)
                {
                    node->add_neighbor(otherNode);
                }
                else if (otherNode->get_position().x == node->get_position().x && otherNode->get_position().y == node->get_position().y + 1)
                {
                    node->add_neighbor(otherNode);
                }
            }
        }
        
    }
    else
    {
        std::cout << "Unable to open file";
        return;
    }

    IO::print_new_line();
    // prints out node neighbours

    int showNeighbours = IO::get_int_input("Show neighbours? (1 - Yes/0 - No)\n");
    if (showNeighbours)
    {
        graph.print_node_neighbors();
    }

    std::string reply = "y";
    while (reply == "y") {

        int iterationCount = IO::get_int_input("Iteration count?\n");
        int showIterations = IO::get_int_input("Show iterations? (1 - Yes/0 - No)\n");
        
        long long * resultArray = new long long[iterationCount];
        bool sucess = false;
        // depth first search
        IO::print_title("Depth first search");
        for (int i=0; i<iterationCount; i++)
        {
            std::chrono::steady_clock::time_point beginDFS = std::chrono::steady_clock::now();
            sucess = graph.depth_first_search(startNode, endNode);
            std::chrono::steady_clock::time_point endDFS = std::chrono::steady_clock::now();

            long long timeTakenNanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endDFS - beginDFS).count();
            resultArray[i] = timeTakenNanoseconds;
        }

        if (sucess)
            std::cout << "Path found!\n";
        else
            std::cout << "Path not found!\n";
        
        print_time_taken_summary(resultArray, iterationCount, showIterations);
        
        // breadth first search
        IO::print_title("Breadth first search");
        for (int i=0; i<iterationCount; i++)
        {
            std::chrono::steady_clock::time_point beginBFS = std::chrono::steady_clock::now();
            sucess = graph.breadth_first_search(startNode, endNode);
            std::chrono::steady_clock::time_point endBFS = std::chrono::steady_clock::now();

            long long timeTakenNanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endBFS - beginBFS).count();
            resultArray[i] = timeTakenNanoseconds;
        }

        if (sucess)
            std::cout << "Path found!\n";
        else
            std::cout << "Path not found!\n";
        
        print_time_taken_summary(resultArray, iterationCount, showIterations);
        
        std::cout << std::endl;
        std::cout << "Do you want to try again? (y/n): ";
        std::cin >> reply;
    }

}

