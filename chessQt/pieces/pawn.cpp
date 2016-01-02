#include "pieces/pawn.h"


QString Pawn::srcWhite()
{
    return QString("D:/workspace/chessQt/chessQt/gfx/pw.png");
}

QString Pawn::srcBlack()
{
    return QString("D:/workspace/chessQt/chessQt/gfx/pb.png");
}

bool Pawn::moveValidator(const int x, const int y)
{

    return false;
}
