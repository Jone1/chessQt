#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop :  public AbstractPiece
{
    using AbstractPiece::AbstractPiece;

    QString srcWhite();
    QString srcBlack();

    bool moveValidator(const int x, const int y);


};


#endif // BISHOP_H
