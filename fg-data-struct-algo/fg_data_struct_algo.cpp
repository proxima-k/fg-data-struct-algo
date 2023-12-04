#include <chrono>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <list>
#include "SortAlgorithms/sorting_algo.h"
#include "Utilities/utils.h"
#include "Utilities/performance.h"
#include "DataStructures/Graph.h"

using namespace Utils;

// sorting algorithms
void auto_generate_measurements();
void manual_measurements();

// graph
void load_from_file_graph();

int main()
{
    load_from_file_graph();
    return 0;
}

void manual_measurements()
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
            
            double averageTimeTaken = get_average(resultArray, iterationCount);
            double medianTimeTaken = get_median(resultArray, iterationCount);
            double min = get_min(resultArray, iterationCount);
            double max = get_max(resultArray, iterationCount);
            
            averageTimeTaken = nanoseconds_to_milliseconds(averageTimeTaken);
            medianTimeTaken = nanoseconds_to_milliseconds(medianTimeTaken);
            min = nanoseconds_to_milliseconds(min);
            max = nanoseconds_to_milliseconds(max);

            // print results
            std::cout << "Batch " << i+1 << "\n";
            for (int i=0; i<iterationCount; i++)
            {
                std::cout << std::fixed;
                std::cout << std::setprecision(8);
                std::cout << "Iteration " << std::setw(3) << i+1 << ": " << nanoseconds_to_milliseconds(resultArray[i]) << " ms\n";
            }
            std::cout << "Average: " << averageTimeTaken << " ms\n";
            std::cout << "Median: " << medianTimeTaken << " ms\n";
            std::cout << "Min: " << min << " ms\n";
            std::cout << "Max: " << max << " ms\n";
            std::cout << std::endl;
            
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
void auto_generate_measurements() {
    std::list<SortResult> sortResultList = std::list<SortResult>();
    const int dataSizes[] = { 10, 50, 100, 500, 1000, 5000 };
    int iterationCount = 10;
    
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
        for (int j=0; j<6; j++)
        {
            long long* resultArray = get_sort_time_taken_array(sort_func, dataSizes[j], iterationCount);

            double averageTimeTaken = get_average(resultArray, iterationCount);
            double medianTimeTaken = get_median(resultArray, iterationCount);
            double min = get_min(resultArray, iterationCount);
            double max = get_max(resultArray, iterationCount);
            
            SortResult sortResult;
            sortResult.sortName = sortFuncName;
            sortResult.arraySize = dataSizes[j];
            sortResult.averageTimeTaken = nanoseconds_to_milliseconds(averageTimeTaken);
            sortResult.medianTimeTaken = nanoseconds_to_milliseconds(medianTimeTaken);
            sortResult.min = nanoseconds_to_milliseconds(min);
            sortResult.max = nanoseconds_to_milliseconds(max);

            sortResultList.push_back(sortResult);
            
            delete [] resultArray;
            resultArray = nullptr;
        }
        sort_func = nullptr;
    }
    
    generate_csv_file(sortResultList, sortResultList.size(), "SortResult");
}

void load_from_file_graph()
{
    Graph graph = Graph();
    Node* startNode = nullptr;
    Node* endNode = nullptr;
    
    std::ifstream file ("NodesData.txt");

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
                // std::string node;
                
                if (line[column] == 'X')
                {
                    // std::cout << std::setw(5) << "";
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

                // std::cout << std::setw(5) << node->get_id();
                // std::cout << node << std::endl;
            }
            // std::cout << "\n";
        }
        file.close();

        std::cout << std::endl;
        std::cout << "Assigning neighbours...\n";
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
    IO::print_new_line();

    // graph.print_graph();

    std::string reply;
    while (reply != "y") {
        int iterationCount = IO::get_int_input("Iteration count?\n");
        for (int i=0; i<iterationCount; i++) {
            // depth first search
            std::cout << "Depth first search\n";
            
            std::chrono::steady_clock::time_point beginDFS = std::chrono::steady_clock::now();
            bool sucess = graph.depth_first_search(startNode, endNode);
            std::chrono::steady_clock::time_point endDFS = std::chrono::steady_clock::now();

            
            if (sucess) {
                std::cout << "Path found!\n";
            }
            else {
                std::cout << "Path not found!\n";
            }

            long long timeTakenNanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endDFS - beginDFS).count();
            double timeTakenMilliseconds = nanoseconds_to_milliseconds(timeTakenNanoseconds);

            std::cout << std::fixed;
            std::cout << std::setprecision(8);
            std::cout << "Time taken: " << timeTakenMilliseconds << " ms\n";

            // breadth first search
            std::cout << "Breadth first search\n";
            
            std::chrono::steady_clock::time_point beginBFS = std::chrono::steady_clock::now();
            sucess = graph.breadth_first_search(startNode, endNode);
            std::chrono::steady_clock::time_point endBFS = std::chrono::steady_clock::now();

            if (sucess) {
                std::cout << "Path found!\n";
            }
            else {
                std::cout << "Path not found!\n";
            }

            timeTakenNanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(endBFS - beginBFS).count();
            timeTakenMilliseconds = nanoseconds_to_milliseconds(timeTakenNanoseconds);

            std::cout << std::fixed;
            std::cout << std::setprecision(8);
            std::cout << "Time taken: " << timeTakenMilliseconds << " ms\n";
        }

        
        std::cout << std::endl;
        std::cout << "Do you want to exit? (y/n): ";
        std::cin >> reply;
    }

}

void task_3()
{
    Node node1 = Node(vector2(0, 0), 0);
    Node node2 = Node(vector2(1, 0), 1);
    Node node3 = Node(vector2(2, 0), 2);
    
    node1.add_neighbor(&node2);
    node1.add_neighbor(&node3);

    // node1.print_neighbours();

    std::cout << &node1 << std::endl;
    std::cout << &node2 << std::endl;
    std::cout << &node3 << std::endl;

    for (Node* node : node1.get_neighbors())
    {
        std::cout << node << std::endl;
        node->add_neighbor(&node1);
    }
}

