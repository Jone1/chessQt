#include "piece.h"
#include "QDebug"

Piece* chessboard[8][8];

Piece::Piece(int x, int y, bool color)
{
    this->x = x;
    this->y = y;
    this->color = color;
}

QString Piece::srcWhite()
{
    return QString("");
}

QString Piece::srcBlack()
{
    return QString("");
}

bool Piece::moveValidator(const int x, const int y)
{
    return false;
}




bool Piece::isOpponentHere(const int x, const int y)
{
    if(chessboard[x][y]){
       if(chessboard[x][y]->color != this->color){
           return true;
       }
    }
    return false;
}

bool Piece::isSelfHere(const int x, const int y)
{
    if(chessboard[x][y]){
        if(chessboard[x][y]->color == this->color){
            return false;
        }
    }
    return true;
}

bool Piece::isEmpty(const int x, const int y)
{
    if(!chessboard[x][y]){
            return true;
    }
    return false;
}

bool Piece::isEmptyTo(const int x, const int y)
{

    if(this->x == x || this->y == y){
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
    } else {
//        for(int i=1; i < 3; i++){
//            if(!this->isEmpty(x + i, y + i)){
//                return false;
//            }
//        }
//        for(int i=1; i < 3; i++){
//            if(!this->isEmpty(x - i, y + i)){
//                return false;
//            }
//        }
//        for(int i=1; i < 3; i++){
//            if(!this->isEmpty(x + i, y - i)){
//                return false;
//            }
//        }
        if(this->x - x == this->y - y){
            for(int i=1; i < 5; i++){
                if(!this->isEmpty(x - i, y - i)){
                    return false;
                }
            }
        }
    }
    return true;
}


void Piece::makeNotAlive()
{
    this->alive = false;
}

void Piece::move(int x, int y)
{
    this->x = x;
    this->y = y;
}
