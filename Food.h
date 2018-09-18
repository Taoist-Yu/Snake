#ifndef FOOD_H
#define FOOD_H

#include"Element.h"
#include"Square.h"

class Food : public Element
{
    Q_OBJECT
public:
    Food();
    Food(Square* _sq);

    virtual void onGameUpdate();

private:
    void respawn();

signals:
    void beEatten();

};

#endif // FOOD_H
