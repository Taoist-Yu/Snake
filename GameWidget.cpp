#include "GameWidget.h"
#include "Square.h"
#include <QPainter>
#include <QMessageBox>

GameWidget::GameWidget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(1000,800);    //设置窗口大小
    setWindowTitle(tr("HappySnake"));  //设置窗口标题

    snake = new Snake(&square);
    food =  new Food(&square);

    connect(this,GameWidget::turnDown,snake,Snake::turnDown);
    connect(this,GameWidget::turnUp,snake,Snake::turnUp);
    connect(this,GameWidget::turnLeft,snake,Snake::turnLeft);
    connect(this,GameWidget::turnRight,snake,Snake::turnRight);

    connect(snake->getHead(),SnakeHead::gameOverSignal,this,GameWidget::gameOver);
    connect(food,Food::beEatten,snake,Snake::eatFood);

    timerID = startTimer(100);
}

GameWidget::~GameWidget()
{

}

void GameWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(Qt::white);
    painter.setBrush(Qt::white);
    painter.drawRect(0,0,1000,800);
    for(int i=1;i<=20;i++)
        for(int j=1;j<=20;j++){
            if(square.s[i][j] == 1){
                painter.setPen(Qt::red);
                painter.setBrush(Qt::red);
                painter.drawRect((i-1)*50,(j-1)*40,25,20);
            } else if(square.s[i][j] == 2){
                painter.setPen(Qt::blue);
                painter.setBrush(Qt::blue);
                painter.drawRect((i-1)*50,(j-1)*40,25,20);
            } else if(square.s[i][j] == 3){
                painter.setPen(Qt::green);
                painter.setBrush(Qt::green);
                painter.drawRect((i-1)*50,(j-1)*40,25,20);
            }
        }
}

void GameWidget::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key() == Qt::Key_A && snake->getDirection() !='d'){
        emit turnLeft();
    } else if(ev->key() == Qt::Key_D && snake->getDirection() != 'a'){
        emit turnRight();
    } else if(ev->key() == Qt::Key_W && snake->getDirection() != 's'){
        emit turnUp();
    } else if(ev->key() == Qt::Key_S && snake->getDirection() != 'w'){
        emit turnDown();
    }
}

void GameWidget::timerEvent(QTimerEvent *ev)
{
    square.clear();
    snake->onGameUpdate();
    food->onGameUpdate();
    repaint();
}

void GameWidget::gameOver()
{
    QObject::killTimer(timerID);
    QMessageBox::about(this,tr("game over"),tr("You are died               "));
    this->close();
}



