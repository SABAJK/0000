#ifndef SUN_H
#define SUN_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QObject>

class Sun : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Sun(QGraphicsItem *parent = 0);

signals:
    void clicked();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private slots:
    void removeSun();

private:
    QTimer *timer;
};

#endif // SUN_H
