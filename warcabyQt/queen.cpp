#include "queen.h"

QString Queen::srcWhite()
{
    return QString("D:/workspace/warcabyQt/warcabyQt/gfx/qw.png");
}

QString Queen::srcBlack()
{
    return QString("D:/workspace/warcabyQt/warcabyQt/gfx/qb.png");
}

bool Queen::moveValidator(const int x, const int y)
{
    if(abs(x-this->x) != abs(y-this->y) && y != this->y && x != this->x){
        return false;
    }
    return this->isEmptyTo(x, y);
}
