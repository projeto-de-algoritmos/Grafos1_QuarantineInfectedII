#include "Engine.h"

#include <cstdlib>
#include <time.h>
#include <unistd.h>

int statusGlobal[MAX_NO];
int numberInfected;
int numberVacinated;
int numberContagion = 0;

Engine::Engine()
{
    std::fill_n(statusGlobal, MAX_NO, 0);
    contagionPercent = 50;
    deathPercent = 1;
    curePercent = 0;

    numberInfected = 0;
    numberVacinated = 0;
}

Engine::~Engine() = default;

void Engine::createNodesAndVerticesWithMap()
{
/*
    Essa seria a integração dos nós
       *  *  *
        \ | /
       *- 0 -*
        / | \
       *  *  *
*/
    for(int i = 0; i < MAX_VALUE; i++) {
        for (int j = 0; j < MAX_VALUE; j++) {
            //TODO integração das laterais
            if (i > 0 && i < MAX_VALUE-1 && j > 0 && j < MAX_VALUE-1) {
                addEdgeOneDirection((MAX_VALUE*i)+j,(MAX_VALUE*(i-1))+j-1);  /* lado \  */
                addEdgeOneDirection((MAX_VALUE*i)+j,(MAX_VALUE*(i-1))+j);    /* lado |  */
                addEdgeOneDirection((MAX_VALUE*i)+j,(MAX_VALUE*(i-1))+j+1);  /* lado /  */
                addEdgeOneDirection((MAX_VALUE*i)+j,(MAX_VALUE*i)+j+1);      /* lado -  */
                addEdgeOneDirection((MAX_VALUE*i)+j,(MAX_VALUE*(i+1))+j+1);  /* lado \  */
                addEdgeOneDirection((MAX_VALUE*i)+j,(MAX_VALUE*(i+1))+j);    /* lado |  */
                addEdgeOneDirection((MAX_VALUE*i)+j,(MAX_VALUE*(i+1))+j-1);  /* lado /  */
                addEdgeOneDirection((MAX_VALUE*i)+j,(MAX_VALUE*(i))+j-1);    /* lado -  */
            }
        }
    }

    for (int i=0; i < MAX_VALUE-1; i++) {
        addEdgeOneDirection((i),i+1);        // linha superior
        addEdgeOneDirection((i), (MAX_VALUE+i)); //liga topo ao centro

        addEdgeOneDirection((MAX_VALUE*i),(MAX_VALUE*(i+1)));  // coluna esquerda
        addEdgeOneDirection((MAX_VALUE*i), (MAX_VALUE*i+1)); //liga col esquerda ao centro

        addEdgeOneDirection((MAX_VALUE*(i+1)-1),((MAX_VALUE*(i+2))-1));  // coluna direita
        addEdgeOneDirection((MAX_VALUE*(i+1)-1), (MAX_VALUE*(i+1)-2));//liga col direita ao centro

        addEdgeOneDirection( ((MAX_NO-MAX_VALUE)+i), ((MAX_NO-MAX_VALUE)+(i+1)) );  // linha inferior
        addEdgeOneDirection(((MAX_NO-MAX_VALUE)+i), ((MAX_NO-MAX_VALUE)-MAX_VALUE+i));//liga o de baixo ao centro

    }

    // ligar ultimo nó
       addEdgeOneDirection(1599, 1598);
       addEdgeOneDirection(1599, 1597);
       addEdgeOneDirection(1599, 1558);
}

void Engine::generateContagion(int x, int y)
{
    
    int xMap{x-1};
    int yMap{y-1};

    int nextPosX{xMap};
    int nextPosY{yMap};
    
    int moviment{0};

    statusGlobal[MAX_VALUE*xMap+yMap] = -1;
    std::srand( time( NULL ));

    while(numberInfected+numberVacinated < MAX_NO)
    {
        moviment = rand()%4;

        switch (moviment)
        {
        case 0:
            if( nextPosY+1 < MAX_VALUE)
            nextPosY+=1;
            break;
        case 1:
            if( nextPosX+1 < MAX_VALUE)
            nextPosX+=1;
            break;
        case 2:
            if( nextPosY-1 >= 0 )
            nextPosY-=1;
            break;
        case 3:
            if( nextPosX-1 >= 0 )
            nextPosX-=1;
            break;
        default:
            break;
        }

        if( statusGlobal[MAX_VALUE*nextPosX+nextPosY] == 0 )
        {
            if( rand()%101 > contagionPercent )
            {
                numberInfected++;
                xMap = nextPosX;
                yMap = nextPosY;
                statusGlobal[MAX_VALUE*xMap+yMap] = -1;
            }
            else {
                nextPosX = xMap;
                nextPosY = yMap;
            }

        } else if ( statusGlobal[MAX_VALUE*nextPosX+nextPosY] < 0 )
        {
            xMap = nextPosX;
            yMap = nextPosY;
        }
        usleep(5000);
    } 

}

std::string Engine::conversorMapa(int x, int y) {
    std::string tempMapa;
    // bloqueado bota asterisco com azul d
    if(statusGlobal[MAX_VALUE*x+y] == -2){
        tempMapa = tempMapa + "\x1B[31mX\033[0m ";
    }else{
        if ( statusGlobal[MAX_VALUE*x+y] == -1) {
            tempMapa = tempMapa + "\x1B[33m" + std::to_string(mapXY[x][y]) + "\033[0m" + " ";
        }else {
            tempMapa = tempMapa + std::to_string(mapXY[x][y]) + " ";
        }
    }

    return tempMapa;
}

std::string Engine::imprimirPlano() {
    std::string tempMapa;

    for (int i = 0; i < MAX_VALUE ; i++) {
        for (int j = 0; j < MAX_VALUE ; j++) {
            tempMapa = tempMapa + conversorMapa(i,j);

            if (j == 39) {
                tempMapa = tempMapa + '\n';
            }
        }
    }

    return tempMapa;
}

void Engine::rollDeath()
{
    srand( time( NULL ));

    while(1){

    for(auto & v : statusGlobal)
    {
        if( v == -1 && rand() % 101 < deathPercent )
            v = -2;
    }
    usleep(500000);
    }

}