#pragma once

#include "../plane2D/Plane2D.h"
#include "../graph/Graph.h"

extern int statusGlobal[MAX_NO];
extern int numberInfected;
extern int numberVacinated;
extern int numberContagion;

class Engine : public Graph, public Plane2D 
{
    public:
    int status[MAX_NO];
    u_int8_t contagionPercent;
    u_int8_t deathPercent;
    u_int8_t curePercent;



    Engine();
    ~Engine();

    void createNodesAndVerticesWithMap();
    void generateContagion(int x, int y);
    void rollDeath();

    std::string conversorMapa(int x, int y);
    std::string imprimirPlano();


};