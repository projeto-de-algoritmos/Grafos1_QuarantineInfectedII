#include <QApplication>

#include "gui/HelloWorld.h"
#include "graph/Graph.h"
#include "plane2D/Plane2D.h"
#include "engine/Engine.h"

#include <thread>
#include <unistd.h>

Engine run;

void imprime(){
	while( 1 ) 
	{
		std::cout << run.imprimirPlano();

		std::cout << "number of infected: " << numberInfected << '\n';
		std::cout << "number of vacinated: " << numberVacinated << '\n';
		std::cout << "number of deaths: " << numberDeaths << '\n';
		sleep(1);
		system("clear");

	}	
}

void case1() {
	run.createNodesAndVerticesWithMap();
	std::thread t1(&Engine::generateContagion, run, 13, 13);
	std::thread t2(&Engine::rollDeath, run);
	std::thread t3(&Engine::vivaSUS, run, 3,35);

	imprime();
}

void case2() {
	run.createNodesAndVerticesWithMap();
	std::thread t4(&Engine::generateContagion, run, 13, 13);
	std::thread t5(&Engine::rollDeath, run);
	std::thread t6(&Engine::vivaSUS, run, 3,35);
	std::thread t7(&Engine::vivaSUS, run, 35,3);

	imprime();
}

void case3() {
	run.createNodesAndVerticesWithMap();
	std::thread t11(&Engine::generateContagion, run, 13, 13);
	std::thread t22(&Engine::rollDeath, run);
	std::thread t66(&Engine::imunidadeDeRebanho, run, MAX_VALUE*33+37);
	statusGlobal[MAX_VALUE*33+37] = 190;


	imprime();
}


int main(int argc, char *argv[])
{


  int menu{0};

	Engine run;
	run.createNodesAndVerticesWithMap();

    system("clear");

     // coloque false para testar as buscas nos nós


        std::cout << "Escolha a configuração da simulação: " << '\n';
        std::cout << "1. BFS - 1 contaminado e 1 agente de saúde" << '\n';
        std::cout << "2. BFS - 1 contaminado e 2 agentes de saúde " << '\n';
        std::cout << "3. DFS - 1 contaminado e 1 agentes de saúde" << '\n';

        std::cout << "0. Sair" << '\n';

        std::cin >> menu;

        system("clear");
		
        switch (menu) 
		{
            case 1 :
				case1();
                break;
            case 2 :
				case2();
                break;
            case 3 :
				case3();
                break;
            case 0 :
                return 0;
                break;
            default:
                std::cout << "Escolha invalida!" << '\n';
				sleep(3);
				return 0;

        }

	return 0;

	// return QApplication::exec();
}
