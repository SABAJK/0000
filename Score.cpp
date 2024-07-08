#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    score = 0;
}

void Score::increase()
{
    score += 25;
}

int Score::getScore() const
{
    return score;
}

void Score::setScore(int scr)
{
    score = scr;
}
