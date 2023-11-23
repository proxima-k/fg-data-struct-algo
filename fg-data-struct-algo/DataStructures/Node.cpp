#include "Node.h"
#include <iostream>

Node::Node()
{
    this->position_ = vector2(0, 0);
    this->id_ = 0;
    this->neighbors_ = std::list<Node*>();
}

void Node::add_neighbor(Node* neighbour)
{
    this->neighbors_.push_back(neighbour);
}

void Node::print_neighbors() const
{
    std::cout << "Printing neighbours for node " << this->id_ << std::endl;
    for (Node* neighbor : this->neighbors_)
    {
        std::cout << neighbor->get_position().x << " " << neighbor->get_position().y << std::endl;
    }
}