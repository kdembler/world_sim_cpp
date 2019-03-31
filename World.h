#ifndef SYMULACJA_CPP_WORLD_H
#define SYMULACJA_CPP_WORLD_H

#include <string>
#include <vector>

#include "Utilities.h"
#include "Screen.h"

class Human;

class Organism;

using namespace std;

class World {
public:

    friend Point Utilities::findFree(World *, Point);

    World(int height, int width);

    ~World();

    void putTranslated(Point p, string s);

    void putTranslated(Point p, char c);

    void makeTurn();

    void draw();

    int getWidth();

    int getHeight();

    bool addOrganism(Organism *o);

    void addHuman(Point);

    void addHuman(Point, int);

    bool isHumanAlive();

    Human *getHuman();

    void removeOrganism(Organism *o);

    void addMessage(string);

    void saveState();

    void loadState();

    Human* generateOrganisms();

    Organism *getOrganismAt(Point);

    void setOrganismAt(Organism *, Point);

private:
    int round;
    int width, height;

    Human *human;

    bool humanAlive = false;

    void init();

    void implode();

    void drawBorders();

    void drawInfo();

    void drawMessages();

    void drawBoard();

    void drawMessageBox();

    void clearBoard();

    void clearMessages();

    Point translatePoint(Point p);

    Organism ***board;

    vector<Organism *> organisms;

    vector<string> messages;
};


#endif
