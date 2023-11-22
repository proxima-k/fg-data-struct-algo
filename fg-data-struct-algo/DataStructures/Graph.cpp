#include "Graph.h"

#include <queue>
#include <iostream>
#include <iomanip>

void Graph::add_node(Node node)
{
    nodes.push_back(node);
}

void Graph::print_graph() const
{
    Node previousNode = *get_nodes().begin();

    for (Node node : nodes)
    {
        node.print_neighbours();
        // node.print_neighbours();
        // if (node.get_position().y == previousNode.get_position().y)
        // {
        //     int distance = node.get_position().x - previousNode.get_position().x;
        //     for (int i=0; i<distance-1; i++)
        //     {
        //         std::cout << std::setw(5) << "";
        //     }
        // }
        // else
        // {
        //     std::cout << "\n";
        // }
        //
        // std::cout << std::setw(5) << node.get_neighbours().size();
        //
        //
        // previousNode = node;
        // std::cout << node.get_position().x << " " << node.get_position().y << std::endl;
    }
}


bool Graph::breadth_first_search(Node start, Node end) const
{
    bool* visited = new bool[nodes.size()];
    std::queue<Node> toVisit;
    toVisit.push(start);


    while (!toVisit.empty())
    {
        Node current = toVisit.front();
        toVisit.pop();
        
        if (current.get_id() == end.get_id())
        {
            return true;
        }

        for (const Node& neighbor : current.get_neighbours())
        {
            if (!visited[neighbor.get_id()])
            {
                toVisit.push(neighbor);
                visited[neighbor.get_id()] = true;
            }
        }
    }
    
    return false;
}

Node::Node()
{
    this->position_ = vector2(0, 0);
    this->id_ = 0;
    this->neighbors_ = std::list<Node>();
}

Node::Node(vector2 position, int id, std::list<Node> neighbors)
{
    this->position_ = position;
    this->id_ = id;
    this->neighbors_ = neighbors;
}

const std::list<Node>& Node::get_neighbours() const
{
    return this->neighbors_;
}

void Node::add_neighbour(Node neighbour)
{
    this->neighbors_.push_back(neighbour);

    // std::cout << "Added neighbour to node " << this->id_ << std::endl; 
    // std::cout << neighbour.get_position().x << " " << neighbour.get_position().y << std::endl;
    // std::cout << neighbors_.size() << std::endl;
}

void Node::print_neighbours() const
{
    std::cout << "Printing neighbours for node " << this->id_ << std::endl;
    for (Node neighbor : this->neighbors_)
    {
        std::cout << neighbor.get_position().x << " " << neighbor.get_position().y << std::endl;
    }
}
