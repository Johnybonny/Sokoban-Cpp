#ifndef GAME_MENU_H
#define GAME_MENU_H

#include "SFML/Graphics.hpp"
#include <iostream>
using namespace sf;
using namespace std;

#define MAX_NUMBER_OF_ITEMS 3

class Menu{
private:
    int selectedItemIndex;
    Font font;
    Text text[MAX_NUMBER_OF_ITEMS];
    RectangleShape button[MAX_NUMBER_OF_ITEMS];
public:
    Menu(float width, float height);
    ~Menu() = default;
    void draw(RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }
    void load(float width, float height);
};


#endif //GAME_MENU_H
