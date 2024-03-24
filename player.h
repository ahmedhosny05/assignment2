#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QObject>
#include <QMessageBox>
#include <QGraphicsTextItem>

class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
public:
    void keyPressEvent(QKeyEvent * event);


public slots:
    void createEnemy();
    void increase () ;
    void decrease() ;


private :
    int score =0 ;
    int health = 3 ;

};

#endif // PLAYER_H
