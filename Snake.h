#ifndef SNAKE_H
#define SNAKE_H

#include"Element.h"
#include"SnakeHead.h"

#include<QObject>

class Snake : public QObject
{
    Q_OBJECT
public:
    Snake(Square* _sq);
    char getDirection(){return direction;}
    const SnakeHead *const getHead(){return head;}

    virtual void onGameUpdate();

private:
    SnakeHead* head;
    SnakeBody* end;
    char direction = 'd';
    bool ifDirectionIsChange = false;
    int lenth;
    int foodNumber;
    Square* sq;

    void createSnake();

public slots:
    void turnUp();
    void turnDown();
    void turnLeft();
    void turnRight();

    void eatFood();

};

#endif // SNAKE_H
