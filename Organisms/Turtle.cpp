#include <random>

#include "Turtle.h"
#include "Animal.h"

Turtle::Turtle(World *w, Point p) : Animal(w, p, 2, 1, '@', "zolw") {
}

Organism *Turtle::clone(Point p) {
    return new Turtle(world, p);
}

void Turtle::move() {
    if (Utilities::randRange(1, 4) == 4)
        makeMove(genNewPos());
}

bool Turtle::fight(Organism *origin) {
    if (origin->getStrength() < 5) {
        emitMessage("odbija atak");
        return false;
    }
    else return makeFight(origin);
}