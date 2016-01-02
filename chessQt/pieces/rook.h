#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
#include "QDebug"

class Rook : public AbstractPiece
{
    using AbstractPiece::AbstractPiece;

    QString srcWhite();
    QString srcBlack();

    bool moveValidator(const int x, const int y);


};

#endif // ROOK_H
