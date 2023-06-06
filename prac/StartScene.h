#pragma once
#include <ncurses.h>
#include "map.h"

void Start_page(){
    int maxRow, maxCols;
    getmaxyx(stdscr, maxRow, maxCols);

    int height = maxRow * 0.8;
    int width = maxCols * 0.4;
    int startX = (maxCols - width) / 4;
    int startY = (maxRow - height) / 2 + 4;

    WINDOW* win1 = newwin(height, width, startY, startX);
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

    while ((ch = getch()) != ' ') {
      wrefresh(startwin);
    }
    delwin(startwin);
    clear();
}