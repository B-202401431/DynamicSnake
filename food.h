#ifndef FOOD_H
#define FOOD_H
#include<stdlib.h>

#include"cord.h"
class Food
{
    private:
    cord pos;
    public:
    Food()
    {
    }
    cord get_food_pos()
    {
        return pos;
    }

    void food_gen()
    {
        pos.x=rand()% (width-3) +2;
        pos.y=rand()% (height-3)+2;
    }
};

#endif