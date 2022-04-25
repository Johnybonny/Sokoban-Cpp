#include "wall.h"


Wall::Wall(int x, int y) {
    texture.loadFromFile("assets/image_tree.png");
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    this->size = 64;
}

void Wall::draw(RenderTarget& target, RenderStates state) const{ target.draw(this->sprite, state); }

int Wall::getSize() {return this->size; }

Vector2f Wall::getPosition(){return this->sprite.getPosition(); }

void Wall::setTexture(string path){
    texture.loadFromFile(path);
    sprite.setTexture(texture);
}