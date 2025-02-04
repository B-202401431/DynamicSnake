#ifndef SNAKE_H
#define SNAKE_H
#include"cord.h"
#include<windows.h>
#include<vector>
using namespace std;

class Snake
{
    private:
    cord pos;
    int len;
    int vel;
    char dir;
    vector<cord> body;
    
    public:

    Snake(cord pos,int vel)
    {
        this->pos=pos;
        this->vel=vel;
        dir='n';
        len=1;
        body.push_back(pos);

    }

    int get_length()
    {
        return len;
    }

    void change_dir(char dir)
    {
        this->dir=dir;
    }

    void move()
    {
        switch(dir)
        {
            case 'u': pos.y-=vel; break;
            case 'd': pos.y+=vel; break;
            case 'r': pos.x+=vel; break;
            case 'l': pos.x-=vel; break;
        }
        body.push_back(pos);
        if (body.size()>len)
        {
            body.erase(body.begin());
        }
        
    }

    cord get_pos()
    {
        return pos;
    }

    bool food_eaten(cord food_pos)
    {
        if(food_pos.x==pos.x && food_pos.y==pos.y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void length_inc()
    {
        len++;
    }

    bool snake_collide_border()
    {
        if (pos.x<1 || pos.x>width-2 || pos.y<1 || pos.y>height-2)
        {
            return true;
        }
        for (int i = 0; i <len-2; i++)
        {
            if (pos.x==body[i].x && pos.y==body[i].y)
            {
                return true;
            }
            
        }
        return false;
        
        
    }

    vector<cord> snake_body()
    {
        return body;
    }
};


#endif