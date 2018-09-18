#include "Snake.h"
#include "GameWidget.h"

Snake::Snake(Square *_sq)
{
    sq = _sq;
    head = new SnakeHead(sq);
    lenth = 0;
    foodNumber = 3;
    end = head;
    createSnake();
}

void Snake::turnDown()
{
    if(ifDirectionIsChange == false){
        direction = 's';
        ifDirectionIsChange = true;
    }
}

void Snake::turnUp()
{
    if(ifDirectionIsChange == false){
        direction = 'w';
        ifDirectionIsChange = true;
    }
}

void Snake::turnLeft()
{
    if(ifDirectionIsChange == false){
        direction = 'a';
        ifDirectionIsChange = true;
    }
}

void Snake::turnRight()
{
    if(ifDirectionIsChange == false){
        direction = 'd';
        ifDirectionIsChange = true;
    }
}

void Snake::onGameUpdate()
{
    //如果吃了食物，增加长度
    if(foodNumber > 0){
        SnakeBody* newBody = new SnakeBody(end,++lenth,sq);
        newBody->setPosition(end->getx(),end->gety());
        end->changeNext(newBody);
        end = newBody;
        foodNumber--;
    }

    //遍历蛇身
    SnakeBody* p = end;
    while(p != head){
        p->setPosition(p->getLast()->getx(),p->getLast()->gety());
        p = p->getLast();
    }

    //蛇头移动
    if(direction == 'w'){
        head->MoveUp();
    } else if(direction == 's'){
        head->MoveDown();
    } else if(direction == 'a'){
        head->MoveLeft();
    } else if(direction == 'd'){
        head->MobeRight();
    }

    //将坐标信息加载到棋盘
    p = end;
    while(p != head){
        p->AttachToSquare();
        p = p->getLast();
    }
    head->AttachToSquare();

    ifDirectionIsChange = false;
}

void Snake::createSnake()
{
    while(foodNumber--){
        SnakeBody* newBody = new SnakeBody(end,++lenth,sq);
        newBody->setPosition(end->getx()-1,end->gety());
        end->changeNext(newBody);
        end = end->getNext();
    }
    foodNumber++;

    //将坐标信息加载到棋盘
    SnakeBody* p = head;
    while(p != end){
        p->AttachToSquare();
        p = p->getNext();
    }
    end->AttachToSquare();
}

void Snake::eatFood()
{
    foodNumber++;
}


