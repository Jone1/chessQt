#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public AbstractPiece
{
    using AbstractPiece::AbstractPiece;

    QString srcWhite();
    QString srcBlack();

    bool moveValidator(const int x, const int y);
    void makeNotAlive();

};


#endif // KING_H
