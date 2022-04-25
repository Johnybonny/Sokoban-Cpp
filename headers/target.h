#ifndef GAME_TARGET_H
#define GAME_TARGET_H

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Target: public Drawable{
private:
    Sprite sprite;
    Texture texture;
    int size;
    void draw(RenderTarget& target, RenderStates state) const override;
    bool full;

public:
    Target(int x, int y);

    ~Target() = default;

    int getSize();

    void setTexture(string path);

    Vector2f getPosition();

    bool getFull();

    void setFull(bool state);
};


#endif //GAME_TARGET_H
