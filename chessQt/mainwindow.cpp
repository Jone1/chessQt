#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filed.h"
#include "blackpawn.h"
#include "whitepawn.h"

#include <QMessageBox>

myLabel* labels[8][8]; // 8x8 array of labels.


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(648, 635);
    this->setWindowTitle("ChessQt");

    // Chessboard creatoin
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            myLabel* m_label = new myLabel(this->style[(i+j) % 2], this, i, j);
            ui->gridLayout->addWidget(m_label, i, j);
            labels[i][j] = m_label;
            connect( m_label, SIGNAL( clicked(int, int) ), this, SLOT( slotClicked(int, int) ) );
        }
    }

    connect(ui->actionNowa_gra, SIGNAL(triggered()), this, SLOT(slotNewGame()));
}

void MainWindow::createPiece()
{
    // Black pices
    chessboard[6][0] = new BlackPawn(6, 0, true);
    chessboard[6][1] = new BlackPawn(6, 1, true);
    chessboard[6][2] = new BlackPawn(6, 2, true);
    chessboard[6][3] = new BlackPawn(6, 3, true);
    chessboard[6][4] = new BlackPawn(6, 4, true);
    chessboard[6][5] = new BlackPawn(6, 5, true);
    chessboard[6][6] = new BlackPawn(6, 6, true);
    chessboard[6][7] = new BlackPawn(6, 7, true);

    chessboard[7][0] = new Rook(7, 0, true);
    chessboard[7][1] = new Knight(7, 1, true);
    chessboard[7][2] = new Bishop(7, 2, true);
    chessboard[7][4] = new King(7, 4, true);
    chessboard[7][3] = new Queen(7, 3, true);
    this->black_king = chessboard[7][4];
    chessboard[7][5] = new Bishop(7, 5, true);
    chessboard[7][6] = new Knight(7, 6, true);
    chessboard[7][7] = new Rook(7, 6, true);

    //White pieces
    chessboard[0][0] = new Rook(0, 0, false);
    chessboard[0][1] = new Knight(0, 1, false);
    chessboard[0][2] = new Bishop(0, 2, false);
    chessboard[0][4] = new King(0, 4, false);
    this->white_king = chessboard[0][4];
    chessboard[0][3] = new Queen(0, 3, false);
    chessboard[0][5] = new Bishop(0, 5, false);
    chessboard[0][6] = new Knight(0, 6, false);
    chessboard[0][7] = new Rook(0, 7, false);

    chessboard[1][0] = new WhitePawn(1, 0, false);
    chessboard[1][1] = new WhitePawn(1, 1, false);
    chessboard[1][2] = new WhitePawn(1, 2, false);
    chessboard[1][3] = new WhitePawn(1, 3, false);
    chessboard[1][4] = new WhitePawn(1, 4, false);
    chessboard[1][5] = new WhitePawn(1, 5, false);
    chessboard[1][6] = new WhitePawn(1, 6, false);
    chessboard[1][7] = new WhitePawn(1, 7, false);
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
    this->next_move = !this->next_move;

    if(!this->black_king->alive){
        QMessageBox msgBox;
        msgBox.setText("White wins.");
        msgBox.exec();
        this->newGame();
    } else if(!this->white_king->alive){
        QMessageBox msgBox;
        msgBox.setText("Black wins.");
        msgBox.exec();
        this->newGame();
    }

}

void MainWindow::removePiece()
{
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            if (chessboard[i][j]){
                delete chessboard[i][j];
                chessboard[i][j]=NULL;
            }
        }
    }
}

void MainWindow::newGame()
{
    this->removePiece();
    this->createPiece();
    this->refreshPiece();
}

void MainWindow::slotNewGame()
{
    this->newGame();
}



void MainWindow::slotClicked(int x, int y)
{
    if(chessboard[x][y] && labels[x][y]->styleSheet() == "background: #00f"){ //beat
        chessboard[x][y]->makeNotAlive();
        this->movePiece(x, y);
    } else if (chessboard[x][y]){ //choose piece
        if (chessboard[x][y]->color == this->next_move){
            for(int i = 0; i<8; i++){
                for(int j = 0; j<8; j++){
                    labels[i][j]->setStyleSheet(this->style[(i+j) % 2]);
                    labels[i][j]->setStyleSheet(this->style[(i+j) % 2]);
                    if (chessboard[x][y]->moveValidator(i, j) && chessboard[x][y]->isSelfHere(i, j)){
                        labels[i][j]->setStyleSheet("background: #00f");
                    } else {
                        labels[i][j]->setStyleSheet(this->style[(i+j) % 2]);
                    }
                }
            }
            labels[x][y]->setStyleSheet("background: #f00");
            this->active_x = x;
            this->active_y = y;
        }
    } else if (labels[x][y]->styleSheet() == "background: #00f"){ // move piece
        this->movePiece(x, y);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
