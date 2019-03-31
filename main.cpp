#include <string>
#include <chrono>
#include <thread>

#include <iostream>

#include "Utilities.h"
#include "World.h"

#include "Organisms/All.h"

int main() {
    int ch = 0;

    int width, height;
    cout << "Y: ";
    cin >> height;
    cout << "X: ";
    cin >> width;

    World *world = new World(height, width);
    Human* human = world->generateOrganisms();

    world->addMessage("Rozpoczyna sie tura 1");
    world->draw();
    while (ch != KEY_ESC) {
        ch = 0;
        while (ch != KEY_ENTER && ch != KEY_ESC) {
            ch = Screen::get();
            if (world->isHumanAlive()) {
                switch (ch) {
                    case KEY_LEFT:
                        human->setDirection(1);
                        break;
                    case KEY_UP:
                        human->setDirection(2);
                        break;
                    case KEY_RIGHT:
                        human->setDirection(3);
                        break;
                    case KEY_DOWN:
                        human->setDirection(4);
                        break;
                    case 'f':
                        human->activateAbility();
                        break;
                    default:
                        break;
                }
            }
            if (ch == 's') {
                world->saveState();
            } else if (ch == 'l') {
                world->loadState();
            }
        }
        world->makeTurn();
        world->draw();
//        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    Screen::implode();
    return 0;
}