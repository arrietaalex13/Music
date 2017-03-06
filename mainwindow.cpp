#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Chord c;
    //Chord Cm(Note('C'), MINOR);
    //Chord a(Note('A'), MAJOR);
    Scale min(Note('C'), MINOR);
}

MainWindow::~MainWindow()
{
    delete ui;
}

