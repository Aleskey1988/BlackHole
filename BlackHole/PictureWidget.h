
#ifndef PICTUREWIDGET
#define PICTUREWIDGET

#include <QWidget>
#include <QTime>

class PictureWidget : public QWidget {
public:
	PictureWidget( const double angle, const double angleStep,
				   const int numLines,
				   const int lineLenght,
				   const int timerInterval,
				   const int width, const int height );

	void stopTimerAnimation();

public slots:
	void startTimerAnimation();
	void setAngle( const double angle );
	void setAngleStep( const double angleStep );
	void setNumLines( const int numLines );
	void setLineLenght( const double lineLenght );
	void setTimerInterval( const int timerInterval );
	void setWidth( const int width );
	void setHeight( const int height );

protected:
	virtual void paintEvent( QPaintEvent *e );

private slots:
	void incrementAngle();

private:
	double angle;
	double angleStep;
	int numLines;
	int lineLenght;
	int timerInterval;
	int width;
	int height;
	
	QTimer timer;
};

#endif
