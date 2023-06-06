#include "Gate.h"

int Gate::get_lifetime(){
    return lifetime;
}

void Gate::Setpos(int x, int y){
    posX=x;
    posY=y;
    exist=false;
}

bool Gate::Collision(int x, int y){
    if(posX==x && posY==y)
        return true;
    return false;
}

void Gate::Draw(WINDOW *win){
    mvwprintw(win,posY,posX,"★");
}