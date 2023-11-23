#include "Graph.h"

#include <queue>
#include <stack>
#include <iostream>
#include <iomanip>

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

void Graph::print_graph()
{
    Node* previousNode = nodes_.front();
    
    for (Node* node : nodes_)
    {
        // node->print_neighbors();
        // node.print_neighbours();
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

        // std::cout << "Visiting node " << current->get_id() << std::endl;
        toVisit.pop();
        
        if (current->get_id() == end->get_id())
        {
            return true;
        }

        for (Node* neighbor : current->get_neighbors())
        {
            // std::cout << "Checking neighbor " << neighbor->get_id() << std::endl;

            // std::cout << visited[neighbor->get_id()] << std::endl;
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

        std::cout << "Visiting node " << current->get_id() << std::endl;
        toVisit.pop();
        
        if (current->get_id() == end->get_id())
        {
            return true;
        }

        for (Node* neighbor : current->get_neighbors())
        {
            // std::cout << "Checking neighbor " << neighbor->get_id() << std::endl;

            // std::cout << visited[neighbor->get_id()] << std::endl;
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

