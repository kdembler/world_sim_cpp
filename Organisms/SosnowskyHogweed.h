#ifndef SYMULACJA_CPP_SOSNOWSKYHOGWEED_H
#define SYMULACJA_CPP_SOSNOWSKYHOGWEED_H

#include "Plant.h"

class SosnowskyHogweed : public Plant {
public:
    SosnowskyHogweed(World *, Point);

protected:
    void getEaten(Organism *) override;

    void action() override;

    int burn();

private:
    Organism *clone(Point) override;

};


#endif
