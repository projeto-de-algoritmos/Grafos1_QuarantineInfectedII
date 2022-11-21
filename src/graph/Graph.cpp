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
    std::fill_n(markedClass, MAX_NO, false);
}

Graph::~Graph() = default;

int Graph::getGraphSize()
{
    return v;
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::addEdgeOneDirection(int u, int v)
{
    adj[u].push_back(v);
}

std::string Graph::printEdge(int u, int v)
{
    return "(" + std::to_string(u) + " ," + std::to_string(v) + ")";
}

void Graph::breadthFirstSearch(int inicial)
{
    std::queue<int> S;
    bool marked[MAX_NO];

    std::fill_n( marked, MAX_NO, false);

    S.push(inicial);
    marked[inicial] = true;

    while(!S.empty())
    {
        v = S.front();
        S.pop();

        for(auto i : adj[v])
        {
            if(!marked[i])
            {             
                std::cout << printEdge(v, i) << '\n'; 
                marked[i] = true;
                S.push(i);
            }
        }
    }
}

void Graph::deepFirstSearch(int init)
{
    std::queue<int> S;


    markedClass[init] = true;

    for(auto line :  adj[init])
    {
        if( !markedClass[line] )
        {
            std::cout << printEdge(init, line) << '\n';
            markedClass[line] = true;
            deepFirstSearch(line);
        }
    } 
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
