#include <QApplication>

#include "gui/HelloWorld.h"
#include "graph/Graph.h"
#include "plane2D/Plane2D.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	HelloWorld hello;
	hello.show();

	Graph g(8);
    Plane2D plane;

	g.addEdge(1,4);
	g.addEdge(1,2);
	g.addEdge(1,5);
	g.addEdge(4,5);
	g.addEdge(4,2);
	g.addEdge(2,6);

    std::cout << "BFS ---------------------- " << '\n';

	g.breadthFirstSearch(6);

    std::cout << "DFS ---------------------- " << '\n';

    g.deepFirstSearch(6);

    for( auto & f : plane.mapXY )
    {
        for( auto & e : f )
            std::cout << e << " ";
        std::cout << '\n';
    }

	return QApplication::exec();
}
