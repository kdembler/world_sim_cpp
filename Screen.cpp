#include <ncurses.h>

#include "Screen.h"
#include "Utilities.h"

void Screen::init() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
}

void Screen::implode() {
    endwin();
}

void Screen::put(Point p, std::string s) {
    mvprintw(p.y, p.x, s.c_str());
}

int Screen::get() {
    return getch();
}

void Screen::update() {
    refresh();
}

void Screen::clean() {
    clear();
}


