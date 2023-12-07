#include "Graph.h"
#include "../Utilities/utils.h"
#include <queue>
#include <stack>
#include <iostream>
#include <iomanip>

using namespace Utils;


Graph::~Graph()
{
    for (Node* node : nodes_)
    {
        delete node;
        node = nullptr;
    }
    nodes_.clear();
}

void Graph::add_node(Node* node)
{
    nodes_.push_back(node);
}

void Graph::print_node_neighbors() const
{
    Node* previousNode = nodes_.front();
    
    for (Node* node : nodes_)
    {
        if (node->get_position().y == previousNode->get_position().y)
        {
            int distance = node->get_position().x - previousNode->get_position().x;
            for (int i=0; i<distance-1; i++)
            {
                std::cout << std::setw(5) << "";
            }
        }
        else
        {
            std::cout << "\n";
            for (int i=0; i<node->get_position().x; i++)
            {
                std::cout << std::setw(5) << "";
            }
        }
        
        std::cout << std::setw(5) << node->get_neighbors().size();
        
        
        previousNode = node;
        // std::cout << node->get_position().x << " " << node->get_position().y << std::endl;
    }
    std::cout << "\n";
}

bool Graph::breadth_first_search(Node* start, Node* end) const
{
    bool* visited = new bool[nodes_.size()];
    for (int i=0; i<nodes_.size(); i++)
    {
        visited[i] = false;
    }
    
    std::queue<Node*> toVisit;
    toVisit.push(start);
    visited[start->get_id()] = true;
    
    while (!toVisit.empty())
    {
        Node* current = toVisit.front();

        toVisit.pop();
        
        if (current->get_id() == end->get_id())
        {
            return true;
        }

        for (Node* neighbor : current->get_neighbors())
        {
            if (!visited[neighbor->get_id()])
            {
                toVisit.push(neighbor);
                visited[neighbor->get_id()] = true;
            }
        }
    }

    delete [] visited;
    visited = nullptr;
    
    return false;
}

bool Graph::depth_first_search(Node* start, Node* end) const
{
    bool* visited = new bool[nodes_.size()];
    for (int i=0; i<nodes_.size(); i++)
    {
        visited[i] = false;
    }
    
    std::stack<Node*> toVisit;
    toVisit.push(start);
    visited[start->get_id()] = true;
    
    while (!toVisit.empty())
    {
        Node* current = toVisit.top();

        toVisit.pop();
        
        if (current->get_id() == end->get_id())
        {
            return true;
        }

        for (Node* neighbor : current->get_neighbors())
        {
            if (!visited[neighbor->get_id()])
            {
                toVisit.push(neighbor);
                visited[neighbor->get_id()] = true;
            }
        }
    }

    delete [] visited;
    visited = nullptr;
    
    return false;
}

