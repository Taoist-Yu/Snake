#ifndef ELEMENT_H
#define ELEMENT_H
/*
 *游戏中的某一个元件
 * 例如蛇头，蛇身，食物等都是element
*/

#include "Square.h"
#include <QObject>

class Element : public QObject
{
    Q_OBJECT
public:
    Element();
    Element(Square* _sq);
    int getStyle();
    int setStyle(int _style);
    int getx(){return x;}
    int gety(){return y;}

    void MoveUp() {y--;}
    void MoveDown() {y++;}
    void MoveLeft() {x--;}
    void MobeRight() {x++;}
    void setPosition(int _x,int _y) {x=_x;y=_y;}

    virtual void AttachToSquare();
    virtual void onGameUpdate();

protected:
    int x;
    int y;
    int Style;  //0为空，1为头，2为身，3为食物,4为墙
    Square* sq;

};

#endif // ELEMENT_H
