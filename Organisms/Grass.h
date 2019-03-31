#ifndef SYMULACJA_CPP_GRASS_H
#define SYMULACJA_CPP_GRASS_H

#include "Plant.h"

class Grass : public Plant {
public:
    Grass(World *, Point);

private:
    Organism *clone(Point) override;
};


#endif
