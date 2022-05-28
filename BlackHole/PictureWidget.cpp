
#include "stdafx.h"
#include "PictureWidget.h"

PictureWidget::PictureWidget(const double angle, const double angleStep,
    const int numLines,
    const int lineLenght,
    const int timerInterval,
    const int width, const int height)
{

    this->angle = angle;
    this->angleStep = angleStep;
    this->numLines = numLines;
    this->lineLenght = lineLenght;
    this->timerInterval = timerInterval;
    this->width = width;
    this->height = height;
    setFixedSize(width, height);

    connect(&timer, &QTimer::timeout, this, &PictureWidget::incrementAngle);
}

void PictureWidget::paintEvent(QPaintEvent *e)
{
    QPixmap *pixmap = new QPixmap(500, 500);
    //QPainter pixmapPainter( pixmap );
    QPainter widgetPainter(this);

    widgetPainter.setRenderHint(QPainter::Antialiasing, true);
    //pixmapPainter.setRenderHint( QPainter::Antialiasing, true );
    QPen pen;
    pen.setWidth(1);

    widgetPainter.translate(width / 2.0, height / 2.0);
    //pixmapPainter.translate( width / 2.0, height / 2.0 );

    for (int i = 0; i < numLines; ++i)
    {
        pen.setColor(QColor((i * 3) % 256, (i * 2) % 256, i % 256));
        widgetPainter.setPen(pen);
        widgetPainter.drawLine(0, 0, i * lineLenght, 0);
        widgetPainter.translate(i * lineLenght, 0);
        widgetPainter.rotate(angle);

        //pixmapPainter.setPen( pen );
        //pixmapPainter.drawLine( 0, 0, i * lineLenght, 0 );
        //pixmapPainter.translate( i * lineLenght, 0 );
        //pixmapPainter.rotate( angle );
    }

    //pixmap->save( "pixmap.png" );
}

void PictureWidget::stopTimerAnimation()
{
    timer.stop();
}

// public slots
void PictureWidget::startTimerAnimation()
{
    timer.start(timerInterval);
}
void PictureWidget::setAngle(const double angle)
{
    this->angle = angle;
    update();
}
void PictureWidget::setAngleStep(const double angleStep)
{
    this->angleStep = angleStep;
    update();
}
void PictureWidget::setNumLines(const int numLines)
{
    this->numLines = numLines;
    update();
}
void PictureWidget::setLineLenght(const double lineLenght)
{
    this->lineLenght = lineLenght;
    update();
}
void PictureWidget::setTimerInterval(const int timerInterval)
{
    this->timerInterval = timerInterval;
    timer.stop();
    timer.start(timerInterval);
}
void PictureWidget::setWidth(const int width)
{
    this->width = width;
    setFixedSize(width, height);
    update();
}
void PictureWidget::setHeight(const int height)
{
    this->height = height;
    setFixedSize(width, height);
    update();
}

// private slots
void PictureWidget::incrementAngle()
{
    angle += angleStep;
    update();
}