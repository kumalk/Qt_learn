#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QMessageBox>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    statusBar()->showMessage("Ready");

    QMenuBar *menuBar = this->menuBar();

    fileMenu = menuBar->addMenu("&File");

    QAction *newAction = new QAction("&New",this);
    QAction *openAction = new QAction("&Open",this);
    QAction *exitAction = new QAction("&Exit",this);

    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);



    delete ui;
}
