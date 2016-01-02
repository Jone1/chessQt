#ifndef PIECE_H
#define PIECE_H

#include <QString>
#include <cmath>




class AbstractPiece
{
public:
    explicit AbstractPiece(int x, int y, bool color);

    QString virtual srcWhite(); // Returns src to white piece's image.
    QString virtual srcBlack(); // Returns src to black piece's image.

    bool virtual moveValidator(const int x, const int y); // Checks that pieces can move to x and y.
    void virtual makeNotAlive(); // Dies piece.

    int x; //
    int y; // Current piece position.
    bool color; // Color false - white, true - black
    bool alive = true; // Is alice, if not - pieces won't be diplay.

    bool isOpponentHere(const int x, const int y); //
    bool isSelfHere(const int x, const int y); //
    bool isEmpty(const int x, const int y); // Self comment (if x,y position) + (method name)
    bool isEmptyTo(const int x, const int y); // Checks move valid from this->x, this->y do x, y.

    void move(int x, int y); // Move piece to x, y.


    virtual ~AbstractPiece();
};

extern AbstractPiece* chessboard[8][8]; // Array of pieces.

#endif // PIECE_H
