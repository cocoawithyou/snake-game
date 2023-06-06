#pragma once
#include "IDraw.h"

using namespace std;

class Wall:public IDraw{
private:
    int posX;
    int posY;
    int info;
    bool candi_gate;
public:
    Wall(){
        posX=0;
        posY=0;
        info = 0;
        candi_gate=false;
    };
    ~Wall(){};
    void Draw(WINDOW *win);
    void Setinfo(int x, int y,bool cd_gate,int info=0);
    int get_x();
    int get_y();
    bool can();
};