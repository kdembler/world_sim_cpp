#include "SosnowskyHogweed.h"
#include "Animal.h"

SosnowskyHogweed::SosnowskyHogweed(World *w, Point p) : Plant(w, p, 10, '?', "barszcz sosnowskiego") {
}

Organism *SosnowskyHogweed::clone(Point p) {
    return new SosnowskyHogweed(world, p);
}

void SosnowskyHogweed::getEaten(Organism *o) {
    o->die();
    Plant::getEaten(o);
}

void SosnowskyHogweed::action() {
    int burned = burn();
    if (burned > 0) emitMessage("spala " + to_string(burned) + " sasiadow");
    Plant::action();
}

int SosnowskyHogweed::burn() {
    int numOfPoints = 4;
    int numOfBurned = 0;
    Point pointsToBurn[] = {Point(0, -1), Point(0, 1), Point(-1, 0),
                            Point(1, 0)};
    for (int i = 0; i < numOfPoints; i++) {
        Animal *toBurn = dynamic_cast<Animal *>(world->getOrganismAt(pointsToBurn[i] + pos));
        if (toBurn != nullptr) {
            toBurn->die();
            numOfBurned++;
        }
    }
    return numOfBurned;
}
