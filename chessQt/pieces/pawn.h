#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public AbstractPiece
{
    using AbstractPiece::AbstractPiece;

    QString srcWhite();
    QString srcBlack();

    bool virtual moveValidator(const int x, const int y);
};

#endif // PAWN_H
