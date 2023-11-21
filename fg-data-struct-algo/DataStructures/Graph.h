#ifndef GRAPH_H
#define GRAPH_H

#include <list>

#include "vector2.h"


class Node
{
public:
    // Node (vector2 position, int id, std::list<Node> neighbors);
    // constructor
    Node();
    Node(vector2 position, int id, std::list<Node> neighbors);
    
    vector2 get_position() const { return position_; }
    int get_id() const { return id_; }
    std::list<Node> get_neighbours() const { return neighbors_; }

    void set_position(const vector2 position) { this->position_ = position; }
    void set_id(int id) { this->id_ = id; }
    void add_neighbour(Node neighbour);
    
private:
    vector2 position_;
    int id_;
    std::list<Node> neighbors_;
};


class Graph
{
public:
    // constructor
    // breadth first search
    // depth first search
    // a* search

    void add_node(Node node);
    bool breadth_first_search(Node start, Node end) const;
    
private:
    std::list<Node> nodes;
};

#endif // GRAPH_H