#include "character.h"
#include "game.h"

Character::Character(int x, int y) {
    texture.loadFromFile("assets/image_snake.png");
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    this->size = 64;
}


void Character::draw(RenderTarget& target, RenderStates state) const {target.draw(this->sprite, state); }

void Character::update(){
    if(Keyboard::isKeyPressed(Keyboard::Key::Left)){
        move('l');
    }else if(Keyboard::isKeyPressed(Keyboard::Key::Right)){
        move('r');
    }else if(Keyboard::isKeyPressed(Keyboard::Key::Up)){
        move('u');
    }else if(Keyboard::isKeyPressed(Keyboard::Key::Down)){
        move('d');
    }

}

void Character::move(char direction){
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

int Character::getSize() {return this->size; }
void Character::setPosition(int x, int y)
{
    sprite.setPosition(x,y);
}
Vector2f Character::getPosition(){return this->sprite.getPosition();}