#include "Board.h"

void Board::init(vector<Wall*>& d){
    for (int i = 0; i < 33; i++) {
        for (int j = 0; j < 64; j++) {
            if (Map::map[stage][i][j] == 0){
                continue;
            }
            else if (Map::map[stage][i][j]  == 1) {
                Wall *wall = new Wall;
                wall->Setinfo(j,i,true,1);
                d.emplace_back(wall);
            } else if (Map::map[stage][i][j]  == 2) {
                Wall *wall = new Wall;
                wall->Setinfo(j,i,false,2);
                d.emplace_back(wall);
            }
        }
    }
}

void Board::set_stage(int stage){
    this->stage = stage;
}

int Board::get_maxRows(){
    return maxRows;
}
int Board::get_maxCols(){
    return maxCols;
}

void Board::stage_up(){
    stage+=1;    
}