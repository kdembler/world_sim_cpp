#ifndef SYMULACJA_CPP_GUARANA_H
#define SYMULACJA_CPP_GUARANA_H

#include "Plant.h"

class Guarana : public Plant {
public:
    Guarana(World *, Point);

protected:
    void getEaten(Organism *) override;

private:
    Organism *clone(Point) override;
};


#endif
