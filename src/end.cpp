#include "end.h"


End::End(float width, float height) {
    if (!font.loadFromFile("fonts/Barrio-Regular.ttf"))
    {
        //error
    }

    text.setFont(font);
    text.setColor(sf::Color(71,233,114));
    text.setString("\n\n\n\n\n\n\n\n\n\n\n                Press ESC to go back to menu.. ");
    text.setPosition(sf::Vector2f((100), 100 ));
    square.setPosition(75, 75);
    square.setSize(sf::Vector2f(690, 490));
    square.setFillColor(sf::Color(45,142,21));
    square.setOutlineThickness(50);
    square.setOutlineColor(sf::Color(71,233,114));

}


void End::draw(sf::RenderWindow &window)
{
    window.draw(square);
    window.draw(text);
}
