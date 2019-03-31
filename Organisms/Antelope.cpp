#include "Antelope.h"
#include "Animal.h"

#include <random>

Antelope::Antelope(World *w, Point p) : Animal(w, p, 4, 4, 'A', "antylopa") {
    speed = 2;
}

Organism *Antelope::clone(Point p) {
    return new Antelope(world, p);
}

bool Antelope::fight(Organism *origin) {
    if (Utilities::randRange(1,2) == 2) {
        Point newPos = Utilities::findFree(world, pos);
        if (newPos.y != -1 && newPos.x != -1) {
            emitMessage("ucieka przed walka");
            makeMove(newPos);
            return true;
        }
    }
    return makeFight(origin);
}

