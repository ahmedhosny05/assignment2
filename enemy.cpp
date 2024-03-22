#include "enemy.h"
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> to generate really large integer
#include <QTimer>
#include <QDebug>
#include"player.h"
#include "gameover.h"

Enemy::Enemy() {
    // *******  Setting the size of the enemy ********
    QPixmap enemy(":/resources/download.jpeg");
    setPixmap(enemy.scaledToWidth(80)) ;
    setPixmap(QPixmap(":/resources/download.jpeg").scaled(60, 80));

    // *******  Setting the postion of the enemy within the view dimensions ********
    int random_number = rand() % 700;
    setPos(random_number,0);

    // *******  Moving the enemies downwards automatically every 50 milli second ********
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);

}
// Function move: move the enemy downwards untill the end of the scene then remove it and delete it
void Enemy:: move()
{
    setPos(x(),y()+5);
    if(y()+pixmap().height()>800)
    {
        scene()->removeItem(this);
        delete this;
    }
    QList<QGraphicsItem*> collided_items = collidingItems();
    for (int i = 0; i < collided_items.size(); i++) {
        if (typeid(*(collided_items[i])) == typeid(Player)) {
            // Remove the player and the enemy
            scene()->removeItem(collided_items[i]);
            scene()->removeItem(this);
            delete collided_items[i];
            delete this;

            // Display the game over UI
            gameover* game = new gameover();
            game->show();

            // Return from the function after displaying game over UI
            return;
        }
    }
}

