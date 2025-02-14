#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentCircle(nullptr)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QPointF scenePos = ui->graphicsView->mapToScene(event->pos());
    QGraphicsItem *item = scene->itemAt(scenePos, QTransform());

    if (event->button() == Qt::LeftButton)
    {
        if (item == nullptr)
        {
            currentCircle = scene->addEllipse(scenePos.x(), scenePos.y(), 50, 50, QPen(Qt::black), QBrush(Qt::yellow));
            currentCircle->setFlag(QGraphicsItem::ItemIsMovable, true);
            currentCircle->setFlag(QGraphicsItem::ItemIsSelectable, true);
            currentCircle->setFlag(QGraphicsItem::ItemChildRemovedChange,true);
        }
    }
    else if (event->button() == Qt::RightButton && item != nullptr)
    {
        delete item;
    }

    QMainWindow::mousePressEvent(event);
}
