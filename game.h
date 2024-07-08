#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QApplication>
#include <QTimer>
#include <QFont>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsRectItem>
#include <QPen>
#include "Plant.h"
#include "Zombie.h"
#include "Score.h"
#include "Sun.h"
#include <QDialog>

namespace Ui {
class Game;
}

class Game : public QDialog
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();
    //QGraphicsScene *scene;
    Plant *plant;
    Zombie *zombie;
    Score *score;

protected:
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void spawnSun();
    void increaseScore();

private:
    QTimer *sunTimer;
    Ui::Game *ui;
};
#endif // GAME_H

