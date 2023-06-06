#pragma once
#include <ncurses.h>
#include "Snake.h"
#include "Board.h"
#include "Obmanager.h"

class SnakeGame {
private:
    WINDOW* win;    
    int height,width,startX,startY;
    Snake *snake;
    Board *board;
    Obm *obm;
    vector<Wall*> d;
    long long timelap;
public:
    //SnakeGame(){};
    SnakeGame();
    ~SnakeGame(){
        for(auto &i:d){
            delete i;
        }
        delete snake;
        delete win;
        delete board;
    }
    void StartGame();
    void ProcessInput();
    void Checkcollision();
    void UpdateGame();
    void DrawGame();
    void Timego();
};

