#include "rook.h"



QString Rook::srcWhite()
{
    return QString("D:/workspace/warcabyQt/warcabyQt/gfx/rw.png");
}

QString Rook::srcBlack()
{
    return QString("D:/workspace/warcabyQt/warcabyQt/gfx/rb.png");
}

bool Rook::moveValidator(const int x, const int y)
{
    if(!this->isSelfHere(x, y)){ // Any own pice here?
        return false;
    }

    if(y != this->y && x != this->x){
        return false;
    }
    return this->isEmptyTo(x, y);
}
