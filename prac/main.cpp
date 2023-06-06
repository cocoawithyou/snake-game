#include "SnakeGame.h"
#include "StartScene.h"

int main() {
    // ncurses 초기화
    initscr();
    // 입력 설정
    keypad(stdscr, true);
    noecho();
    curs_set(0);
    Start_page();
    nodelay(stdscr, true);
    // SnakeGame 객체 생성
    SnakeGame game;
    game.StartGame();

    // ncurses 종료
    endwin();

    return 0;
}
