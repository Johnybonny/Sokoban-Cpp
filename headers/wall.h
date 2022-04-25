#ifndef GAME_WALL_H
#define GAME_WALL_H

#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;
using namespace std;

class Wall: public Drawable {
private:
    Sprite sprite;
    Texture texture;
    int size;
    void draw(RenderTarget& target, RenderStates state) const override;
public:
    Wall(int x, int y);

    ~Wall() = default;

    int getSize();

    Vector2f getPosition();

    void setTexture(string path);

};


#endif //GAME_WALL_H
