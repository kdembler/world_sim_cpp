#ifndef SYMULACJA_CPP_SONCHUS_H
#define SYMULACJA_CPP_SONCHUS_H

#include "Plant.h"

class Sonchus : public Plant {
public:
    Sonchus(World *, Point);

protected:
    void sow() override;

private:
    Organism *clone(Point) override;
};


#endif
