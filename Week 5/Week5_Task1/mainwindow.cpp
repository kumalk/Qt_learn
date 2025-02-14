#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->installEventFilter(this); // Install the event filter on the QLineEdit
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->lineEdit && event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->text().contains('e') || keyEvent->text().contains('E'))
        {
            return true; // Ignore the event if the letter 'e' is pressed.
        }
    }
    return QMainWindow::eventFilter(obj, event);
}
