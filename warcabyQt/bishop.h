#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop :  public Piece
{
    using Piece::Piece;

    QString srcWhite();
    QString srcBlack();

    bool moveValidator(const int x, const int y);


};


#endif // BISHOP_H
