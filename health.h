#ifndef HEALTH_H
#define HEALTH_H

#include <QObject>

class Health : public QObject
{
    Q_OBJECT

public:
    explicit Health(QObject *parent = nullptr);
    ~Health();

    void decrease();
    int getHealth() ;
    bool isGameOver() ;

signals:
    void gameOver(int finalScore);

private:
    int health;
};

#endif // HEALTH_H
