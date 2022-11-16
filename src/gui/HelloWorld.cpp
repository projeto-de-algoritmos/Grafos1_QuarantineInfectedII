#include "HelloWorld.h"

#include <iostream>
#include <QPushButton>
#include <QApplication>
#include <QSignalMapper>

HelloWorld::HelloWorld(QWidget *parent) :
	QWidget(parent) 
{
		setWindowTitle(QString("Quarantine Infected II"));
		setFixedSize(320,180);

		tela = new QLabel("0",this);
		tela->setAlignment(Qt::AlignHCenter);
		tela->setGeometry(10, 10, 310, 170);
		tela->setText( QString("Aqui eh uma amostra cachorra!"));


}

void HelloWorld::setTextLabel() 
{
	std::cout << "F demais" << '\n';
}
