#ifndef SYMULACJA_CPP_HUMAN_H
#define SYMULACJA_CPP_HUMAN_H

#include "Animal.h"

class Human : public Animal {
public:
    Human(World *, Point);

    void setDirection(int);

    void activateAbility();

    int getCooldown();

    void setCooldown(int);

protected:
    int direction = 0;

    void move() override;

    void action() override;

    int burn();

    int currentCooldown = 0;

    int cooldown = 5;

private:
    Organism *clone(Point) override;
};

#endif
