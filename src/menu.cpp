#include "menu.h"


Menu::Menu(float width, float height) {
    if (!font.loadFromFile("fonts/Barrio-Regular.ttf"))
    {
        //error
    }

    text[0].setFont(font);
    text[0].setColor(sf::Color(45,142,21));
    text[0].setString("Play");
    text[0].setPosition(sf::Vector2f((width / 2)-30, height / (MAX_NUMBER_OF_ITEMS + 1) * 1 -25) );
    button[0].setPosition((width / 2)-150, height / (MAX_NUMBER_OF_ITEMS + 1) * 1-50);
    button[0].setSize(sf::Vector2f(300, 100));
    button[0].setFillColor(sf::Color(71,233,114));
    button[0].setOutlineThickness(10);
    button[0].setOutlineColor(sf::Color(71,233,114));

    text[1].setFont(font);
    text[1].setColor(sf::Color(71,233,114));
    text[1].setString("How To Play");
    text[1].setPosition(sf::Vector2f((width / 2)-70, height / (MAX_NUMBER_OF_ITEMS + 1) * 2-25));
    button[1].setPosition((width / 2)-150, height / (MAX_NUMBER_OF_ITEMS + 1) * 2-50);
    button[1].setSize(sf::Vector2f(300, 100));
    button[1].setFillColor(sf::Color(45,142,21));
    button[1].setOutlineThickness(10);
    button[1].setOutlineColor(sf::Color(71,233,114));

    text[2].setFont(font);
    text[2].setColor(sf::Color(71,233,114));
    text[2].setString("Exit");
    text[2].setPosition(sf::Vector2f((width / 2)-30, height / (MAX_NUMBER_OF_ITEMS + 1) * 3-25));
    button[2].setPosition((width / 2)-150, height / (MAX_NUMBER_OF_ITEMS + 1) * 3-50);
    button[2].setSize(sf::Vector2f(300, 100));
    button[2].setFillColor(sf::Color(45,142,21));
    button[2].setOutlineThickness(10);
    button[2].setOutlineColor(sf::Color(71,233,114));
    selectedItemIndex = 0;
}


void Menu::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(button[i]);
        window.draw(text[i]);
    }
}

void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        text[selectedItemIndex].setColor(sf::Color(71,233,114));
        button[selectedItemIndex].setFillColor(sf::Color(45,142,21));
        selectedItemIndex--;
        text[selectedItemIndex].setColor(sf::Color(45,142,21));
        button[selectedItemIndex].setFillColor(sf::Color(71,233,114));
    }
    else{
        text[selectedItemIndex].setColor(sf::Color(71,233,114));
        button[selectedItemIndex].setFillColor(sf::Color(45,142,21));
        selectedItemIndex=2;
        text[selectedItemIndex].setColor(sf::Color(45,142,21));
        button[selectedItemIndex].setFillColor(sf::Color(71,233,114));
    }
}

void Menu::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        text[selectedItemIndex].setColor(sf::Color(71,233,114));
        button[selectedItemIndex].setFillColor(sf::Color(45,142,21));
        selectedItemIndex++;
        text[selectedItemIndex].setColor(sf::Color(45,142,21));
        button[selectedItemIndex].setFillColor(sf::Color(71,233,114));
    }
    else
    {
        text[selectedItemIndex].setColor(sf::Color(71,233,114));
        button[selectedItemIndex].setFillColor(sf::Color(45,142,21));
        selectedItemIndex=0;
        text[selectedItemIndex].setColor(sf::Color(45,142,21));
        button[selectedItemIndex].setFillColor(sf::Color(71,233,114));
    }
}
