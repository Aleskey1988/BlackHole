
#pragma once

#include <QtWidgets/QWidget>
#include "ui_mainwindow.h"
#include "PictureWidget.h"

#define SLIDER_DECIMAL 1

class MainWindow : public QWidget {
	Q_OBJECT

public:
	MainWindow( QWidget *parent = Q_NULLPTR );
	~MainWindow();

private slots:
	void startAnimation();
	void searchFrame( const int value );

private:
	Ui::MainWindowClass ui;
	PictureWidget *wgt;
	bool animationStarted;
};
