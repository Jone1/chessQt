
#ifndef FILED_H
#define FILED_H

#include<QLabel>
#include<QDebug>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    int x;
    int y;
    myLabel( const QString & text, QWidget * parent = 0, int x = 0, int y = 0);
    void setImagePiece(const QString & text);
    ~myLabel(){}

signals:
    void clicked(int, int);


protected:
    void mousePressEvent ( QMouseEvent * event ) ;

};
#endif
