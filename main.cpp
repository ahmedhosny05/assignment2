
#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include "player.h"
#include <QTimer>
#include <QDebug>
#include <QBrush>
#include <QGraphicsPixmapItem>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    // ******* Create the Scene ********

    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    // create view
    QGraphicsView * view = new QGraphicsView(scene);
    view->setFixedSize(800,600);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);




     // *******  Create the Player ********

    QPixmap playerpix(":/icons/resources/spaceship.png");
    playerpix=playerpix.scaledToWidth(50) ;
    playerpix=playerpix.scaledToHeight(60) ;
    Player *  player = new Player() ;
    player->setPixmap(playerpix) ;
    player->setPos(10,450) ;







    // *******  Setting the foucs to the Player ********

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus() ;

    // *******  Adjust the location of the Player (middle of the screen) ********

player->setPos(view->width() / 2 , view->height() - playerpix.height());
 scene ->addItem(player);

   // *******   Assign scene to the view   ***************

      view->setScene(scene);


    // *******  Create the Enemies automatically ********
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),player,SLOT(createEnemy()));
    time->start(2000);

    view->show();


    return a.exec();
}
