#ifndef PIECE_H
#define PIECE_H

#include <QString>
#include <cmath>




class AbstractPiece
{
public:
    explicit AbstractPiece(int x, int y, bool color);

    QString virtual srcWhite();
    QString virtual srcBlack();

    int x; //
    int y; // Current piece position.
    bool color; // Color false - white, true - black
    bool alive = true; // Is alice, if not - pieces won't be diplay.


    bool virtual moveValidator(const int x, const int y);

    bool isOpponentHere(const int x, const int y);
    bool isSelfHere(const int x, const int y);
    bool isEmpty(const int x, const int y);
    bool isEmptyTo(const int x, const int y);

    void virtual makeNotAlive();
    void move(int x, int y);

    virtual ~AbstractPiece();
};

extern AbstractPiece* chessboard[8][8];

#endif // PIECE_H
