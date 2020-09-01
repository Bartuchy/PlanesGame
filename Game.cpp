#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QImage>

Game::Game(QWidget *parent)
{
    //create a scene
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,1000); //set 0,0 pos at left up corner
    setBackgroundBrush(QBrush(QImage(":/Images/bg.png")));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,1000);

    //create the player
    Player *player = new Player();
    player->setPos(200,500);
    scene->addItem(player);

    //make the player focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //create the score/health
    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);

    //spawn enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    show();
}
