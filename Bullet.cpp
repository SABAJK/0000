#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QDebug>
#include <QApplication>
#include <QPropertyAnimation>
#include "Zombie.h"
#include "Game.h"

extern Game *game;

Bullet::Bullet(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem(parent)
{
    //draw graphics
    setPixmap(QPixmap(":/R.png"));
    //connect
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}
void Bullet::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0,n = colliding_items.size();i < n;++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Zombie))
        {
            //remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    setPos(x()+10,y());
    if(pos().x() + 15 > 1080)//agar az safhe kharej she
    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "Enemy deleted";
    }
}
