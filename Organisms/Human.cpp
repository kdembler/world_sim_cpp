#include "Human.h"
#include "Animal.h"

Human::Human(World *w, Point p) : Animal(w, p, 5, 4, 'H', "czlowiek") {
}

void Human::move() {
    Point newPos(pos);
    if (direction == 1 && pos.x > 0) newPos.x--;
    else if (direction == 2 && pos.y > 0) newPos.y--;
    else if (direction == 3 && pos.x < world->getWidth() - 1) newPos.x++;
    else if (direction == 4 && pos.y < world->getHeight() - 1) newPos.y++;
    if (newPos != pos)
        makeMove(newPos);
    direction = 0;
}

Organism *Human::clone(Point p) {
    return new Human(world, p);
}

void Human::setDirection(int d) {
    direction = d;
}

void Human::action() {
    if (currentCooldown < 0) {
        int burned = burn();
        if (burned > 0) emitMessage("calopalenie spala " + to_string(burned) + " sasiadow");
        if (++currentCooldown == 0) currentCooldown = cooldown;
    } else if (currentCooldown > 0) currentCooldown--;

    Animal::action();
}

void Human::activateAbility() {
    if (currentCooldown == 0) {
        currentCooldown = -cooldown;
        emitMessage("aktywuje calopalenie");
    }
}

int Human::burn() {
    int numOfPoints = 4;
    int numOfBurned = 0;
    Point pointsToBurn[] = {Point(0, -1), Point(0, 1), Point(-1, 0),
                            Point(1, 0)};
    for (int i = 0; i < numOfPoints; i++) {
        Organism *toBurn = world->getOrganismAt(pointsToBurn[i] + pos);
        if (toBurn != NULL) {
            toBurn->die();
            numOfBurned++;
        }
    }
    return numOfBurned;
}

int Human::getCooldown() {
    return currentCooldown;
}

void Human::setCooldown(int c) {
    currentCooldown = c;
}
