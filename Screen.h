#ifndef SYMULACJA_CPP_SCREEN_H
#define SYMULACJA_CPP_SCREEN_H

#include <string>

#include "Utilities.h"

class Screen {
public:
    static void init();
    static void put(Point p, std::string s);
    static int get();
    static void update();
    static void clean();
    static void implode();

private:
    Screen() {};
};

#endif
