#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece
{
    using Piece::Piece;

    QString srcWhite();
    QString srcBlack();

    bool moveValidator(const int x, const int y);
};

#endif // PAWN_H
