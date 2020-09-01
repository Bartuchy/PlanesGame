#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/Images/Player.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        if(pos().x()>-200){
            setPos(x()-10,y());
        }
    }

    else if(event->key() == Qt::Key_Right){
        if(pos().x()<700){
            setPos(x()+10,y());
        }

    }

    else if(event->key() == Qt::Key_Up){
        if(pos().y()>-200){
            setPos(x(),y()-10);
        }

    }

    else if(event->key() == Qt::Key_Down){
        if(pos().y() < 700){
            setPos(x(),y()+10);
        }

    }

    else if(event->key() == Qt::Key_Space){
        Bullet *bullet = new Bullet;
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }
}

void Player::spawn()
{
    //create an enemy
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
