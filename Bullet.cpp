#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"

extern Game *game; //there is an external global object called game

Bullet::Bullet(QGraphicsItem *parent): QObject(),QGraphicsPixmapItem(parent)
{
    //drew graphics
    setPixmap(QPixmap(":/Images/bullet.png"));

    //connect
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    //collision
    QList<QGraphicsItem *> colliding_items = collidingItems();
    int n=colliding_items.size();
    for(int i=0; i<n; i++){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            //increse the score
            game->score->increase();

            //remove bullet and enemy
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            delete colliding_items[i];
            delete this;
            return;
        }
    }

    //move  bullet up
    setPos(x(), y()-10);
    if(pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }

}
