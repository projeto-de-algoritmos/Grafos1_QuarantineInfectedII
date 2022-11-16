#include <QApplication>

#include "gui/HelloWorld.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	HelloWorld hello;
	hello.show();

	return QApplication::exec();
}
