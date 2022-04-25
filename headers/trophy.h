#ifndef GAME_TROPHY_H
#define GAME_TROPHY_H
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Trophy: public Drawable{
private:
    Sprite sprite;
    Texture texture;
    int size;
    void draw(RenderTarget& target, RenderStates state) const override;


public:
    Trophy(int x, int y);

    ~Trophy() = default;
    void setTexture(string path);


};
#endif //GAME_TROPHY_H
