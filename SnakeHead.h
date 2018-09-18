#ifndef SNAKEHEAD_H
#define SNAKEHEAD_H

#include"Element.h"
#include"SnakeBody.h"

class SnakeHead : public SnakeBody
{
    Q_OBJECT
public:
    SnakeHead();
    SnakeHead(Square *_sq);

    virtual void AttachToSquare();
    virtual void onGameUpdate();

signals:
    void gameOverSignal();

};

#endif // SNAKEHEAD_H
