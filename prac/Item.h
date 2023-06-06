#pragma once
#include "ICollision.h"
#include "IDraw.h"

class Item:public ICollision,public IDraw{
private:
    int lifetime;
    int posX,posY;
    int type;
public:
    Item(int x=0,int y=0,int t=0);
    ~Item(){}
    int Get_lifetime();
    void Setpos(int x, int y);
    void Update();
    bool Collision(int x, int y);
    void Draw(WINDOW *win);
};