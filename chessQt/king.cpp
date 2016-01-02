#include "king.h"



QString King::srcWhite()
{
    return QString("D:/workspace/warcabyQt/warcabyQt/gfx/kw.png");
}

QString King::srcBlack()
{
    return QString("D:/workspace/warcabyQt/warcabyQt/gfx/kb.png");
}

bool King::moveValidator(const int x, const int y)
{
    if(abs(this->x-x) > 1 || abs(this->y-y) > 1){
        return false;
    }
    return true;
}
