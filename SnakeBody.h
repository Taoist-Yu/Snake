#ifndef SNAKEBODY_H
#define SNAKEBODY_H

#include "Element.h"
#include "Square.h"

class SnakeBody : public Element
{
    Q_OBJECT
public:
    SnakeBody();
    SnakeBody(Square *_sq);
    SnakeBody(SnakeBody* last,int id,Square* _sq);
    SnakeBody& nextBody();
    int getBodyID(){return bodyID;}

    SnakeBody* getNext(){return next;}
    SnakeBody* getLast(){return last;}
    void changeNext(SnakeBody *newNext){next = newNext;}

    virtual void onGameUpdate();

protected:
    SnakeBody *next;
    SnakeBody *last;
    void move();
    int bodyID;

};

#endif // SNAKEBODY_H
