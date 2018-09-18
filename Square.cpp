#include "Square.h"

Square::Square()
{
    this->clear();
}

void Square::clear()
{
    for(int i=0;i<25;i++)
        for(int j=0;j<25;j++)
            s[i][j] = 0;
    for(int i=0;i<=21;i++){
        s[0][i]=4;
        s[i][0]=4;
        s[21][i]=4;
        s[i][21]=4;
    }
}

void Square::onGameUpdate()
{

}
