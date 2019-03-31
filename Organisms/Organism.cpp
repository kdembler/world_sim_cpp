#include "Organism.h"

void Organism::draw() {
    world->putTranslated(pos, sym);
}

Organism::Organism(World *world, Point pos, int strength, int initiative, char sym, string name) {
    this->world = world;
    this->pos = pos;
    this->strength = strength;
    this->initiative = initiative;
    this->age = 0;
    this->sym = sym;
    this->name = name;
}

Point Organism::getPos() {
    return pos;
}

void Organism::die() {
    emitMessage("umiera");
    if (inAction) shouldDie = true;
    else world->removeOrganism(this);

}

int Organism::getAge() {
    return age;
}

int Organism::getInitiative() {
    return initiative;
}

int Organism::getStrength() {
    return strength;
}

void Organism::setStrength(int s) {
    strength = s;
}

void Organism::emitMessage(string msg) {
    world->addMessage(name + pos.toString() + ": " + msg);
}

string Organism::getName() {
    return name;
}

string Organism::getSym() {
    return string(1, sym);
}

void Organism::setAge(int a) {
    age = a;
}
