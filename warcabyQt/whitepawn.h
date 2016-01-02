#ifndef WHITEPAWN_H
#define WHITEPAWN_H

#include "pawn.h"

class WhitePawn : public Pawn
{
    using Pawn::Pawn;
    bool virtual moveValidator(const int x, const int y);
};

#endif // WHITEPAWN_H
