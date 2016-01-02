#include "pieces/bishop.h"


QString Bishop::srcWhite()
{
    return QString("D:/workspace/chessQt/chessQt/gfx/bw.png");
}

QString Bishop::srcBlack()
{
    return QString("D:/workspace/chessQt/chessQt/gfx/bb.png");
}

bool Bishop::moveValidator(const int x, const int y)
{
    if(abs(x-this->x) != abs(y-this->y)){
        return false;
    }
    return this->isEmptyTo(x, y);
}
