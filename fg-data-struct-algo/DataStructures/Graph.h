#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include "vector2.h"


class Node
{
public:
    // constructor
    Node();
    Node(vector2 position, int id, std::list<Node> neighbors);

    vector2 get_position() const { return position_; }
    int get_id() const { return id_; }
    const std::list<Node>& get_neighbours() const;
    // std::list<Node> get_neighbours();
    void print_neighbours() const;

    void set_position(const vector2 position) { this->position_ = position; }
    void set_id(int id) { this->id_ = id; }
    void add_neighbour(Node neighbour);
    
    std::list<Node> neighbors_;
private:
    vector2 position_;
    int id_;
};


class Graph
{
public:
    // constructor
    // breadth first search
    // depth first search
    // a* search

    void set_width(int width) { this->width_ = width; }
    void set_height(int height) { this->height_ = height; }

    void print_graph() const;
    
    void add_node(Node node);
    std::list<Node> get_nodes() const { return nodes; }
    bool breadth_first_search(Node start, Node end) const;

    std::list<Node> nodes;
    
private:
    int width_ = 0;
    int height_ = 0;
};

#endif // GRAPH_H