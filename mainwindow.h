#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <qboxlayout.h>
#include <qlabel.h>

class Tile : public QMdiSubWindow
{
    Q_OBJECT
public:
    Tile(const QString &cap, QWidget* parent = 0)
        : QMdiSubWindow(parent)
    {
        QLabel *l = new QLabel(cap);
        l->setFont(QFont("Arial", 30));
        l->setStyleSheet("QLabel:hover { border: 5px solid green; } ");
        setWidget(l);
    }
};

struct TilePosition
{
    int row;
    int column;
    int rowSpan;
    int colSpan;
    bool visible;
    TilePosition() : row(0), column(0), rowSpan(1), colSpan(1), visible(false) {}
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void updateArrangement();
    void keyPressEvent(QKeyEvent *ke);

public slots:
    void preset1();
    void preset2();
    void preset3();
    void preset4();
    void preset5();
    void resetTiles();

public:
    QList<Tile*> tiles;
    QList<TilePosition> arrange;
};

#endif // MAINWINDOW_H
