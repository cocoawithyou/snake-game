#include "Wall.h"
#include "map.h"


void Wall::Draw(WINDOW *win){
    if(info ==0){
        mvwprintw(win,posY,posX," ");
    }
    else if(info==1){
        mvwprintw(win,posY,posX,"O");
    }
    else if(info ==2){
        mvwprintw(win,posY,posX,"X");
    }
    
}

void Wall::Setinfo(int x, int y,bool cd_gate,int c){
    posX = x;
    posY = y;
    info = c;
    candi_gate = cd_gate;
}


int Wall::get_x(){
    return posX;
}
int Wall::get_y(){
    return posY;        
}

bool Wall::can(){
    return candi_gate;
}