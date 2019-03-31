#include <random>

#include "Animal.h"

Animal::Animal(World *w, Point p, int s, int i, char sym, string n) : Organism(w, p, s, i, sym, n) {}

Point Animal::genNewPos() {
    // 1 - left
    // 2 - up
    // 3 - right
    // 4 - down
    vector<int> directions;
    int width = world->getWidth(), height = world->getHeight();

    if (pos.x - speed > 0) directions.push_back(1);
    if (pos.y - speed > 0) directions.push_back(2);
    if (pos.x + speed < width) directions.push_back(3);
    if (pos.y + speed < height) directions.push_back(4);

    int idx = Utilities::randRange(0, (int) directions.size() - 1);
    int direction = directions[idx];
    Point newPos(pos);
    switch (direction) {
        case 1:
            newPos.x -= speed;
            break;
        case 2:
            newPos.y -= speed;
            break;
        case 3:
            newPos.x += speed;
            break;
        case 4:
            newPos.y += speed;
            break;
    }
    return newPos;
}

void Animal::makeMove(Point newPos) {
    bool move = true;
    if (world->getOrganismAt(newPos) != NULL) {
        move = world->getOrganismAt(newPos)->collision(this);
    }
    if (move) {
        world->setOrganismAt(NULL, pos);
        world->setOrganismAt(this, newPos);
        pos = newPos;
    }
}

void Animal::move() {
    makeMove(genNewPos());
}

void Animal::action() {
    active = true;
    inAction = true;
    age++;
    move();
    if (shouldDie) {
        world->removeOrganism(this);
    }
    inAction = false;
}

bool Animal::makeFight(Organism *origin) {
    if (origin->getStrength() >= strength) {
        emitMessage("przegrywa walke z " + origin->getName());
        die();
        return true;
    } else {
        emitMessage("wygrywa walke z " + origin->getName());
        origin->die();
        return false;
    }
}

bool Animal::fight(Organism *origin) {
    return makeFight(origin);
}

bool Animal::collision(Organism *origin) {
    Animal* a = dynamic_cast<Animal*>(origin);
    if (typeid(*origin).name() == typeid(*this).name()) {
        Point childPos = Utilities::findFree(world, pos);
        if (childPos.y != -1 && childPos.x != -1 && active && a->isActive()) {
            Organism *child = clone(childPos);
            world->addOrganism(child);
            deactivate();
            a->deactivate();
            emitMessage("rodzi dziecko na " + childPos.toString());
        }
        return false;
    }
    return fight(origin);
}

bool Animal::isActive() {
    return active;
}

void Animal::deactivate() {
    active = false;
}
