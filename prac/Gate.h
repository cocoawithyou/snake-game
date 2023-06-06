#pragma once
#include "ICollision.h"
#include "IDraw.h"

using namespace std;
class Gate:public ICollision,public IDraw{
    private:
    int lifetime;
    int posX,posY;
    bool exist;
public:
    Gate(){}
    ~Gate(){}
    int get_lifetime();
    void Setpos(int x, int y);
    bool Collision(int x, int y);
    void Draw(WINDOW *win);
};

