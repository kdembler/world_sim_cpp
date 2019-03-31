#ifndef SYMULACJA_CPP_BELLADONNA_H
#define SYMULACJA_CPP_BELLADONNA_H

#import "Plant.h"

class Belladonna : public Plant {
public:
    Belladonna(World *, Point);

protected:
    void getEaten(Organism *) override;

private:
    Organism *clone(Point) override;
};


#endif
