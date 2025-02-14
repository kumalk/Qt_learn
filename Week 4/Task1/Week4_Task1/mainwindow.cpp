#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    textEdit = new QTextEdit(this);
    textEdit->setPlainText("This text is only a sample for preview font change. YOu can type your own text here");
    textEdit->setGeometry(10, 10, 600, 500);


    fontButton = new QPushButton("Select Font", this);
    fontButton->setGeometry(10, 510, 100, 30);

    connect(fontButton, &QPushButton::clicked, this, &MainWindow::selectFont);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectFont()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if (ok) {
        textEdit->setFont(font);
    }
}
