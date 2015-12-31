#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filed.h"
#include "piece.h"


myLabel* labels[8][8];


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Chessboard creatoin
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            myLabel* m_label = new myLabel(this->style[(i+j) % 2], this, i, j);
            ui->gridLayout->addWidget(m_label, i, j);
            labels[i][j] = m_label;
            connect( m_label, SIGNAL( clicked(int, int) ), this, SLOT( slotClicked(int, int) ) );
        }
    }
    this->createPiece();
    this->refreshPiece();

}

void MainWindow::createPiece()
{
    chessboard[6][1] = new Pawn(6, 1, true);
    chessboard[6][2] = new Pawn(6, 2, true);
    chessboard[6][3] = new Pawn(6, 3, true);
    chessboard[6][5] = new Pawn(6, 5, true);
    chessboard[6][7] = new Pawn(6, 7, true);

    chessboard[0][0] = new Rook(0, 0, false);
    chessboard[4][3] = new Bishop(4, 3, false);

    chessboard[3][7] = new King(3, 7, false);
    chessboard[4][7] = new Queen(4, 7, false);
    chessboard[5][7] = new Knight(5, 7, false);

    chessboard[5][0] = new Pawn(5, 0, false);
    chessboard[1][1] = new Pawn(1, 1, false);
    chessboard[0][3] = new Pawn(0, 3, false);
    chessboard[3][2] = new Pawn(3, 2, false);
    chessboard[1][4] = new Pawn(1, 4, false);
    chessboard[1][6] = new Pawn(1, 6, false);
}

void MainWindow::refreshPiece(){
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            if (chessboard[i][j]){
                if(chessboard[i][j]->alive){
                    if(chessboard[i][j]->color){
                        labels[i][j]->setImagePiece(chessboard[i][j]->srcBlack());
                    } else {
                        labels[i][j]->setImagePiece(chessboard[i][j]->srcWhite());
                    }
                }
            } else {
                labels[i][j]->setImagePiece("");
            }
        }
    }
}

void MainWindow::deselectAll()
{
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
        labels[i][j]->setStyleSheet(this->style[(i+j) % 2]);
        }
    }
}

void MainWindow::movePiece(int x, int y)
{
    chessboard[this->active_x][this->active_y]->move(x, y);
    chessboard[x][y] = chessboard[this->active_x][this->active_y];
    chessboard[this->active_x][this->active_y] = NULL;
    this->deselectAll();
    this->refreshPiece();

}



void MainWindow::slotClicked(int x, int y)
{
    if(chessboard[x][y] && labels[x][y]->styleSheet() == "background: #00f"){ //beat
        chessboard[x][y]->makeNotAlive();
        this->movePiece(x, y);
    } else if (chessboard[x][y]){ //choose piece
        for(int i = 0; i<8; i++){
            for(int j = 0; j<8; j++){
                labels[i][j]->setStyleSheet(this->style[(i+j) % 2]);
                labels[i][j]->setStyleSheet(this->style[(i+j) % 2]);
                if (chessboard[x][y]->moveValidator(i, j)){
                    labels[i][j]->setStyleSheet("background: #00f");
                } else {
                    labels[i][j]->setStyleSheet(this->style[(i+j) % 2]);
                }
            }
        }
        labels[x][y]->setStyleSheet("background: #f00");
        this->active_x = x;
        this->active_y = y;
    } else if (labels[x][y]->styleSheet() == "background: #00f"){ // move piece
        this->movePiece(x, y);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
