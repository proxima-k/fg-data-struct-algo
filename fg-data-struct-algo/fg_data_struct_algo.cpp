#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <list>
#include "sorting_algo.h"
#include "utils.h"
#include "performance.h"
#include "DataStructures/Graph.h"

using namespace Utils;

void task_1();
void task_2();
void task_3();

int main()
{
    task_2();
    return 0;
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


void task_2()
{
    Graph graph = Graph();

    
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
                    std::cout << std::setw(5) << "";
                    continue;
                }
                Node* node = new Node(vector2(column, row), id);
                graph.add_node(node);
                id++;
                // else if (line[column] == 'S') {
                //     Node startNode = Node(vector2(column, row), id, std::list<Node>());
                //     graph.add_node(startNode);
                //     id++;
                // }
                // else if (line[column] == 'G')
                // {
                //     Node endNode = Node(vector2(column, row), id, std::list<Node>());
                //     graph.add_node(endNode);
                //     id++;
                // }
                if (width < column)
                    width = column;

                std::cout << std::setw(5) << node->get_id();
                // std::cout << node << std::endl;
            }
            std::cout << "\n";
        }
        file.close();

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
        std::cout << "Unable to open file";

    IO::print_new_line();
    IO::print_new_line();
    // if previous node x is same as current node x - 1

    graph.print_graph();

}

void task_1()
{
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

