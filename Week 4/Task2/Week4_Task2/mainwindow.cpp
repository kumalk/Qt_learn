#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_circleButton_clicked()
{
    ShapeNo = 1;
}

void MainWindow::on_rectangleButton_clicked()
{
    ShapeNo = 2;
}

void MainWindow::on_triangleButton_clicked()
{
    ShapeNo = 3;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    clickPosition = event->pos();
    update();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter myQpainter(this);
    QPoint originPoint(500, 200); // Fixed origin point at (200, 200)
    QBrush myfill(Qt::yellow);
    QPen myPen(Qt::black);
    myPen.setWidth(3);
    myQpainter.setPen(myPen);
    myQpainter.setBrush(myfill);

    switch (ShapeNo) {
    case 1:
        myQpainter.drawEllipse(originPoint, 100, 100);
        break;
    case 2:
        myQpainter.drawRect(originPoint.x() - 100, originPoint.y() - 100, 200, 200);
        break;
    case 3: {
        QPolygon triangle;
        triangle << QPoint(originPoint.x(), originPoint.y() - 100)
                 << QPoint(originPoint.x() - 100, originPoint.y() + 100)
                 << QPoint(originPoint.x() + 100, originPoint.y() + 100);
        myQpainter.drawPolygon(triangle);
        break;
    }
    default:
        break;
    }
}
