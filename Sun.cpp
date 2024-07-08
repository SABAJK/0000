#include "Sun.h"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>

Sun::Sun(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/sun.png"));

    // Timer to remove sun after 3 seconds
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Sun::removeSun);
    timer->start(3000); // 3 seconds
}

void Sun::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
    delete this; // Remove sun from the scene
}

void Sun::removeSun()
{
    scene()->removeItem(this);
    delete this;
}
