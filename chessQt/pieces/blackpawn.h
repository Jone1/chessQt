#ifndef BLACKPAWN_H
#define BLACKPAWN_H

#include "pawn.h"

class BlackPawn : public Pawn
{
    using Pawn::Pawn;
    bool moveValidator(const int x, const int y);
};

#endif // BLACKPAWN_H
