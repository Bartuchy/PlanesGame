#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "Player.h"
#include "Health.h"
#include "Game.h"

extern Game *game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem()
{
    //set random position
    int random_number = rand() % 1000;
    setPos(random_number, 0);

    //drew enemy
    setPixmap(QPixmap(":/Images/Enemy.png"));
    setTransformOriginPoint(50,50);
    setRotation(180);

    //connect
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);


}

void Enemy::move()
{
    //move enemy down
    setPos(x(), y()+5);
    if(pos().y() > 1200){
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }

}

