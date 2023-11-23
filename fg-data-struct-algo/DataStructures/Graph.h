#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include "Node.h"

class Graph
{
public:
    // constructor
    // breadth first search
    // depth first search
    // a* search

    void set_width(int width) { this->width_ = width; }
    void set_height(int height) { this->height_ = height; }

    std::list<Node*> get_nodes() const { return nodes_; }
    
    void add_node(Node* node);
    void print_graph();
    bool breadth_first_search(Node* start, Node* end) const;
    bool depth_first_search(Node* start, Node* end) const;

    // void print_graph() const;
    ~Graph();
    
private:
    int width_ = 0;
    int height_ = 0;
    std::list<Node*> nodes_;
};

#endif // GRAPH_H