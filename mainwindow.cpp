#include "mainwindow.h"

#include <QBoxLayout>
#include <QKeyEvent>
#include <QLabel>
#include <QMdiArea>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowState(Qt::WindowMaximized);
    QMdiArea *area = new QMdiArea;
    setCentralWidget(area);

    for(int i = 0; i < 9; ++i)
    {
        Tile *t = new Tile(QString::number(i+1), this);
        area->addSubWindow(t);
    }
    area->tileSubWindows();
}

MainWindow::~MainWindow()
{

}



