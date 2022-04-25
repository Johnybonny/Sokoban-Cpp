#ifndef GAME_END_H
#define GAME_END_H
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace sf;
using namespace std;


class End{
private:
    Font font;
    Text text;
    RectangleShape square;
    Sprite sprite;
    Texture texture;
    int size;

public:
    End(float width, float height);
    ~End() = default;
    void draw(RenderWindow &window);

};

#endif //GAME_END_H
