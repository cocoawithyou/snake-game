#include "Snake.h"
#include <iostream>
#include "map.h"
Snake::Snake() {

}

Snake::Snake(int startX, int startY) {
    head = make_pair(startX / 2,startY / 2);
    tail = make_pair(startX / 2+2,startY / 2);
    direction = KEY_LEFT;
    gameOver = false;
    len =3;
    body.push_back(head);
    body.push_back({ head.first + 1, head.second });  // 몸통 초기 위치 설정
    body.push_back({ head.first + 2, head.second });  // 몸통 초기 위치 설정
}
void Snake::HandleInput(int key) {
    // 방향을 변경하지 않는 키 입력은 무시
    if (key == ERR)
        return;

    // 현재 방향과 반대 방향의 키 입력이 들어오면 게임 중지
    if ((key == KEY_UP && direction == KEY_DOWN) ||
        (key == KEY_DOWN && direction == KEY_UP) ||
        (key == KEY_LEFT && direction == KEY_RIGHT) ||
        (key == KEY_RIGHT && direction == KEY_LEFT)) {
        gameOver = true;
        return;
    }

    // 키 입력에 따라 방향 변경
    direction = key;
}

void Snake::Update() {
    // 현재 방향에 따라 뱀의 위치 업데이트
    switch (direction) {
        case KEY_UP:
            head.second--;
            break;
        case KEY_DOWN:
            head.second++;
            break;
        case KEY_LEFT:
            head.first--;
            break;
        case KEY_RIGHT:
            head.first++;
            break;
    }

    // 현재 위치와 게임 오버 조건을 검사하고 게임 오버 처리
    // 현재 위치가 화면 바깥으로 나가는 경우 게임 오버로 간주
    if (head.first < 0 || head.second < 0 || head.first >= Map::BOARD_COL || head.second >= Map::BOARD_ROW) {
        gameOver = true;
        return;
    }

    // 뱀의 몸통을 이동시킴,head tail값 재설정
    body.push_front(head);
    body.pop_back();
    tail = make_pair(body[len-1].first,body[len-1].second);

}

void Snake::Draw(WINDOW *win) {
    //몸통을 그리고, 머리 그리기
    for(const auto& element:body){
        mvwprintw(win,element.second,element.first,"#");
    }
    mvwprintw(win,head.second,head.first,"@");
}

bool Snake::IsGameOver() const {
    return gameOver;
}

pair<int,int> Snake::Get_head(){
    return head;
}

pair<int,int> Snake::Get_tail(){
    return tail;
}

void Snake::Set_gameOver(){
    gameOver=true;
}