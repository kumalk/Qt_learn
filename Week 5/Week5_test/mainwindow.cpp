#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(nullptr) // Initialize scene to nullptr
{
    ui->setupUi(this);
    scene = new QGraphicsScene(); // Create the scene object
    ui->graphicsView->setScene(scene); // Set the scene for graphicsView
    text = scene->addText("Hello World", QFont("Arial", 26));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene; // Delete the scene to free memory
}
