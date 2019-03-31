#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Utilities.h"
#include "World.h"
#include "Screen.h"
#include "Organisms/All.h"

using namespace std;

World::World(int width, int height) {
    Screen::init();
    Utilities::init();
    this->width = width;
    this->height = height;
    round = 2;
    init();
}

World::~World() {
    for (Organism *o : organisms) {
        delete o;
    }
}

Point World::translatePoint(Point p) {
    return Point(p.y + 1, p.x + 1);
}

void World::makeTurn() {
    addMessage("Rozpoczyna sie tura " + to_string(round));
    for (int i = 0; i < organisms.size(); i++) {
        organisms[i]->action();
    }
    round++;
}

void World::draw() {
    clearBoard();
    drawBoard();
    clearMessages();
    drawMessages();
    Screen::update();
}

void World::putTranslated(Point p, char c) {
    Screen::put(translatePoint(p), string(1, c));
}

void World::putTranslated(Point p, string s) {
    Screen::put(translatePoint(p), s);
}

bool World::addOrganism(Organism *o) {
    Point pos = o->getPos();
    if (board[pos.y][pos.x] != NULL)
        return false;
    int i = 0;
    while (i < organisms.size() && organisms[i]->getInitiative() > o->getInitiative()) i++;
    while (i < organisms.size() && organisms[i]->getAge() > o->getAge()) i++;
    organisms.insert(organisms.begin() + i, o);
    board[pos.y][pos.x] = o;
    return true;
}

void World::drawBorders() {
    int i = 0;
    for (; i < height + 2; i++) {
        Screen::put(Point(i, 0), string(1, '|'));
        Screen::put(Point(i, width + 1), string(1, '|'));
    }
    for (i = 1; i <= width; i++) {
        Screen::put(Point(0, i), string(1, '-'));
        Screen::put(Point(height + 1, i), string(1, '-'));
    }
    Screen::put(Point(0, 7), "Plansza");
}

void World::drawInfo() {
    Screen::put(Point(1, width + 3), "Klaudiusz Dembler");
    Screen::put(Point(2, width + 3), "Indeks: 165389");
}

void World::clearBoard() {
    string empty = "";
    for (int x = 0; x < width; x++) {
        empty += " ";
    }
    for (int y = 0; y < height; y++) {
        putTranslated(Point(y, 0), empty);
    }
}

int World::getWidth() {
    return width;
}

int World::getHeight() {
    return height;
}

void World::removeOrganism(Organism *o) {
    if (dynamic_cast<Human *>(o) != nullptr) humanAlive = false;
    delete o;
    board[o->getPos().y][o->getPos().x] = NULL;
    organisms.erase(std::remove(organisms.begin(), organisms.end(), o), organisms.end());
}

void World::drawMessageBox() {
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        Screen::put(Point(y, width + 23), "|");
        Screen::put(Point(y, SCREEN_WIDTH - 1), "|");
    }

    for (int x = width + 24; x < SCREEN_WIDTH - 1; x++) {
        Screen::put(Point(0, x), "-");
        Screen::put(Point(SCREEN_HEIGHT - 1, x), "-");
    }
    Screen::put(Point(0, width + 47), "Wiadomosci");
}

void World::addMessage(string msg) {
    messages.push_back(msg);
    if (messages.size() > SCREEN_HEIGHT - 2)
        messages.erase(messages.begin());
}

Organism *World::getOrganismAt(Point p) {
    if (p.y >= 0 && p.x >= 0 && p.y < height && p.x < width)
        return board[p.y][p.x];
    return NULL;
}

void World::setOrganismAt(Organism *o, Point p) {
    if (p.y >= 0 && p.x >= 0 && p.y < height && p.x < width)
        board[p.y][p.x] = o;
}

void World::drawMessages() {
    for (int i = (int) messages.size() - 1; i >= 0; i--) {
        Screen::put(Point((int) messages.size() - i, width + 25), messages[i]);
    }
}

void World::drawBoard() {
    for (Organism *o : organisms) {
        o->draw();
    }
}

void World::clearMessages() {
    string empty = "";
    for (int x = width + 24; x < SCREEN_WIDTH - 1; x++) {
        empty += " ";
    }
    for (int y = 1; y < SCREEN_HEIGHT - 1; y++) {
        Screen::put(Point(y, width + 24), empty);
    }
}

