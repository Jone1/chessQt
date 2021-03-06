#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pieces/piece.h"
#include "pieces/pawn.h"
#include "pieces/rook.h"
#include "pieces/bishop.h"
#include "pieces/king.h"
#include "pieces/queen.h"
#include "pieces/knight.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    bool next_move = false; // Which player has next move? (false - white, true - blue)
    AbstractPiece *white_king;
    AbstractPiece *black_king;
public:
    explicit MainWindow(QWidget *parent = 0);

    int active_x = 100; //
    int active_y = 100; // Currently clicked label.
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
