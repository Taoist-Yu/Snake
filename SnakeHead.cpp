#include "SnakeHead.h"
#include "GameWidget.h"
#include <cstdio>

SnakeHead::SnakeHead(Square* _sq)
    :SnakeBody(_sq)
{
    setStyle(1);
    next = NULL;
    bodyID = 1;
    x=10;y=10;
}

SnakeHead::SnakeHead()
{
    setStyle(1);
    next = NULL;
    bodyID = 1;
}

void SnakeHead::onGameUpdate()
{

}

void SnakeHead::AttachToSquare()
{
    if(!(sq->s[x][y])){
        sq->s[x][y] = Style;
    } else if(sq->s[x][y] == 2 || sq->s[x][y] == 4){
        emit gameOverSignal();
    }
}

