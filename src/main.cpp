#include <QApplication>

#include "gui/HelloWorld.h"
#include "graph/Graph.h"
#include "plane2D/Plane2D.h"
#include "engine/Engine.h"

#include <thread>
#include <unistd.h>

int main(int argc, char *argv[])
{
	Engine run;

	std::thread t1(&Engine::generateContagion, run, 13, 13);
	std::thread t2(&Engine::rollDeath, run);

	run.createNodesAndVerticesWithMap();

	// std::thread t3(&Engine::vivaSUS, run, 3,35);
	// std::thread t5(&Engine::vivaSUS, run, 35,3);

	std::thread t6(&Engine::imunidadeDeRebanho, run, MAX_VALUE*33+37);
	statusGlobal[MAX_VALUE*33+37] = 190;

	while( 1 ) 
	{
		std::cout << run.imprimirPlano();

		std::cout << "number of infected: " << numberInfected << '\n';
		std::cout << "number of vacinated: " << numberVacinated << '\n';
		std::cout << "number of deaths: " << numberDeaths << '\n';
		sleep(1);
		system("clear");

	}

	return 0;

	// return QApplication::exec();
}
