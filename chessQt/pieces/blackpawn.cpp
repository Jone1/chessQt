#include "pieces/blackpawn.h"

bool BlackPawn::moveValidator(const int x, const int y)
{
    if(this->x - 1 == x && this->y - 1 == y){ // Can beat?
        return this->isOpponentHere(this->x-1, this->y-1);
    } else if (this->x - 1 == x && this->y + 1 == y){
        return this->isOpponentHere(this->x-1, this->y+1);
    }



    if(y == this->y){
        if(6 == this->x){ // First move of pawn
            if(this->x - x < 3 && this->x - x > 0){
                return this->isEmpty(x, y);
            }
        } else { // Other move of piece
            if(this->x - x < 2 && this->x - x > 0){
                return this->isEmpty(x, y);
            }
        }
    }
    return false;
}
