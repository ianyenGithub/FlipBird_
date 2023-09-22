#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QTimer>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);

signals:

private:
    void setupPillarTimer();
    QTimer *pillarTimer; // 繼承 QObject
};

#endif // SCENE_H
