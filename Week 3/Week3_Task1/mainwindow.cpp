#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDockWidget *dockWidget1 = new QDockWidget(tr("My Tool Bar"),this);
    dockWidget1->setAllowedAreas(Qt::RightDockWidgetArea|Qt::BottomDockWidgetArea|Qt::TopDockWidgetArea|Qt::LeftDockWidgetArea);
    QPushButton *myButton = new QPushButton("Press Now!",this);
    dockWidget1->setWidget(myButton);
    addDockWidget(Qt::RightDockWidgetArea,dockWidget1);

    connect(myButton,&QPushButton::clicked,this,&MainWindow::onmyButtonClicked);

}

void MainWindow::onmyButtonClicked(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm", "Do you want exit?",
    QMessageBox::Yes | QMessageBox::No);
    if(reply=QMessageBox::Yes){
        QApplication::quit();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
