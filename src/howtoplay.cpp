#include "howtoplay.h"


Howtoplay::Howtoplay(float width, float height) {
    if (!font.loadFromFile("fonts/Barrio-Regular.ttf"))
    {
        //error
    }

    text.setFont(font);
    text.setColor(sf::Color(71,233,114));
    text.setString("\nSOKOBAN: AGE OF SNAKES - HOW TO PLAY?\n\n Aim of the game:\n Unless like in original 'Snake', put all apples into\n baskets instead of eating them\n\n Movement:\n Use AWSD to move and Space to choose from menu\n You can use r to restart the level in any moment\n\n                       Press ESC to return.. ");
    text.setPosition(sf::Vector2f((100), 100 ));
    square.setPosition(75, 75);
    square.setSize(sf::Vector2f(690, 490));
    square.setFillColor(sf::Color(45,142,21));
    square.setOutlineThickness(50);
    square.setOutlineColor(sf::Color(71,233,114));

}


void Howtoplay::draw(sf::RenderWindow &window)
{

    window.draw(square);
    window.draw(text);


}