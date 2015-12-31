#include "knight.h"

QString Knight::srcWhite()
{
    return QString("D:/workspace/warcabyQt/warcabyQt/gfx/nw.png");
}

QString Knight::srcBlack()
{
    return QString("D:/workspace/warcabyQt/warcabyQt/gfx/nb.png");
}

bool Knight::moveValidator(const int x, const int y)
{
    if(!this->isSelfHere(x, y)){ // Any own pice here?
        return false;
    }
    if(abs(this->x-x) == 2 && abs(this->y-y) == 1){
        return true;
    } else if(abs(this->x-x) == 1 && abs(this->y-y) == 2) {
        return true;
    }
    return false;
}
