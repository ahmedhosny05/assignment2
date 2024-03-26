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






};

#endif // PLAYER_H
