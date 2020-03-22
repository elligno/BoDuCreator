#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiAppBoduc.h"

class QtGuiAppBoduc : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiAppBoduc(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtGuiAppBoducClass ui;
};
