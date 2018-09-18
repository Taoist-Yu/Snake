#ifndef SQUARE_H
#define SQUARE_H

class Square
{
public:
    Square();

    void clear();

    void onGameUpdate();

public:
    //棋盘大小
    const int size = 20;
    //棋盘数组
    int s[25][25];
};

#endif // SQUARE_H
