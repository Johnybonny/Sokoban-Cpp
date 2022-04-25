#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <vector>

#include <SFML/Graphics.hpp>
#include "character.h"
#include "wall.h"
#include "chest.h"
#include "target.h"
#include "trophy.h"
using namespace std;
using namespace sf;

class Game {
private:
    Character character;
    vector<Wall> walls;
    vector<Chest> chests;
    vector<Target> targets;
    vector<Trophy> troph;
    bool exit;
    unsigned int height;
    unsigned int width;
    unsigned int fps;
    RenderWindow window;

public:
    Game();

    ~Game() = default;

    void menu();
    void reset();
    void level(int number);
    void how();
    void ending();
    void displayAll();

    void loadLevel(int number);

    void collision(char direction, bool &ifwin);

};


#endif //GAME_GAME_H