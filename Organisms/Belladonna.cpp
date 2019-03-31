#include "Belladonna.h"

Belladonna::Belladonna(World *w, Point p) : Plant(w, p, 99, '!', "wilcze jagody") {
}

Organism *Belladonna::clone(Point p) {
    return new Belladonna(world, p);
}

void Belladonna::getEaten(Organism *o) {
    o->die();
    Plant::getEaten(o);
}