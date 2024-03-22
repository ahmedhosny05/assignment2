#include"bullet.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <enemy.h>
#include <player.h>
Bullet::Bullet():QObject(), QGraphicsRectItem() {

        // *******  Setting the bullets' size ********
    setRect(0,0,10,50);

        // *******  Generating the Bullets automatically ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
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
            scene()->removeItem(collided_items[i]);
            scene()-> removeItem(this);
            delete this ;
            delete collided_items[i] ;
            return ;
        }


    }   // *******  Moving the bullets upward ********

    setPos(x(),y()-10);
    if(pos().y()+rect().height()<0)
    {
        scene()->removeItem(this);
        delete this ;
    }

}
