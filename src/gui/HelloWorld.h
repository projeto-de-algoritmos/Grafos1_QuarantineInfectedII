#pragma once

#include <QWidget>
#include <QLabel>

class HelloWorld : public QWidget {
	Q_OBJECT
	public:
		explicit HelloWorld(QWidget *parent = 0);

	private:
		QLabel *tela;

	public slots:
		void setTextLabel();

signals:
};
