#include "widget.h"
#include "ui_widget.h"
#include "Pillaritem.h"
#include <QGraphicsPixmapItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget), scene(new Scene(this))
{
    ui->setupUi(this);
    scene->setSceneRect(-144,-256,288,512);
    QGraphicsPixmapItem *pixItem = new QGraphicsPixmapItem(QPixmap(":/images/background.png"));
    pixItem->setPos(-144,-256);
    scene->addItem(pixItem);

    scene->addLine(-144,0,144,0,QPen(Qt::blue));
    scene->addLine(0,-256,0,256,QPen(Qt::blue));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setFixedSize(288,512);

    //這種方式不會動
//    PillarItem *pillar = new PillarItem();
//    scene->addItem(pillar);

    //利用 timer
}

Widget::~Widget()
{
    delete ui;
//    delete scene; //會自動del. 因為scene也是QObject
}

