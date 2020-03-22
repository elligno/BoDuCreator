#include "QtGuiAppBoduc.h"

QtGuiAppBoduc::QtGuiAppBoduc(QWidget *parent)
	: QMainWindow(parent)
{
	// just testing access to the global variable qApp
	// since we are now inherit from QApplication
	auto w_checkVersion = qApp->applicationVersion();
	QDesktopWidget* w_desktop = qApp->desktop();

	ui.setupUi(this);
}
