#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H

#include <SFML/Graphics.hpp>
using namespace sf;

using namespace std;

class Character: public Drawable{
private:
    Sprite sprite;
    Texture texture;
    int size;
    void draw(RenderTarget& target, RenderStates state) const override;
public:
    Character(int x, int y);

    Character();

    ~Character()=default;

    int getSize();

    virtual void update();

    void move(char direction);
    void setPosition(int x, int y);
    Vector2f getPosition();


};


#endif //GAME_CHARACTER_H
