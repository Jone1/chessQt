#include "pieces/rook.h"



QString Rook::srcWhite()
{
    return QString("D:/workspace/chessQt/chessQt/gfx/rw.png");
}

QString Rook::srcBlack()
{
    return QString("D:/workspace/chessQt/chessQt/gfx/rb.png");
}

bool Rook::moveValidator(const int x, const int y)
{

    if(y != this->y && x != this->x){
        return false;
    }
    return this->isEmptyTo(x, y);
}
