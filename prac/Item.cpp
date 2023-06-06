#include "Item.h"

Item::Item(int x,int y,int t){
    posX=x;
    posY=y;
    type=t;
}

int Item::Get_lifetime(){
    return lifetime;
}

void Item::Update(){
    lifetime+=1;
}

void Item::Setpos(int x, int y){
    posX=x;
    posY=y;
}

bool Item::Collision(int x, int y){
    if(posX==x && posY==y)
        return true;
    return false;
}

void Item::Draw(WINDOW *win){
    if(type==0)
        mvwprintw(win,posY,posX,"A");
    else if(type ==1)
        mvwprintw(win,posY,posX,"P");
}