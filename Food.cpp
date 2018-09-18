#include "Food.h"
#include <cstdlib>
#include<vector>
#include<utility>

Food::Food(Square *_sq)
    :Element(_sq)
{
    setStyle(3);
    while(sq->s[x][y]){
        x = rand()%20 + 1;
        y = rand()%20 + 1;
    }
    AttachToSquare();
}

Food::Food()
{
    setStyle(3);
}

void Food::onGameUpdate()
{
    if(sq->s[x][y] == 1){
        respawn();
        emit beEatten();
    }

    AttachToSquare();
}

void Food::respawn()
{
    std::vector<std::pair<int,int>> pos;
    for(int i=1;i<=20;i++)
        for(int j=1;j<=20;j++)
            if(!sq->s[i][j])pos.push_back(std::pair<int,int>(i,j));
    int posID = rand()%(pos.size());
    x = (pos[posID]).first;
    y = (pos[posID]).second;
}
