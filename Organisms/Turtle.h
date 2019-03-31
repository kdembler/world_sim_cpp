#ifndef SYMULACJA_CPP_TURTLE_H
#define SYMULACJA_CPP_TURTLE_H

#include "Animal.h"

class Turtle : public Animal {
public:
    Turtle(World *, Point);

protected:
    void move() override;

    bool fight(Organism *) override;

private:
    Organism *clone(Point) override;
};


#endif
