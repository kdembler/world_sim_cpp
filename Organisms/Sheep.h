#ifndef SYMULACJA_CPP_SHEEP_H
#define SYMULACJA_CPP_SHEEP_H

#include "Animal.h"

class Sheep : public Animal {
public:
    Sheep(World *, Point);

private:
    Organism *clone(Point) override;
};


#endif
