#include <QApplication>

#include "gui/HelloWorld.h"
#include "graph/Graph.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	HelloWorld hello;
	hello.show();

	Graph g(8);

    g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 5);
	g.addEdge(2, 6);
	g.addEdge(6, 7);

	g.breadthFirstSearch();

	return QApplication::exec();
}