void World::saveState() {
    ofstream file;
    file.open("state.txt");
    string sep = " ";
    file << height << sep << width << sep << round << "\n";
    for (Organism *o:organisms) {
        Human *h = dynamic_cast<Human *>(o);
        // name;pos.y;pos.x;age;strength;cooldown
        file << o->getSym() << sep << o->getPos().y << sep << o->getPos().x << sep << o->getAge() << sep
             << o->getStrength() << sep << (h != nullptr ? to_string(h->getCooldown()) : "0") << "\n";
    }
    file.close();
}

void World::loadState() {
    implode();
    ifstream file;
    file.open("state.txt");
    string line;
    bool first = true;
    humanAlive = false;
    while (getline(file, line)) {
        istringstream iss(line);
        if (first) {
            int nw, nh, nr;
            iss >> nh >> nw >> nr;
            width = nw;
            height = nh;
            round = nr;
            init();
            first = false;
        } else {
            char sym;
            int y, x, age, str, cd;
            iss >> sym >> y >> x >> age >> str >> cd;
            Point p(y, x);
            if (sym == 'H') {
                addHuman(p, age);
                human->setStrength(str);
                human->setCooldown(cd);
            } else {
                Organism *o = NULL;
                switch (sym) {
                    case 'H':

                        break;
                    case 'A':
                        o = new Antelope(this, p);
                        break;
                    case '!':
                        o = new Belladonna(this, p);
                        break;
                    case '>':
                        o = new Fox(this, p);
                        break;
                    case '=':
                        o = new Grass(this, p);
                        break;
                    case 'G':
                        o = new Guarana(this, p);
                        break;
                    case '^':
                        o = new Sheep(this, p);
                        break;
                    case '$':
                        o = new Sonchus(this, p);
                        break;
                    case '?':
                        o = new SosnowskyHogweed(this, p);
                        break;
                    case '@':
                        o = new Turtle(this, p);
                        break;
                    case '#':
                        o = new Wolf(this, p);
                        break;
                }
                o->setAge(age);
                o->setStrength(str);
                addOrganism(o);
            }
        }
    }
    file.close();
    draw();
}

void World::addHuman(Point p) {
    addHuman(p, 0);
}

void World::addHuman(Point p, int age) {
    humanAlive = true;
    human = new Human(this, p);
    human->setAge(age);
    addOrganism(human);
}

bool World::isHumanAlive() {
    return humanAlive;
}

Human *World::getHuman() {
    return human;
}

void World::init() {
    Screen::clean();

    board = new Organism **[height];
    for (int i = 0; i < height; i++) {
        board[i] = new Organism *[width];
        for (int j = 0; j < width; j++) {
            board[i][j] = NULL;
        }
    }
    drawBorders();
    drawInfo();
    drawMessageBox();
    Screen::update();
}

void World::implode() {
    organisms.clear();
    messages.clear();
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            delete board[y][x];
        }
        delete[] board[y];
    }
    delete[] board;
}

Human *World::generateOrganisms() {
    addHuman(Point(0,0));
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (y == 0 && x == 0) continue;
            if (Utilities::randRange(1, 100) < 10) {
                Organism *toSpawn;
                Point p(y, x);
                int organismType = Utilities::randRange(1, 10);
                switch (organismType) {
                    default:
                        toSpawn = new Sheep(this, p);
                        break;
                    case 1:
                        toSpawn = new Antelope(this, p);
                        break;
                    case 2:
                        toSpawn = new Belladonna(this, p);
                        break;
                    case 3:
                        toSpawn = new Fox(this, p);
                        break;
                    case 4:
                        toSpawn = new Grass(this, p);
                        break;
                    case 5:
                        toSpawn = new Guarana(this, p);
                        break;
                    case 6:
                        toSpawn = new Sheep(this, p);
                        break;
                    case 7:
                        toSpawn = new Sonchus(this, p);
                        break;
                    case 8:
                        toSpawn = new SosnowskyHogweed(this, p);
                        break;
                    case 9:
                        toSpawn = new Turtle(this, p);
                        break;
                    case 10:
                        toSpawn = new Wolf(this, p);
                        break;
                }
                addOrganism(toSpawn);
            }
        }
    }

    return human;
}
