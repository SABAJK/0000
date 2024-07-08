#ifndef PLANT_H
#define PLANT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Zombie;

class Plant : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Plant(QGraphicsItem *parent = 0);

public slots:
    int getFiringRate();
    void spawn();
    virtual bool canGrow(int x, int y) const;
    virtual void birth(int c, int r);
    //virtual void normalAttack(Zombie *zombie);

protected:
    int hp;
    int row, col;
    bool canSelect;
    int attackPower;
    int firingRate;
    QString eName;
    int beAttackedPointR;
    int sunNum;
    QString path;
};

class Peashooter : public Plant
{
public:
    Peashooter(QGraphicsItem *parent = 0);
};

class TwoPeashooter : public Plant
{
public:
    TwoPeashooter(QGraphicsItem *parent = 0);
};

class Wallnut : public Plant
{
public:
    Wallnut(QGraphicsItem *parent = 0);
};

class PlumMine : public Plant
{
public:
    PlumMine(QGraphicsItem *parent = 0);
};

class Jalapeno : public Plant
{
public:
    Jalapeno(QGraphicsItem *parent = 0);
};

class Boomerang : public Plant
{
public:
    Boomerang(QGraphicsItem *parent = 0);
};

Plant *PlantFactory(const QString &eName);

#endif // PLANT_H
