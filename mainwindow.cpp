#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    Chord c;
//    Chord Cm(Note('G'), MINOR);
//    Chord a(Note('A'), MAJOR);
    Scale min(Note('D', SHARP), MINOR);
    min.ChangeRoot(Note('E', FLAT));
    min.ChangeKey(MAJOR);
    qDebug() << min.Naturals();
    qDebug() << min.Sharps();
    qDebug() << min.Flats();
}

MainWindow::~MainWindow()
{
    delete ui;
}

