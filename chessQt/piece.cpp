
#include "piece.h"
#include "QDebug"

AbstractPiece* chessboard[8][8];

AbstractPiece::AbstractPiece(int x, int y, bool color)
{
    this->x = x;
    this->y = y;
    this->color = color;
}

QString AbstractPiece::srcWhite()
{
    return QString("");
}

QString AbstractPiece::srcBlack()
{
    return QString("");
}

bool AbstractPiece::moveValidator(const int x, const int y)
{
    return false;
}




bool AbstractPiece::isOpponentHere(const int x, const int y)
{
    if(chessboard[x][y]){
       if(chessboard[x][y]->color != this->color){
           return true;
       }
    }
    return false;
}

bool AbstractPiece::isSelfHere(const int x, const int y)
{
    if(chessboard[x][y]){
        if(chessboard[x][y]->color == this->color){
            return false;
        }
    }
    return true;
}

bool AbstractPiece::isEmpty(const int x, const int y)
{
    if(!chessboard[x][y]){
            return true;

    }
    return false;
}

bool AbstractPiece::isEmptyTo(const int x, const int y)
{

    if(this->x == x || this->y == y){ // Horizontal and vertical move (Rook)
        for(int i=this->x + 1; i < x; i++){
            if(!this->isEmpty(i, y)){
                return false;
            }
        }

        for(int j = this->y + 1; j < y; j++){
            if(!this->isEmpty(x, j)){
                return false;
            }
        }

        for(int i=this->x - 1; i > x; i--){
            if(!this->isEmpty(i, y)){
                return false;
            }
        }

        for(int j = this->y - 1; j > y; j--){
            if(!this->isEmpty(x, j)){
                return false;
            }
        }
    } else if(x - this->x > 0 && y - this->y > 0){
        for(int i=1; i < x - this->x; i++){
            if(!this->isEmpty(this->x + i, this->y + i)){
                return false;
            }
        }
    } else if(this->x - x > 0 && this->y - y > 0)  {
        for(int i=1; i < this->x - x; i++){
            if(!this->isEmpty(this->x - i, this->y - i)){
                return false;
            }
        }
    } else if(this->y - y > 0 && x - this->x > 0)  {
        for(int i=1; i < this->y - y; i++){
            if(!this->isEmpty(this->x + i, this->y - i)){
                return false;
            }
        }
    } else if(y - this->y > 0 && this->x - x > 0)  {
        for(int i=1; i < y - this->y; i++){
            if(!this->isEmpty(this->x - i, this->y + i)){
                return false;
            }
        }
    }
    return true;
}


void AbstractPiece::makeNotAlive()
{
    this->alive = false;
}

void AbstractPiece::move(int x, int y)
{
    this->x = x;
    this->y = y;
}

AbstractPiece::~AbstractPiece()
{

}
