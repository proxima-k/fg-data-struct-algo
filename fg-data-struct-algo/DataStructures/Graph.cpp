#include "Graph.h"

#include <queue>

void Graph::add_node(Node node)
{
    nodes.push_back(node);
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
