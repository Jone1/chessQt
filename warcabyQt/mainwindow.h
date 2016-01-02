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

private:
    bool next_move = false; // Which player has next move? (false - white, true - blue)
public:
    int active_x = 100; //
    int active_y = 100; // Currently clicked label.
    explicit MainWindow(QWidget *parent = 0);
    void createPiece(); // Creates piece in default postions.
    void refreshPiece(); // Shows pieces in labels.
    void deselectAll(); // Unselect all labels(pieces).
    void movePiece(int x, int y); // Moves piecs
    void removePiece(); // Removes all pieces.
    void newGame(); // Creates new game.
    ~MainWindow();
    QString style[2] = {"background: #333", "background: #fff"};


public slots:
    void slotClicked(int, int); // Slot for label clicked.
    void slotNewGame(); // Slot for new game.
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
