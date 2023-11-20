#ifndef GRAPH_H
#define GRAPH_H

#include <list>

#include "vector2.h"


class Node
{
public:
    // Node (vector2 position, int id, std::list<Node> neighbors);
    // constructor
    vector2 Position() const { return position; }
    int ID() const { return id; }
    std::list<Node> Neighbours() const { return neighbors; }

private:
    vector2 position;
    int id;
    std::list<Node> neighbors;
};

class Graph
{
public:
    // constructor
private:
    std::list<Node> nodes;
};

#endif // GRAPH_H