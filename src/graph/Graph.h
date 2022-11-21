#pragma once

#include <iostream>
#include <list>
#include <queue>
#include <stack>

constexpr int MAX_NO {1600};
constexpr int MAX_VALUE { 40 };

class Graph
{
    private:
        int v = MAX_NO;
        bool *contaminated = new bool[v];
        bool *blocked = new bool[v];
    public:

        Graph();
        Graph(int v);
        ~Graph();
        std::list<int> *adj;
        int getGraphSize();
        void addEdge(int u, int v);
        void addEdgeOneDirection(int u, int v);
        std::string printEdge(int u, int v);

        void breadthFirstSearch(int init);

        int getV();
        void setV(int v);

        void getAdj(std::list<int> vetor[]);
        void setAdj();

};