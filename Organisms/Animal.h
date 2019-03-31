#ifndef SYMULACJA_CPP_ANIMAL_H
#define SYMULACJA_CPP_ANIMAL_H

#include "Organism.h"
#include "../World.h"

class Animal : public Organism {
public:
    Animal(World *w, Point p, int s, int i, char sym, string n);

    bool isActive();

    void deactivate();

    void action() override;

protected:
    int speed = 1;

    bool active;

    virtual bool collision(Organism *origin) override;

    virtual bool fight(Organism *origin);

    virtual bool makeFight(Organism *origin);

    Point genNewPos();

    virtual void move();

    virtual void makeMove(Point);
};


#endif
