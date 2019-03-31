#include "Fox.h"
#include "Animal.h"

Fox::Fox(World *w, Point p) : Animal(w, p, 3, 7, '>', "lis") {
}

Organism *Fox::clone(Point p) {
    return new Fox(world, p);
}

void Fox::move() {
    Point tmp = Utilities::findFree(world, pos);
    if (tmp.y == -1 && tmp.x == -1) return;
    Point newPos = genNewPos();
    Organism *atNewPos = world->getOrganismAt(newPos);
    while (atNewPos != NULL && atNewPos->getStrength() > strength) {
        newPos = genNewPos();
        atNewPos = world->getOrganismAt(newPos);
    }
    makeMove(newPos);
}