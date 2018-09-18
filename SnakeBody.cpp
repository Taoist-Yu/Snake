#include "SnakeBody.h"
#include <cstdio>

SnakeBody::SnakeBody()
{
    setStyle(2);
    next = NULL;
    last = NULL;
    bodyID = 0;
}

SnakeBody::SnakeBody(Square *_sq)
    :Element(_sq)
{
    setStyle(2);
    next = NULL;
    last = NULL;
    bodyID = 0;
}

SnakeBody::SnakeBody(SnakeBody* _last,int id,Square* _sq)
    :Element(_sq)
{
    setStyle(2);
    next = NULL;
    last = _last;
    bodyID = id;
}

SnakeBody& SnakeBody::nextBody()
{
    return *next;
}

void SnakeBody::onGameUpdate()
{

}

void SnakeBody::move()
{
    x = last->getx();
    y = last->gety();
}
