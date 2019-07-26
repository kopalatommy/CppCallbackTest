#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow() :
    QMainWindow(nullptr),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

