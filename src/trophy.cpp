#include "trophy.h"

Trophy::Trophy(int x, int y) {
    texture.loadFromFile("assets/image_trophy.png");
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    this->size = 64;
}

void Trophy::setTexture(string path) {
    texture.loadFromFile(path);
    sprite.setTexture(texture);
}

void Trophy::draw(RenderTarget& target, RenderStates state) const {target.draw(this->sprite, state); }
