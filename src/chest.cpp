#include "chest.h"

Chest::Chest(int x, int y) {
    texture.loadFromFile("assets/image_apple.png");
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    this->size = 64;
    this->inPlace = false;
}

void Chest::draw(RenderTarget& target, RenderStates state) const {target.draw(this->sprite, state); }



void Chest::move(char direction){
    switch(direction){
        case 'l':
            this->sprite.move(-1 * getSize(),0);
            break;
        case 'r':
            this->sprite.move(getSize(),0);
            break;
        case 'u':
            this->sprite.move(0,-1 * getSize());
            break;
        case 'd':
            this->sprite.move(0,getSize());
            break;
        default:
            break;
    }
}

int Chest::getSize() {return this->size; }

Vector2f Chest::getPosition(){return this->sprite.getPosition();}

void Chest::setTexture(string path){
    texture.loadFromFile(path);
    sprite.setTexture(texture);
}

bool Chest::getInPlace(){ return this->inPlace; }

void Chest::setInPlace(bool state){ this->inPlace = state; }