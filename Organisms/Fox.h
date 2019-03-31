#ifndef SYMULACJA_CPP_FOX_H
#define SYMULACJA_CPP_FOX_H

#include "Animal.h"

class Fox : public Animal {
public:
    Fox(World *, Point);

protected:
    void move() override;

private:
    Organism *clone(Point) override;
};


#endif
