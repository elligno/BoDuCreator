#include "QtGuiAppBoduc.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtGuiAppBoduc w;
	w.show();
	return a.exec();
}
