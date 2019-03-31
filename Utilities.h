#ifndef SYMULACJA_CPP_UTILITIES_H
#define SYMULACJA_CPP_UTILITIES_H

#include <random>
#include <string>

#define KEY_ENTER 10
#define KEY_ESC 27
#define KEY_LEFT 260
#define KEY_UP 259
#define KEY_RIGHT 261
#define KEY_DOWN 258

#define SCREEN_WIDTH 160
#define SCREEN_HEIGHT 55

class World;

struct Point {
    Point();

    Point(int y, int x);

    std::string toString();

    Point operator+(Point o);

    bool operator==(Point o);

    bool operator!=(Point o);

    int y, x;
};

class Utilities {
public:

    static void init();

    static int randRange(int, int);

    static Point findFree(World *w, Point origin);


private:
    Utilities();

    static std::mt19937 generator;
    static std::random_device randomDevice;
};


#endif
