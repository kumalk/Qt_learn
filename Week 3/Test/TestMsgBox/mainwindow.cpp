#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSplitter* pSplitter = new QSplitter(this);
    pSplitter->addWidget(new QPushButton("left side"));
    pSplitter->addWidget(new QPushButton("right side"));
    setCentralWidget(pSplitter);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    showMessage();
}

void MainWindow:: showMessage(){
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText("Test Message");
    msgBox.setInformativeText("This is the testing message , click on any of this answer");
    msgBox.setWindowTitle("Test");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    int ret = msgBox.exec();

    switch(ret){
        case QMessageBox::Ok:
                          break;
        case QMessageBox::Cancel:
            break;
        default:
            break;


    }
}

