#pragma once
#include "map.h"
#include <vector>
#include "IDraw.h"
#include "Wall.h"

using namespace std;

class Board{
private:
    int stage;
    int maxRows,maxCols;
public:
    ~Board(){}
    Board(){
        getmaxyx(stdscr, maxRows, maxCols);
        stage =0;
    }
    void init(vector<Wall*>& d);
    void set_stage(int stage);
    int get_maxRows();
    int get_maxCols();
    void stage_up();
};