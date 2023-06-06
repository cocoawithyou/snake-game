#pragma once
#include "Board.h"
#include <deque>
#include "IDraw.h"

using namespace std;
class Snake :public IDraw{
private:
    int direction;
    bool gameOver;
    pair<int,int> head;
    pair<int,int> tail;
    deque<pair<int, int>> body;
    int len;
public:
    Snake();
    Snake(int startX, int startY);
    void HandleInput(int key);
    void Update();
    void Set_gameOver();
    void Draw(WINDOW *win);
    bool IsGameOver() const;
    pair<int,int> Get_head();
    pair<int,int> Get_tail();
};
