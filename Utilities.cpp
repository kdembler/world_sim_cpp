#include <vector>
#include <random>

#include "Utilities.h"
#include "World.h"
#include "Organisms/Organism.h"

std::mt19937 Utilities::generator;
std::random_device Utilities::randomDevice;

Point::Point() : y(0), x(0) {}

Point::Point(int y, int x) : y(y), x(x) {}

Point Point::operator+(Point o) {
    return Point(y + o.y, x + o.x);
}

bool Point::operator==(Point o) {
    return o.y == y && o.x == x;
}

bool Point::operator!=(Point o) {
    return !(o.y == y && o.x == x);
}

string Point::toString() {
    return "(" + to_string(y) + ", " + to_string(x) + ")";
}

void Utilities::init() {
    generator = std::mt19937(randomDevice());
}

Point Utilities::findFree(World *w, Point origin) {
    int y = origin.y, x = origin.x;
    int height = w->getHeight(), width = w->getWidth();
    vector<Point> points;
    Organism ***board = w->board;
    if (x > 0 && board[y][x - 1] == NULL) points.push_back(Point(y, x - 1));
    if (x < width - 1 && board[y][x + 1] == NULL) points.push_back(Point(y, x + 1));
    if (y > 0 && board[y - 1][x] == NULL) points.push_back(Point(y - 1, x));
    if (y < height - 1 && board[y + 1][x] == NULL) points.push_back(Point(y + 1, x));
    if (points.size() != 0) {
        return points[randRange(0, (int) points.size() - 1)];
    } else return Point(-1, -1);
}

Utilities::Utilities() {
}

int Utilities::randRange(int lower, int upper) {
    uniform_int_distribution<int> dist(lower, upper);
    return dist(generator);
}
