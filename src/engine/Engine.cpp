#include "Engine.h"

#include <cstdlib>
#include <time.h>
#include <unistd.h>

int statusGlobal[MAX_NO];
int numberInfected;
int numberVacinated;
int numberContagion;
int numberDeaths;

Engine::Engine()
{
    std::fill_n(statusGlobal, MAX_NO, 0);
    contagionPercent = 50;
    deathPercent = 5;
    curePercent = 0;

    numberInfected = 1;
    numberVacinated = 0;
    numberContagion = 0;
    numberDeaths = 0;
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
    for(int i = 0; i < MAX_VALUE; ++i) {
        for (int j = 0; j < MAX_VALUE; ++j) {
            //TODO integração das laterais
            if (i > 0 && i < MAX_VALUE-1 && j > 0 && j < MAX_VALUE-1) {
                addEdge((MAX_VALUE*i)+j,(MAX_VALUE*(i-1))+j-1);  /* lado \  */
                addEdge((MAX_VALUE*i)+j,(MAX_VALUE*(i-1))+j);    /* lado |  */
                addEdge((MAX_VALUE*i)+j,(MAX_VALUE*(i-1))+j+1);  /* lado /  */
                addEdge((MAX_VALUE*i)+j,(MAX_VALUE*i)+j+1);      /* lado - direita */
                addEdge((MAX_VALUE*i)+j,(MAX_VALUE*(i+1))+j+1);  /* lado \  */
                addEdge((MAX_VALUE*i)+j,(MAX_VALUE*(i+1))+j);    /* lado |  */
                addEdge((MAX_VALUE*i)+j,(MAX_VALUE*(i+1))+j-1);  /* lado /  */
                addEdge((MAX_VALUE*i)+j,(MAX_VALUE*(i))+j-1);    /* lado -  esquerda */
            }
        }
    }

    // for (int i=0; i < MAX_VALUE-1; ++i) {

    //     addEdge((i),i+1);        // linha superior
    //     addEdge((i), (MAX_VALUE+i)); //liga topo ao centro
    //     addEdge((i), (MAX_VALUE+i+1)); //liga topo ao centro
    //     addEdge((i), (MAX_VALUE+i-1)); //liga topo ao centro

    //     addEdge((MAX_VALUE*i),(MAX_VALUE*(i+1)));  // coluna esquerda
    //     addEdge((MAX_VALUE*i), (MAX_VALUE*i+1)); //liga col esquerda ao centro

    //     addEdge((MAX_VALUE*(i+1)-1),((MAX_VALUE*(i+2))-1));  // coluna direita
    //     addEdge((MAX_VALUE*(i+1)-1), (MAX_VALUE*(i+1)-2));//liga col direita ao centro

    //     addEdge( ((MAX_NO-MAX_VALUE)+i), ((MAX_NO-MAX_VALUE)+(i+1)) );  // linha inferior
    //     addEdge(((MAX_NO-MAX_VALUE)+i), ((MAX_NO-MAX_VALUE)-MAX_VALUE+i));//liga o de baixo ao centro

    // }

    // ligar ultimo nó
    //    addEdge(1599, 1598);
    //    addEdge(1599, 1557);
    //    addEdge(1599, 1558);
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

    while(numberInfected+numberVacinated < MAX_NO-156)
    {
        moviment = rand()%4;

        switch (moviment)
        {
        case 0:
            if( nextPosY+1 < MAX_VALUE-1)
            nextPosY+=1;
            break;
        case 1:
            if( nextPosX+1 < MAX_VALUE-1)
            nextPosX+=1;
            break;
        case 2:
            if( nextPosY-1 > 0 )
            nextPosY-=1;
            break;
        case 3:
            if( nextPosX-1 > 0 )
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
        usleep(3000);
    } 

}

std::string Engine::conversorMapa(int x, int y) {
    std::string tempMapa;
    // bloqueado bota asterisco com azul d
    if(statusGlobal[MAX_VALUE*x+y] == -2){
        tempMapa = tempMapa + "\x1B[31mX\033[0m ";
    }else if(statusGlobal[MAX_VALUE*x+y] == 192) 
    {
        tempMapa = tempMapa + "\x1B[34mV\033[0m ";
    } else if(statusGlobal[MAX_VALUE*x+y] == 1618)
    {
        tempMapa = tempMapa + "\x1B[32mC\033[0m ";
    } else if(statusGlobal[MAX_VALUE*x+y] == 190)
    {
        tempMapa = tempMapa + "\x1B[35mA\033[0m ";
    } else
    {
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

    for (int i = 1; i < MAX_VALUE-1 ; i++) {
        for (int j = 1; j < MAX_VALUE-1 ; j++) {
            tempMapa = tempMapa + conversorMapa(i,j);

            if (j == 38) {
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
        if( v == -1 && rand() % 100 < deathPercent )
        {
            v = -2;
            numberDeaths++;
            numberInfected--;
        }
    }
    usleep(5000000);
    }

}

void Engine::vivaSUS(int x, int y)
{
    std::queue<int> S;
    bool marked[MAX_NO];
    int nodeTemp;

    std::fill_n( marked, MAX_NO, false);

    S.push(MAX_VALUE*x+y);
    marked[MAX_VALUE*x+y] = true;

    statusGlobal[MAX_VALUE*x+y] = 190;

    while(!S.empty())
    {
        nodeTemp = S.front();
        S.pop();

        for(auto i : adj[nodeTemp])
        {
            if(!marked[i])
            {             
                // std::cout << printEdge(nodeTemp, i) << '\n'; 
                if(statusGlobal[nodeTemp] == 0)
                {
                    statusGlobal[nodeTemp] = 192;
                    numberVacinated++;
                } else if (statusGlobal[nodeTemp] == -1) {
                    statusGlobal[nodeTemp] = 1618;
                    numberVacinated++;
                    numberInfected--;
                }
                marked[i] = true;
                S.push(i);
            }
        }
        usleep(40000);
    }
    
}

void Engine::imunidadeDeRebanho(int init)
{
    std::queue<int> S;

    markedClass[init] = true;

    for(auto line : adj[init])
    {
        if( !markedClass[line] )
        {
            // std::cout << printEdge(init, line) << '\n';
            markedClass[line] = true;
            if(statusGlobal[line] == 0)
            {
                statusGlobal[line] = 192;
                numberVacinated++;
                numberInfected--;
            } else if (statusGlobal[line] == -1) {
                statusGlobal[line] = 1618;
                numberVacinated++;
                numberInfected--;
            }
            imunidadeDeRebanho(line);
        }
        usleep(20000);
    } 
}