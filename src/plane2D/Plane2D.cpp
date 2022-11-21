#include "Plane2D.h"

#include <algorithm>

Plane2D::Plane2D()
{
   for(auto & v : mapXY)
       for(auto & e: v)
           e = 0;
}

Plane2D::~Plane2D() = default;

int Plane2D::getMapXY( int x, int y )
{
    return mapXY[x][y];
} 
