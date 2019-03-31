#ifndef SYMULACJA_CPP_ORGANISM_H
#define SYMULACJA_CPP_ORGANISM_H

#include "../World.h"
#include "../Utilities.h"

class Organism {
public:
    Organism(World *world, Point pos, int strength, int initiative, char sym, string name);

    virtual ~Organism() {}

    virtual void action() = 0;

    virtual bool collision(Organism *origin) = 0;

    virtual void draw();

    virtual void die();

    Point getPos();

    int getInitiative();

    int getAge();

    void setAge(int);

    int getStrength();

    void setStrength(int);

    string getName();

    string getSym();

protected:
    int age, strength, initiative;
    bool inAction;
    Point pos;
    char sym = '?';
    string name = "undefined";
    World *world;
    bool shouldDie = false;

    virtual void emitMessage(std::string);

    virtual Organism *clone(Point) = 0;
};

#endif