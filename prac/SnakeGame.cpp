#include "SnakeGame.h"
#include <cstdlib>
#include <ctime>
 
SnakeGame::SnakeGame() {
    srand(time(NULL));
    timelap=0;
    board = new Board();
    board->init(d);
    height = board->get_maxRows() * 0.8;
    width = board->get_maxCols() * 0.8;
    startX = (board->get_maxCols() - width) / 4 + 8;
    startY = (board->get_maxRows() - height) / 2 + 4;
    win= newwin(height, width, startY, startX);
    snake = new Snake(width / 2, height / 2);
    obm = new Obm();
}

void SnakeGame::StartGame() {
    // 게임 루프 구현
    while (!snake->IsGameOver()) {
        Timego();
        ProcessInput();
        DrawGame();
        UpdateGame();
        Checkcollision();
        wrefresh(win);
        // 500ms 동안 대기
        napms(500);
    }
}

void SnakeGame::ProcessInput() {
    int key = getch();
    snake->HandleInput(key);
}

void SnakeGame::Checkcollision(){
    pair<int,int> tmp = snake->Get_head();
    for(auto &i:d){
        //snake의 머리가 벽에 충돌
        if(tmp.first==i->get_x() &&tmp.second==i->get_y()){
            //게임 종료
            snake->Set_gameOver();
        }
    }
}

void SnakeGame::UpdateGame() {
    snake->Update();
    while(obm->get_gate_size()!=2){
        int x,y,num;
        //for(auto &i:obm->)
        num=rand()%d.size();
        if(d[num]->can()){
            Gate *gate = new Gate();
            x = d[num]->get_x();
            y = d[num]->get_y();
            gate->Setpos(x,y);
        }
    }

}

void SnakeGame::DrawGame() {
    wclear(win);
    for(auto &i:d){
        i->Draw(win);
    }
    //뱀 그리기
    snake->Draw(win);
}

void SnakeGame::Timego(){
    timelap++;
}