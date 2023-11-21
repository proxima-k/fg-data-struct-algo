#ifndef GRAPH_H
#define GRAPH_H

#include <list>

#include "vector2.h"


class Node
{
public:
    // Node (vector2 position, int id, std::list<Node> neighbors);
    // constructor
    vector2 get_position() const { return position; }
    int get_id() const { return id; }
    std::list<Node> get_neighbours() const { return neighbors; }

private:
    vector2 position;
    int id;
    std::list<Node> neighbors;
};

class Graph
{
public:
    // constructor
    // breadth first search
    // depth first search
    // a* search
    
private:
    std::list<Node> nodes;
};

#endif // GRAPH_H