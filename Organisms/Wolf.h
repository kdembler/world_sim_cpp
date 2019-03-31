#ifndef SYMULACJA_CPP_WOLF_H
#define SYMULACJA_CPP_WOLF_H

#include "Animal.h"

class Wolf : public Animal {
public:
    Wolf(World *, Point);

private:
    Organism *clone(Point) override;
};


#endif
