#ifndef PILLARITEM_H
#define PILLARITEM_H

#include <QGraphicsItemGroup>
#include <QObject>
#include <QPropertyAnimation>
//#include <QGraphicsPixmapItem>

class PillarItem : public QObject, public QGraphicsItemGroup
{
    Q_OBJECT
    // DataType is qreal, 名稱是 x， 設定func. 是setx, NOTIFY (x 改變 會通知)
    Q_PROPERTY(qreal x READ x WRITE setx) // 之後refactor 就會自動生成
public:
    explicit PillarItem();//有parent del.會比較方便，但piller本身就會del.故不需要
    virtual ~PillarItem();

    qreal x() const;
    void setx(qreal newX);

signals:

private:
    QGraphicsPixmapItem *topPiller;
    QGraphicsPixmapItem *bottomPiller;
    QPropertyAnimation *xAnimation;
    qreal m_x; //Q_PROPERTY(qreal x READ x WRITE setx) define完成
};

#endif // PILLARITEM_H
