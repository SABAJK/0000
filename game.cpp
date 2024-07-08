#include "game.h"
#include "ui_game.h"
#include "score.h"
#include "sun.h"
#include <QImage>
#include <QBrush>
#include <QDebug>
#include <QTimer>
#include <QMouseEvent>
#include <stdlib.h> // for rand()

Game::Game(QWidget *parent): QDialog(parent), ui(new Ui::Game)
{
    ui->setupUi(this);

    // Create and add a plant
    plant = new Peashooter();
    ui->graphicsView->scene()->addItem(plant);

    qDebug() << "plant made\n";

    score = new Score();
    ui->labelScore->setText(QString::number(score->getScore()));
    ui->graphicsView->scene()->addItem(score);

    // Spawn bullets
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, plant, &Peashooter::spawn);
    timer->start(plant->getFiringRate() * 1000); // Adjusted to use the firingRate of the plant

    // Timer to spawn suns
    sunTimer = new QTimer(this);
    connect(sunTimer, &QTimer::timeout, this, &Game::spawnSun);
    sunTimer->start(5000);

    show();
}

Game::~Game()
{
    delete ui;
}

void Game::mousePressEvent(QMouseEvent *event)
{
    // Get the click position
    QPointF clickPos = event->pos();
    int x = clickPos.x();
    int y = clickPos.y();

    // Calculate grid position (assuming 6x12 grid)
    int cellWidth = ui->graphicsView->scene()->width() / 12;
    int cellHeight = ui->graphicsView->scene()->height() / 6;
    int gridX = x / cellWidth;
    int gridY = y / cellHeight;

    // Only allow planting on the right side (6x6 grid on the right)
    if (gridX > 0 && gridX <= 6)
    {
        int plantX = gridX * cellWidth;
        int plantY = gridY * cellHeight;

        // Position the plant
        plant->setPos(plantX, plantY);
    }
}

void Game::spawnSun()
{
    int x = rand() % static_cast<int>(960 - 200); // Random x position
    int y = rand() % static_cast<int>(480 - 100); // Random y position

    Sun *sun = new Sun();
    sun->setPos(x, y);
    connect(sun, &Sun::clicked, this, &Game::increaseScore);
    ui->graphicsView->scene()->addItem(sun);
}

void Game::increaseScore()
{
    score->increase();
    ui->labelScore->setText(QString::number(score->getScore()));
}
