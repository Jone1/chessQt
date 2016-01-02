#include "views/filed.h"

myLabel::myLabel( const QString & text, QWidget * parent, int x, int y )
:QLabel(parent)
{
    this->setMinimumHeight(70);
    this->setMinimumWidth(70);
    this->setStyleSheet(text);
    this->x = x;
    this->y = y;
//    this->setImagePiece("D:/workspace/chessQt/chessQt/gfx/ch.png");
}

void myLabel::setImagePiece(const QString &text)
{
    QPixmap mypix (text);
    this->setPixmap(mypix);
}


void myLabel::mousePressEvent ( QMouseEvent * event )
{
    emit clicked(this->x,this->y);
}
