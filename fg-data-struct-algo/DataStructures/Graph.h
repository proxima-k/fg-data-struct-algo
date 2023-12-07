#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include "Node.h"

class Graph
{
public:
    std::list<Node*> get_nodes() const { return nodes_; }
    void add_node(Node* node);

    bool breadth_first_search(Node* start, Node* end) const;
    bool depth_first_search(Node* start, Node* end) const;

    void print_node_neighbors() const;
    ~Graph();
    
private:
    std::list<Node*> nodes_;
};

#endif // GRAPH_H