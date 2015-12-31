#include "pawn.h"


QString Pawn::srcWhite()
{
    return QString("D:/workspace/warcabyQt/warcabyQt/gfx/pw.png");
}

QString Pawn::srcBlack()
{
    return QString("D:/workspace/warcabyQt/warcabyQt/gfx/pb.png");
}

bool Pawn::moveValidator(const int x, const int y)
{
    if((this->x + 1 == x && this->y + 1 == y) || (this->x + 1 == x && this->y - 1 == y)){ // Can beat?
        return this->isOpponentHere(this->x+1, this->y+1) || this->isOpponentHere(this->x+1, this->y-1);
    }

    if(!this->isSelfHere(x, y)){ // Any own pice here?
        return false;
    }

    if(y == this->y){
        if(1 == this->x || 6 == this->x){ // First move of pawn
            if(x - this->x < 3 && x - this->x > 0){
                return this->isEmpty(x, y);
            }

        } else { // Other move of piece
            if(x - this->x < 2 && x - this->x > 0){
                return this->isEmpty(x, y);
            }
        }
    }
    return false;
}
