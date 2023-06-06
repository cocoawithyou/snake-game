#pragma once
#include <ncurses.h>

class IDraw{
    public:
    virtual void Draw(WINDOW *win)=0;
};
