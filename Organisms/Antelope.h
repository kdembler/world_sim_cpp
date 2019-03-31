#ifndef SYMULACJA_CPP_ANTELOPE_H
#define SYMULACJA_CPP_ANTELOPE_H

#include "Animal.h"

class Antelope : public Animal {
public:
    Antelope(World *, Point);

protected:
    bool fight(Organism *) override;

private:
    Organism *clone(Point) override;
};


#endif
