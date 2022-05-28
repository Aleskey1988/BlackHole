
#include "stdafx.h"
#include "mainwindow.h"

MainWindow::MainWindow( QWidget *parent ) : QWidget( parent ) {
	ui.setupUi( this );

	this->move( 10, 10 );

	animationStarted = false;

	wgt = new PictureWidget( ui.m_angle->value(), ui.m_angleStep->value(), ui.m_numLines->value(), ui.m_lineLenght->value(), ui.m_timerInterval->value(), ui.m_widgetWidth->value(), ui.m_widgetHeight->value() );
	ui.pictureLayout->addWidget( wgt );

	connect( ui.m_startAnimation, &QPushButton::clicked, this, &MainWindow::startAnimation );
	connect( ui.m_angle, static_cast< void ( QDoubleSpinBox::* )( double ) >( &QDoubleSpinBox::valueChanged ), wgt, &PictureWidget::setAngle );
	connect( ui.m_angleStep, static_cast< void ( QDoubleSpinBox::* )( double )>( &QDoubleSpinBox::valueChanged ), wgt, &PictureWidget::setAngleStep );
	connect( ui.m_numLines, static_cast< void ( QSpinBox::* )( int ) >( &QSpinBox::valueChanged ), wgt, &PictureWidget::setNumLines );
	connect( ui.m_lineLenght, static_cast< void ( QDoubleSpinBox::* )( double ) >( &QDoubleSpinBox::valueChanged ), wgt, &PictureWidget::setLineLenght );
	connect( ui.m_timerInterval, static_cast< void ( QSpinBox::* )( int ) >( &QSpinBox::valueChanged ), wgt, &PictureWidget::setTimerInterval );
	connect( ui.m_widgetWidth, static_cast< void ( QSpinBox::* )( int ) >( &QSpinBox::valueChanged ), wgt, &PictureWidget::setWidth );
	connect( ui.m_widgetHeight, static_cast< void ( QSpinBox::* )( int ) >( &QSpinBox::valueChanged ), wgt, &PictureWidget::setHeight );

	connect( ui.m_frame, &QSlider::valueChanged, this, &MainWindow::searchFrame );
}

MainWindow::~MainWindow() {
	delete wgt;
}

// private slots
void MainWindow::startAnimation() {
	if( animationStarted ) {
		ui.m_startAnimation->setText( "Start" );
		wgt->stopTimerAnimation();
	} else {
		ui.m_startAnimation->setText( "Stop" );
		wgt->startTimerAnimation();
	}
	animationStarted = !animationStarted;
}

void MainWindow::searchFrame( const int value ) {
	ui.m_startAnimation->setText( "Start" );
	animationStarted = false;
	wgt->stopTimerAnimation();
	ui.m_angle->setValue( value / ( double )SLIDER_DECIMAL );
	wgt->update();
}