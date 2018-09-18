#include "Element.h"

Element::Element()
{
    Style = 0;
    x=0;
    y=0;
}

Element::Element(Square* _sq)
{
    Style = 0;
    x=0;
    y=0;
    sq = _sq;
}

int Element::getStyle()
{
    return this->Style;
}

int Element::setStyle(int _style)
{
    return Style = _style;
}

void Element::onGameUpdate()
{

}

void Element::AttachToSquare()
{
    if(!(sq->s[x][y])){
        sq->s[x][y] = Style;
    }
}



