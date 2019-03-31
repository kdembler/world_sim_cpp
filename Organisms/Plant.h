#ifndef SYMULACJA_CPP_PLANT_H
#define SYMULACJA_CPP_PLANT_H

#include "Organism.h"
#include "../World.h"

class Plant : public Organism {
public:
    Plant(World*, Point, int, char, string);

    virtual void action() override;

protected:
    float sowProbability = 0.02;

    virtual void getEaten(Organism*);

    bool collision(Organism*) override;

    virtual void sow();

    bool makeSow();
};


#endif
