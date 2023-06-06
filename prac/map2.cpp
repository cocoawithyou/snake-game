#include <ncurses.h>
#include <string>
#include <vector>
#include "map.h"

using namespace std;

int main() {

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_BLACK);


    int maxRow, maxCols;
    getmaxyx(stdscr, maxRow, maxCols);

    int height = maxRow * 0.8;
    int width = maxCols * 0.4;
    int startX = (maxCols - width) / 4;
    int startY = (maxRow - height) / 2 + 4;


    WINDOW *win1 = newwin(height, width, startY, startX);
    WINDOW *win2 = newwin(height, width, startY, startX);
    WINDOW *win3 = newwin(height, width, startY, startX);
    WINDOW *win4 = newwin(height, width, startY, startX);


    refresh();

    WINDOW *startwin = newwin(maxRow, maxCols, 0, 0);
    wclear(startwin);

    wattron(startwin, COLOR_PAIR(4));
    mvwprintw(startwin, 10, maxCols/2-45, "___________________________________________________________________________________________");
    mvwprintw(startwin, 11, maxCols/2-45, "      __      _     _    __      _    _    _____           __      __      _   _     _____");
    mvwprintw(startwin, 12, maxCols/2-45, "    /    )    /|   /     / |     /  ,'     /    '        /    )    / |     /  /|     /    '");
    mvwprintw(startwin, 13, maxCols/2-45, "----(--------/-| -/-----/__|----/_.'------/__-----------/---------/__|----/| /-|----/__----");
    mvwprintw(startwin, 14, maxCols/2-45, "     (      /  | /     /   |   /  (      /             /  --,    /   |   / |/  |   /       ");
    mvwprintw(startwin, 15, maxCols/2-45, "_(____/____/___|/_____/____|__/____(____/____ ________(____/____/____|__/__/___|__/____ ___");
    wattroff(startwin, COLOR_PAIR(4));

    wattron(startwin, COLOR_PAIR(3));
    mvwprintw(startwin, maxRow/2-2, maxCols/2 -16, "Press 'Spacebar' to start the game");    
    wattroff(startwin, COLOR_PAIR(3));

    wattron(startwin, COLOR_PAIR(1));
    mvwprintw(startwin, maxRow/2, maxCols/2 -12, "Press 'Q' to quit the game");
    wattroff(startwin, COLOR_PAIR(1));


    mvwprintw(startwin, maxRow/2+5, maxCols/2 - 14, " ____  ____  ____  ____  ____ ");
    mvwprintw(startwin, maxRow/2+6, maxCols/2 - 14, "||P ||||R ||||E ||||S ||||S ||");
    mvwprintw(startwin, maxRow/2+7, maxCols/2 - 14, "||__||||__||||__||||__||||__||");
    mvwprintw(startwin, maxRow/2+8, maxCols/2 - 14, "|/__|||/__|||/__|||/__|||/__||");

    mvwprintw(startwin, maxRow/2+12, maxCols/2 -12, "> Press 1 to start STAGE 1");
    mvwprintw(startwin, maxRow/2+14, maxCols/2 -12, "> Press 2 to start STAGE 2");
    mvwprintw(startwin, maxRow/2+16, maxCols/2 -12, "> Press 3 to start STAGE 3");
    mvwprintw(startwin, maxRow/2+18, maxCols/2 -12, "> Press 4 to start STAGE 4");

    wrefresh(startwin);


    int ch;

    while ((ch = getch()) != 'q') {

      
        for(int i= 0; i<maxRow; i++){
            for(int j=0; j<maxCols; j++){
                wattron(startwin, COLOR_PAIR(2));
                mvwprintw(startwin, i, j, " ");
                wattroff(startwin, COLOR_PAIR(2));
            }
        }
        wrefresh(startwin);

        switch (ch) {
            case ' ':
            case '1':
                wclear(win1);

                for (int i = 0; i < 33; i++) {
                    for (int j = 0; j < 64; j++) {
                        if (map[0][i][j] == 0) {
                            wattron(win1, COLOR_PAIR(2));
                            mvwprintw(win1, i, j, "%d", map[0][i][j]);
                            wattroff(win1, COLOR_PAIR(2));
                        } else if (map[0][i][j] == 1) {
                            wattron(win1, COLOR_PAIR(4));
                            mvwprintw(win1, i, j, "%c", ':');
                            wattroff(win1, COLOR_PAIR(4));
                        } else if (map[0][i][j] == 2) {
                            wattron(win1, COLOR_PAIR(5));
                            mvwprintw(win1, i, j, "%c", 'X');
                            wattroff(win1, COLOR_PAIR(5));
                        }
                    }
                }
                wrefresh(win1);
                break;

            case '2':
                wclear(win2);

                for(int i = 0; i<33; i++){
                    for(int j = 0; j<64; j++){
                        if(map[1][i][j] == 0){
                            wattron(win2, COLOR_PAIR(2));
                            mvwprintw(win2, i, j, "%d", map[1][i][j]);
                            wattroff(win2, COLOR_PAIR(2));
                        } else if(map[1][i][j] == 1){
                            wattron(win2, COLOR_PAIR(4));
                            mvwprintw(win2, i, j, "%c", ':');
                            wattroff(win2, COLOR_PAIR(4));
                        } else if(map[1][i][j] == 2){
                            wattron(win2, COLOR_PAIR(5));
                            mvwprintw(win2, i, j, "%c", 'X');
                            wattroff(win2, COLOR_PAIR(5));
                        }
                    }
                }
                wrefresh(win2);
                break;

            case '3':
                wclear(win3);

                for(int i = 0; i<33; i++){
                    for(int j = 0; j<64; j++){
                        if(map[2][i][j] == 0){
                            wattron(win3, COLOR_PAIR(2));
                            mvwprintw(win3, i, j, "%d", map[2][i][j]);
                            wattroff(win3, COLOR_PAIR(2));
                        } else if(map[2][i][j] == 1){
                            wattron(win3, COLOR_PAIR(4));
                            mvwprintw(win3, i, j, "%c", ':');
                            wattroff(win3, COLOR_PAIR(4));
                        } else if(map[2][i][j] == 2){
                            wattron(win3, COLOR_PAIR(5));
                            mvwprintw(win3, i, j, "%c", 'X');
                            wattroff(win3, COLOR_PAIR(5));
                        }
                    }
                }
                wrefresh(win3);
                break;

            case '4':
                wclear(win4);

                for(int i = 0; i<33; i++){
                    for(int j = 0; j<64; j++){
                        if(map[3][i][j] == 0){
                            wattron(win4, COLOR_PAIR(2));
                            mvwprintw(win4, i, j, "%d", map[3][i][j]);
                            wattroff(win4, COLOR_PAIR(2));
                        } else if(map[3][i][j] == 1){
                            wattron(win4, COLOR_PAIR(4));
                            mvwprintw(win4, i, j, "%c", ':');
                            wattroff(win4, COLOR_PAIR(4));
                        } else if(map[3][i][j] == 2){
                            wattron(win4, COLOR_PAIR(5));
                            mvwprintw(win4, i, j, "%c", 'X');
                            wattroff(win4, COLOR_PAIR(5));
                        }
                    }
                }
                wrefresh(win4);
                break;
        }
    }

  delwin(win1);
  delwin(win2);
  delwin(win3);
  delwin(win4);      
  endwin();

  return 0;
}
