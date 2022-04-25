#ifndef GAME_CHEST_H
#define GAME_CHEST_H

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Chest: public Drawable{
private:
    Sprite sprite;
    Texture texture;
    int size;
    void draw(RenderTarget& target, RenderStates state) const override;
    bool inPlace;

public:
    Chest(int x, int y);

    ~Chest() = default;

    int getSize();

    void move(char direction);

    void setTexture(string path);

    Vector2f getPosition();

    bool getInPlace();

    void setInPlace(bool state);
};


#endif //GAME_CHEST_H
