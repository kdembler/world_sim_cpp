#include "Grass.h"

Grass::Grass(World *w, Point p) : Plant(w, p, 0, '=', "trawa") {
}

Organism *Grass::clone(Point p) {
    return new Grass(world, p);
}
