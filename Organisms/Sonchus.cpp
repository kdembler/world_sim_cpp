#include "Sonchus.h"

Sonchus::Sonchus(World *w, Point p) : Plant(w, p, 0, '$', "mlecz") {
}

Organism *Sonchus::clone(Point p) {
    return new Sonchus(world, p);
}

void Sonchus::sow() {
    for (int i = 0; i < 3; i++) {
        makeSow();
    }
}


