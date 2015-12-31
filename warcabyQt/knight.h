#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece
{
    using Piece::Piece;

    QString srcWhite();
    QString srcBlack();

    bool moveValidator(const int x, const int y);


};


#endif // KNIGHT_H
