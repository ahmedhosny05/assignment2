#include"bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <enemy.h>
#include <player.h>
#include"score.h"


extern Score * score ;
Bullet::Bullet():QObject(), QGraphicsPixmapItem() {

        // *******  Setting the bullets' size ********
    QPixmap laser(":/resources/laser.jpg");
    setPixmap(laser.scaledToWidth(30)) ;
    setPixmap(QPixmap(":/resources/laser.jpg").scaled(10, 80));

        // *******  Generating the Bullets automatically ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(20);
}

// Move function is used to 1-  move the bullet upwards
                         // 2- Handle the collision of the bullets with enemies
// *******  Getting the colliding items with the Bullet ********

void Bullet:: move()
{

    QList<QGraphicsItem*> collided_items=collidingItems() ;
    for(int i = 0 ; i<collided_items.size();i++)
    {

        if(typeid(*(collided_items[i]))==typeid(Enemy))
        {
            score->increase() ;
            scene()->removeItem(collided_items[i]);
            scene()-> removeItem(this);
            delete this ;
            delete collided_items[i] ;
            return ;
        }


    }   // *******  Moving the bullets upward ********

    setPos(x(),y()-10);
    if(pos().y()+pixmap().height()<0)
    {
        scene()->removeItem(this);
        delete this ;
    }

}
