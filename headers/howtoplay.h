#ifndef GAME_HOW_TO_PLAY_H
#define GAME_HOW_TO_PLAY_H

#include "SFML/Graphics.hpp"
#include <iostream>
using namespace sf;
using namespace std;


class Howtoplay{
private:
    Font font;
    Text text;
    RectangleShape square;

public:
    Howtoplay(float width, float height);
    ~Howtoplay() = default;
    void draw(RenderWindow &window);
};


#endif
