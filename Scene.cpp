#include "Pillaritem.h"
#include "Scene.h"

Scene::Scene(QObject *parent)
    : QGraphicsScene{parent}
{
    setupPillarTimer();
}

void Scene::setupPillarTimer()
{
    pillarTimer = new QTimer(this);
    connect(pillarTimer, &QTimer::timeout, [=](){
        PillarItem *pillarItem = new PillarItem();
        addItem(pillarItem);
    });
    pillarTimer->start(1000);
}
