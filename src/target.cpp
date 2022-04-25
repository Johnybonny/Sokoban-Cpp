#include "target.h"

Target::Target(int x, int y) {
    texture.loadFromFile("assets/image_basket.png");
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    this->size = 64;
    this->full = false;
}

void Target::draw(RenderTarget& target, RenderStates state) const {target.draw(this->sprite, state); }

int Target::getSize() {return this->size; }

Vector2f Target::getPosition(){return this->sprite.getPosition();}

void Target::setTexture(string path) {
    texture.loadFromFile(path);
    sprite.setTexture(texture);
}

bool Target::getFull(){ return this->full; }

void Target::setFull(bool state){ this->full = state; }