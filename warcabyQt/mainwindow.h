#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
#include "knight.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int active_x = 100;
    int active_y = 100;
    explicit MainWindow(QWidget *parent = 0);
    void createPiece();
    void refreshPiece();
    void deselectAll();
    void movePiece(int x, int y);
    ~MainWindow();
    QString style[2] = {"background: #333", "background: #fff"};


public slots:
    void slotClicked(int, int);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
