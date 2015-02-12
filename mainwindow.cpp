#include "mainwindow.h"

#include <QAction>
#include <QBoxLayout>
#include <QKeyEvent>
#include <QLabel>
#include <QMdiArea>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      area(new QMdiArea)
{
    setWindowState(Qt::WindowMaximized);

    setCentralWidget(area);
    new QGridLayout(area);
    area->setActivationOrder(QMdiArea::CreationOrder);

    for(int i = 0; i < 9; ++i)
        tiles << new Tile(QString::number(i+1));

    preset1();
}

MainWindow::~MainWindow()
{

}

void MainWindow::preset1()
{
    resetTiles();

    for(int i = 0; i < 4; ++i)
    {
        arrange[i].visible = true;
        arrange[i].row = i/2;
        arrange[i].column = i%2;
    }
    updateArrangement();
}

void MainWindow::preset2()
{
    resetTiles();

    for(int i = 0; i < 3; ++i)
        arrange[i].visible = true;

    arrange[0].row = 0;
    arrange[0].column = 0;
    arrange[0].rowSpan = 2;

    arrange[1].row = 0;
    arrange[1].column = 1;

    arrange[2].row = 1;
    arrange[2].column = 1;

    updateArrangement();
}

void MainWindow::preset3()
{
    resetTiles();

    for(int i = 0; i < 4; ++i)
        arrange[i].visible = true;

    arrange[0].row = 0;
    arrange[0].column = 0;
    arrange[0].rowSpan = 2;

    arrange[1].row = 0;
    arrange[1].column = 1;

    arrange[2].row = 1;
    arrange[2].column = 1;

    arrange[3].row = 0;
    arrange[3].column = 2;
    arrange[3].rowSpan = 2;

    updateArrangement();
}

void MainWindow::preset4()
{
    resetTiles();

    for(int i = 0; i < 4; ++i)
        arrange[i].visible = true;

    arrange[0].row = 0;
    arrange[0].column = 0;

    arrange[1].row = 1;
    arrange[1].column = 0;

    arrange[2].row = 0;
    arrange[2].column = 1;
    arrange[2].rowSpan = 2;
    arrange[2].colSpan = 2;

    arrange[3].row = 3;
    arrange[3].column = 0;
    arrange[3].colSpan = 3;

    updateArrangement();
}

void MainWindow::preset5()
{
    resetTiles();

    for(int i = 0; i < 9; ++i)
    {
        arrange[i].visible = true;
        arrange[i].row = i/3;
        arrange[i].column = i%3;
    }
    updateArrangement();
}

void MainWindow::resetTiles()
{
    arrange.clear();
    for(int i = 0; i < tiles.count(); ++i)
    {
        arrange << TilePosition();
    }
    area->hide();
}

void MainWindow::updateArrangement()
{
    QGridLayout *grid = qobject_cast<QGridLayout*>(centralWidget()->layout());
    if (!grid)
        return;

    int i = -1;
    foreach (const TilePosition &tile, arrange) {
        ++i;
        tiles[i]->hide();
        if (!tile.visible)
            continue;

        tiles[i]->show();
        grid->addWidget(tiles[i], tile.row, tile.column, tile.rowSpan, tile.colSpan);
    }
    area->show();
}

void MainWindow::keyPressEvent(QKeyEvent *ke)
{
    switch (ke->key()) {
    case Qt::Key_1:
        preset1();
        break;
    case Qt::Key_2:
        preset2();
        break;
    case Qt::Key_3:
        preset3();
        break;
    case Qt::Key_4:
        preset4();
        break;
    case Qt::Key_5:
        preset5();
        break;
    default:
        break;
    }

    QMainWindow::keyPressEvent(ke);
}



