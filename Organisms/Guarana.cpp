#include "Guarana.h"

Guarana::Guarana(World *w, Point p) : Plant(w, p, 0, 'G', "guarana") {
}

Organism *Guarana::clone(Point p) {
    return new Guarana(world, p);
}

void Guarana::getEaten(Organism *o) {
    o->setStrength(o->getStrength() * 3);
    Plant::getEaten(o);
}
