#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
#include "QDebug"

class Rook : public Piece
{
    using Piece::Piece;

    QString srcWhite();
    QString srcBlack();

    bool moveValidator(const int x, const int y);


};

#endif // ROOK_H
