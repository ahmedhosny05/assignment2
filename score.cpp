#include "score.h"
#include <QFont>

Score :: Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)

{
    score =0;

    setPlainText( " Score :" + QString::number(score ) );
    setDefaultTextColor(Qt:: blue );
    setFont(QFont(" times " ,16))  ;
}

void Score:: increase()
{
    score++ ;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score :: getscore()
{
    return score ;
}
