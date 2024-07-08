#include "Zombie.h"
#include "Bullet.h"
#include <QGraphicsScene>

Zombie::Zombie(QGraphicsItem *parent) : QGraphicsPixmapItem(parent), movementDelay(0),timeBetweenAttack(0), hp(0), row(0), col(0), canSelect(true), attackPower(0), eName(""), brainNum(0), path("")
{
}

RegularZombie::RegularZombie(QGraphicsItem *parent) : Zombie(parent)
{
    eName = "RegularZombie";
    timeBetweenAttack = 1;
    movementDelay = 1;
    attackPower = 25;
    brainNum = 100;
    hp = 500;
    path = ":/regular zombie_transparent.png";
    setPixmap(QPixmap(path));
}
BucketheadZombie::BucketheadZombie(QGraphicsItem *parent) : Zombie(parent)
{
    eName = "BucketheadZombie";
    timeBetweenAttack = 1;
    movementDelay = 2;
    attackPower = 50;
    brainNum = 200;
    hp = 1950;
    path = ":/Bucket head zombie_trasparent.png";
    setPixmap(QPixmap(path));
}

LeafhairZombie::LeafhairZombie(QGraphicsItem *parent) : Zombie(parent)
{
    eName = "LeafhairZombie";
    timeBetweenAttack = 1;
    movementDelay = 1;
    attackPower = 25;
    brainNum = 150;
    hp = 800;
    path = ":/leaf hair zombie_transparent.png";
    setPixmap(QPixmap(path));
}

TallZombie::TallZombie(QGraphicsItem *parent) : Zombie(parent)
{
    eName = "TallZombie";
    timeBetweenAttack = 1;
    movementDelay = 1;
    attackPower = 30;
    brainNum = 150;
    hp = 500;
    path = ":/tall zombie_transparent.png";
    setPixmap(QPixmap(path));
}

AstronautZombie::AstronautZombie(QGraphicsItem *parent) : Zombie(parent)
{
    eName = "AstronautZombie";
    timeBetweenAttack = 1;//speed up after hp <= 100 (0.5)
    movementDelay = 1;//speed up after hp <= 100 (0.5)
    attackPower = 20;
    brainNum = 200;
    hp = 500;
    path = ":/astronaut zombie_transparent.png";
    setPixmap(QPixmap(path));
}

PurplehairZombie::PurplehairZombie(QGraphicsItem *parent) : Zombie(parent)
{
    eName = "PurplehairZombie";
    timeBetweenAttack = 0.5;
    movementDelay = 1;
    attackPower = 75;
    brainNum = 800;
    hp = 4000;
    path = ":/purple hair zombie_transparent.png";
    setPixmap(QPixmap(path));
}

bool Zombie::canGrow(int x, int y) const
{
    // Implement logic to check if the Zombie can grow at (x, y)
    return true;
}

void Zombie::birth(int c, int r)
{
    // Implement logic for Zombie birth
}
