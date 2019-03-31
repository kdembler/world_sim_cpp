#include "Wolf.h"
#include "Animal.h"

Wolf::Wolf(World *w, Point p) : Animal(w, p, 9, 5, '#', "wilk") {
}

Organism *Wolf::clone(Point p) {
    return new Wolf(world, p);
}
