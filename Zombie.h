#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "Plant.h"

class plant;

class Zombie : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Zombie(QGraphicsItem *parent = 0);

public slots:
    virtual bool canGrow(int x, int y) const;
    virtual void birth(int c, int r);
    //virtual void normalAttack(Plant *plant);

protected:
    int hp;
    int row, col;
    bool canSelect;
    int attackPower;
    QString eName;
    int brainNum;
    QString path;
    int timeBetweenAttack;
    int movementDelay;
};

class RegularZombie : public Zombie
{
public:
    RegularZombie(QGraphicsItem *parent = 0);
};

class AstronautZombie : public Zombie
{
public:
    AstronautZombie(QGraphicsItem *parent = 0);
};

class BucketheadZombie : public Zombie
{
public:
    BucketheadZombie(QGraphicsItem *parent = 0);
};

class LeafhairZombie : public Zombie
{
public:
    LeafhairZombie(QGraphicsItem *parent = 0);
};

class PurplehairZombie : public Zombie
{
public:
    PurplehairZombie(QGraphicsItem *parent = 0);
};

class TallZombie : public Zombie
{
public:
    TallZombie(QGraphicsItem *parent = 0);
};

#endif // ZOMBIE_H
