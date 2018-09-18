#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QTimerEvent>
#include <QKeyEvent>
#include <QWidget>
#include "Square.h"
#include "Snake.h"
#include "Food.h"

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    GameWidget(QWidget *parent = 0);
    ~GameWidget();

protected:
    virtual void paintEvent(QPaintEvent *);
    virtual void keyPressEvent(QKeyEvent *ev);
    virtual void timerEvent(QTimerEvent *);

private:
    Square square;
    Snake *snake;
    Food *food;
    int timerID;

signals:
    void turnLeft();
    void turnRight();
    void turnUp();
    void turnDown();

public slots:
    void gameOver();

};

#endif // GAMEWIDGET_H
