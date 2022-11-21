#pragma once

constexpr int horizontal{40};
constexpr int vertical{40};
 
class Plane2D
{   
    public:
        int mapXY[horizontal][vertical];
        Plane2D();
        ~Plane2D();
        
        int getMapXY(int x, int y);
};
