#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *leftWidget = new QWidget(this);
    QWidget *rightWidget = new QWidget(this);

    QVBoxLayout *leftBox = new QVBoxLayout(leftWidget);
    QVBoxLayout *rightBox = new QVBoxLayout(rightWidget);
    QSplitter *winSplit = new QSplitter(this);
    QPushButton *Button1 = new QPushButton("Left Side Button");
    QPushButton *Button2 = new QPushButton("Right Side Button");
    QTextEdit *Textbox1 = new QTextEdit();
    leftBox->addWidget(Button1);
    leftBox->addWidget(Textbox1);
    rightBox->addWidget(Button2);

    winSplit->addWidget(leftWidget);
    winSplit->addWidget(rightWidget);

    setCentralWidget(winSplit);
    winSplit->setStyleSheet("QSplitter::handle { background-color: gray; width: 2px; height: 2px; }");

}

MainWindow::~MainWindow()
{
    delete ui;
}
