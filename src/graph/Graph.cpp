#include "Graph.h"

Graph::Graph()
{
    v = MAX_NO;
    adj = new std::list<int>[v];
}

Graph::Graph(int v)
{
    this->v = v;
    adj = new std::list<int>[v];
}

Graph::~Graph() = default;

int Graph::getGraphSize()
{
    return v;
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

std::string Graph::printEdge(int u, int v)
{
    return "(" + std::to_string(u) + " ," + std::to_string(v) + ")";
}

void Graph::breadthFirstSearch()
{
    for(int i{0}; i<v; i++)
    {
        for( auto triste : adj[i])
        {
            std::cout << printEdge(i,triste ) << '\n';
        }
    }
}

void Graph::breadthFirstSearch(int inicial)
{

}

int Graph::getV()
{
    return v;
}

void Graph::setV(int v)
{
    adj = new std::list<int>[v];
}

void Graph::getAdj(std::list<int> vetor[])
{
    *vetor = *adj;
}

void Graph::setAdj()
{
    adj = new std::list<int>[v];
}