#include "Pillaritem.h"
#include <QRandomGenerator>
#include <QGraphicsScene>

PillarItem::PillarItem()
{
    topPiller = new QGraphicsPixmapItem(QPixmap(":/images/pipe_down.png"));
    bottomPiller = new QGraphicsPixmapItem(QPixmap(":/images/pipe_up.png"));

    topPiller->setPos(QPointF(0,0)-QPointF(topPiller->boundingRect().width()/2, topPiller->boundingRect().height() + 60));
    bottomPiller->setPos(QPointF(0,0)-QPointF(topPiller->boundingRect().width()/2,  -60));

    addToGroup(topPiller);
    addToGroup(bottomPiller);

    int yPos = QRandomGenerator::global()->bounded(150);//手動新增 0 <= yPos <= 150
    int xOffset = QRandomGenerator::global()->bounded(20);//手動新增 0 <= xOffset <= 20
    setPos(QPoint(0,0) + QPoint(256 + xOffset, yPos)); // 256:x螢幕大小

    // move toward left
    xAnimation = new QPropertyAnimation(this, "x", this);// 1st this:self, 2nd this: parent, used for del..
    // define start and end
    xAnimation->setStartValue(256 + xOffset);
    xAnimation->setEndValue(-256);
    // define moving method and duration
    xAnimation->setEasingCurve(QEasingCurve::Linear);
    xAnimation->setDuration(1500); // ms

    connect(xAnimation, &QPropertyAnimation::finished, [=](){
        scene()->removeItem(this);
        delete this;
    }); //lamda expr. "[=]" means that READ ONLY of this func.

    xAnimation->start();
}

PillarItem::~PillarItem()
{
    delete topPiller;
    delete bottomPiller;
}

qreal PillarItem::x() const
{
    return m_x;
}

void PillarItem::setx(qreal newX)
{
    m_x = newX;
    setPos(QPointF(0,0) + QPointF(newX, pos().y()));
}
