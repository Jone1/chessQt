#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece
{
    using Piece::Piece;

    QString srcWhite();
    QString srcBlack();

    bool moveValidator(const int x, const int y);


};


#endif // KING_H
