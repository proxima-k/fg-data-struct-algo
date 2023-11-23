#ifndef NODE_H
#define NODE_H

#include <iostream>

#include "vector2.h"
#include <list>

class Node
{
public:
    // constructor
    Node();
    Node(vector2 position, int id) : position_(position), id_(id) {};

    vector2 get_position() const { return position_; }
    int get_id() const { return id_; }
    std::list<Node*> get_neighbors() const { return neighbors_; }
    void print_neighbors_address() const { std::cout << &neighbors_ << std::endl; }

    void set_position(const vector2 position) { this->position_ = position; }
    void set_id(int id) { this->id_ = id; }
    void add_neighbor(Node* neighbour);

    void print_neighbors() const;
    
private:
    vector2 position_;
    int id_;
    std::list<Node*> neighbors_;
};

#endif // NODE_H