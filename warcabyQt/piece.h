#ifndef PIECE_H
#define PIECE_H

#include <QString>
#include <cmath>




class Piece
{
public:
    explicit Piece(int x, int y, bool color);

    QString virtual srcWhite();
    QString virtual srcBlack();

    int x;
    int y;
    bool color;
    bool alive = true;
    bool can_jump = false;

    bool virtual moveValidator(const int x, const int y);

    bool isOpponentHere(const int x, const int y);
    bool isSelfHere(const int x, const int y);
    bool isEmpty(const int x, const int y);
    bool isEmptyTo(const int x, const int y);

    void makeNotAlive();
    void move(int x, int y);
};

extern Piece* chessboard[8][8];

#endif // PIECE_H
