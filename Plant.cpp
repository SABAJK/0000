#include "Plant.h"
#include "Bullet.h"
#include <QGraphicsScene>
#include <QDebug>

Plant::Plant(QGraphicsItem *parent) : QGraphicsPixmapItem(parent), hp(0), firingRate(1), row(0), col(0), canSelect(true), attackPower(0), eName(""), beAttackedPointR(0), sunNum(0), path("")
{
}

Peashooter::Peashooter(QGraphicsItem *parent) : Plant(parent)
{
    eName = "oPeashooter";
    attackPower = 15;
    sunNum = 50;
    hp = 200;
    path = ":/peashooter transparent.png";
    firingRate = 1;
    setPixmap(QPixmap(path));
}

TwoPeashooter::TwoPeashooter(QGraphicsItem *parent) : Plant(parent)
{
    eName = "oTwoPeashooter";
    attackPower = 40;
    sunNum = 100;
    hp = 200;
    path = ":/two_peashooter_transparent.png";
    firingRate = 1;
    setPixmap(QPixmap(path));
}

Wallnut::Wallnut(QGraphicsItem *parent) : Plant(parent)
{
    eName = "oWallnut";
    attackPower = 0;
    sunNum = 100;
    hp = 400;
    path = ":/walnut_transparent.png";
    firingRate = 0;
    setPixmap(QPixmap(path));
}

PlumMine::PlumMine(QGraphicsItem *parent) : Plant(parent)
{
    eName = "oPlumMine";
    attackPower = 500;
    sunNum = 175;
    hp = 0;
    path = ":/plum mine_transparent.png";
    firingRate = 0;
    setPixmap(QPixmap(path));
}

Jalapeno::Jalapeno(QGraphicsItem *parent) : Plant(parent)
{
    eName = "oJalapeno";
    attackPower = 30;
    sunNum = 150;
    hp = 0;
    path = ":/jalapino_transparent.png";
    firingRate = 0;
    setPixmap(QPixmap(path));
}

Boomerang::Boomerang(QGraphicsItem *parent) : Plant(parent)
{
    eName = "oBoomerang";
    attackPower = 30;
    sunNum = 125;
    hp = 200;
    path = ":/boomrang_transparent.png";
    firingRate = 1; // Set firing rate to 1 second
    setPixmap(QPixmap(path));
}

int Plant::getFiringRate()
{
    return firingRate;
}

void Plant::spawn()
{
    // Create a bullet
    Bullet *bullet = new Bullet(nullptr);
    bullet->setPos(x(),y()+1);
    scene()->addItem(bullet);
    qDebug() << "bullet added\n";
}

bool Plant::canGrow(int x, int y) const
{
    // Implement logic to check if the plant can grow at (x, y)
    return true;
}

void Plant::birth(int c, int r)
{
    // Implement logic for plant birth
}
