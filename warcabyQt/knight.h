#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public AbstractPiece
{
    using AbstractPiece::AbstractPiece;

    QString srcWhite();
    QString srcBlack();

    bool can_jump = false;

    bool moveValidator(const int x, const int y);


};


#endif // KNIGHT_H
