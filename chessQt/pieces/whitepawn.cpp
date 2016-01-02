#include "pieces/whitepawn.h"


bool WhitePawn::moveValidator(const int x, const int y)
{
    if(this->x + 1 == x && this->y + 1 == y){ // Can beat?
        return this->isOpponentHere(this->x+1, this->y+1);
    } else if (this->x + 1 == x && this->y - 1 == y){
        return this->isOpponentHere(this->x+1, this->y-1);
    }
    if(y == this->y){
        if(1 == this->x){ // First move of pawn
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

