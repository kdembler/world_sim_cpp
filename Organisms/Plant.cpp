#include <random>

#include "Plant.h"

Plant::Plant(World *w, Point p, int s, char sym, string n) : Organism(w, p, s, 0, sym, n) {}

void Plant::action() {
    inAction = true;
    age++;
    sow();
    if (shouldDie) {
        world->removeOrganism(this);
    }
    inAction = false;
}

void Plant::sow() {
    makeSow();
}

bool Plant::makeSow() {
    int upper = (int) (sowProbability * 100);
    if (Utilities::randRange(1, 100) < upper) {
        Point childPos = Utilities::findFree(world, pos);
        if (childPos.y != -1 && childPos.x != -1) {
            Organism *child = clone(childPos);
            world->addOrganism(child);
            emitMessage("rozprzestrzenia sie na " + childPos.toString());
        }
    }
    return false;
}

void Plant::getEaten(Organism *origin) {
    emitMessage("zostaje zjedzona przez " + origin->getName());
    die();
}

bool Plant::collision(Organism *origin) {
    getEaten(origin);
    return true;
}
