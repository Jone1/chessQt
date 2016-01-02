#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public AbstractPiece
{
    using AbstractPiece::AbstractPiece;

    QString srcWhite();
    QString srcBlack();

    bool moveValidator(const int x, const int y);
};

#endif // QUEEN_H
