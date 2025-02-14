#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->Slider, &QSlider::valueChanged, this, &MainWindow::SliderChanged);
}

void MainWindow::SliderChanged(int newVal){
    QString newValTxt = QString::number(newVal);
    ui->lblVal->setText(newValTxt);
}



MainWindow::~MainWindow()
{
    delete ui;
}
