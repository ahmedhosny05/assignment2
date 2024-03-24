#include "player.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QGraphicsScene>
#include <QDebug>
#include "enemy.h"
#include <QMessageBox>
#include <QGraphicsTextItem>
Player::Player(  )
{
     ;
 }


void Player::keyPressEvent(QKeyEvent *event)
{
        // *******  Event Handling for the Player ********
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0) // to prevent the player from getting out of the screen
        {
        setPos(x()-10,y());
        }
    }
    else if(event->key()== Qt::Key_Right)

    { if(x()+100<800) // to prevent the player from getting out of the screen
        setPos(x()+10,y());
    }
    else if(event->key()== Qt::Key_Space)
    {
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+30,y());
        scene()->addItem(bullet);

    }


}
 // CreateEnemy function used to create the eneimes
void Player::createEnemy()
{ Enemy* enemy = new Enemy();
  scene()->addItem(enemy);

}


void Player::increase() {
    score++; // Assuming score is a member variable of Player class
    QGraphicsTextItem *scoreText = new QGraphicsTextItem();
    scoreText->setPlainText(QString("Score: ") + QString::number(score));
    scoreText->setDefaultTextColor(Qt::blue);
    // Add scoreText to scene if needed
}

void Player::decrease() {
    health--; // Assuming health is a member variable of Player class
    QGraphicsTextItem *healthText = new QGraphicsTextItem();
    healthText->setPlainText(QString("Health: ") + QString::number(health));
    healthText->setDefaultTextColor(Qt::red);
}
