#include "Sheep.h"
#include "Animal.h"

Sheep::Sheep(World *w, Point p) : Animal(w, p, 4, 4, '^', "owca") {
}

Organism *Sheep::clone(Point p) {
    return new Sheep(world, p);
}
