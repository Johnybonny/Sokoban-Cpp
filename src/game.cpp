#include <iostream>
#include <fstream>
#include "menu.h"
#include "game.h"
#include "howtoplay.h"
#include "end.h"
#include "trophy.h"

Game::Game():
        window(sf::VideoMode{ 840, 640 }, "Sokoban: Age of Snakes", sf::Style::Close | sf::Style::Titlebar),
        character(64, 64){
    window.setFramerateLimit(60);
    exit = false;
}


void Game::menu(){
    Menu menu(840, 640);

    Event event;
    int choice;
    bool if_menu = true;
    window.clear(Color{ 45, 142, 21, 1});
    while(if_menu){
        if (window.pollEvent(event)) {
            switch (event.type) {
                case Event::KeyReleased:
                    switch (event.key.code) {
                        case Keyboard::W:
                            menu.MoveUp();
                            break;

                        case Keyboard::S:
                            menu.MoveDown();
                            break;

                        case Keyboard::Space:
                            switch (menu.GetPressedItem()) {
                                case 0:
                                    if_menu=false;
                                    choice = 1;
                                    break;
                                case 1:
                                    if_menu=false;
                                    choice = 2;
                                    break;
                                case 2:
                                    window.close();
                                    break;
                            }
                            break;
                    }
                    break;
                case Event::Closed:
                    window.close();
                    break;

            }
        }

        window.clear(Color{ 45, 142, 21, 1 });
        menu.draw(window);
        window.display();
    }

    switch(choice){
        case 1:
            level(1);
            break;
        case 2:
            how();
            break;
    }
}


void Game::how(){
    window.clear(Color{ 45, 142, 21, 1 });
    Howtoplay howtoplay(840,640);
    bool if_how = true;
    Event event;
    while (if_how) {
        if (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                break;
            } else if (event.type == Event::KeyPressed) {
                switch (event.key.code) {
                    case Keyboard::Escape:
                        if_how = false;
                        menu();
                        break;
                }
            }
        }
        window.clear(Color{ 45, 142, 21, 1 });
        howtoplay.draw(window);
        window.display();
    }
}


void Game::ending(){
    window.clear(Color{ 45, 142, 21, 1 });
    End end(840,640);
    bool if_end = true;
    Event event;
    while (if_end) {
        if (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                break;
            } else if (event.type == Event::KeyPressed) {
                switch (event.key.code) {
                    case Keyboard::Escape:
                        reset();
                        if_end = false;
                        menu();
                        break;
                }
            }
        }

        window.clear(Color{ 45, 142, 21, 1 });
        end.draw(window);
        troph.push_back(Trophy(220,100));
        for(auto i = troph.begin(); i != troph.end(); ++i){
            i->setTexture("assets/image_trophy.png");
            window.draw(*i);
        }
        window.display();
    }
}


void Game::level(int number) {
    loadLevel(number);
    int xCurrent, yCurrent;
    switch(number){
        case 1:
            xCurrent = 384;
            yCurrent = 192;
            break;
        case 2:
            xCurrent = 320;
            yCurrent = 384;
            break;
        case 3:
            xCurrent = 192;
            yCurrent = 192;
            break;
    }
    character.setPosition(xCurrent, yCurrent);
    bool if_game = true;
    bool if_win=false;
    char direction;
    Event event;
    while (if_game) {
        if (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                break;
            } else if (event.type == Event::KeyPressed) {
                switch (event.key.code) {
                    case Keyboard::A:
                        direction = 'l';
                        break;
                    case Keyboard::D:
                        direction = 'r';
                        break;
                    case Keyboard::W:
                        direction = 'u';
                        break;
                    case Keyboard::S:
                        direction = 'd';
                        break;
                    case Keyboard::Escape:
                        reset();
                        character.setPosition(64,64);
                        menu();
                        break;
                    case Keyboard::R:
                        reset();
                        character.setPosition(xCurrent,yCurrent);
                        loadLevel(number);
                        break;

                }
                character.move(direction);
                collision(direction, if_win);
            }
        }
        if(if_win)
        {
            if(number == 1){
                reset();
                if_win=false;
                level(2);
            }
            else{
                if(number== 2){
                    reset();
                    if_win=false;
                    level(3);
                }
                else{
                    if_win=false;
                    character.setPosition(64,64);
                    ending();
                }
            }
        }
        displayAll();
    }
}


void Game::reset(){
    walls.clear();
    targets.clear();
    chests.clear();
}


void Game::displayAll(){
    window.clear(Color{ 45, 142, 21, 1 });

    for(auto i = walls.begin(); i != walls.end(); ++i){
        i->setTexture("assets/image_tree.png");
        window.draw(*i);
    }

    bool imageSet;
    for(auto i = targets.begin(); i != targets.end(); ++i){
        imageSet = false;
        for(auto j = chests.begin(); j != chests.end(); ++j){
            if(i->getPosition() == j->getPosition()){
                i->setTexture("assets/image_appleinbasket.png");
                imageSet = true;
            }
        }
        if(!imageSet){i->setTexture("assets/image_basket.png");}
        window.draw(*i);
    }
    for(auto i = chests.begin(); i != chests.end(); ++i){
        if(!i->getInPlace()){
            i->setTexture("assets/image_apple.png");
            window.draw(*i);
        }
    }



    window.draw(character);
    window.display();
}


void Game::loadLevel(int num){
    int tmp_x, tmp_y;
    string chestsName, wallsName, targetsName;
    switch(num){
        case 1:
            chestsName = "levels/level1_chests.txt";
            wallsName = "levels/level1_walls.txt";
            targetsName = "levels/level1_targets.txt";
            break;
        case 2:
            chestsName = "levels/level2_chests.txt";
            wallsName = "levels/level2_walls.txt";
            targetsName = "levels/level2_targets.txt";
            break;
        case 3:
            chestsName = "levels/level3_chests.txt";
            wallsName = "levels/level3_walls.txt";
            targetsName = "levels/level3_targets.txt";
            break;
    }
    ifstream file1(chestsName);

    while (file1>>tmp_x){
        file1>>tmp_y;
        chests.push_back(Chest(tmp_x, tmp_y));

    }
    file1.close();
    ifstream file2(wallsName);
    while (file2>>tmp_x){
        file2>>tmp_y;
        walls.push_back(Wall(tmp_x, tmp_y));
    }
    file2.close();
    ifstream file3(targetsName);
    while (file3>>tmp_x){
        file3>>tmp_y;
        targets.push_back(Target(tmp_x, tmp_y));
    }
    file3.close();
}


void Game::collision(char direction, bool &if_win){
    char opposite;
    if(direction == 'd') {opposite = 'u';}
    if(direction == 'u') {opposite = 'd';}
    if(direction == 'l') {opposite = 'r';}
    if(direction == 'r') {opposite = 'l';}

    for(auto i = walls.begin(); i != walls.end(); ++i){
        if(i->getPosition() == character.getPosition()){
            character.move(opposite);
        }
    }

    for(auto i = chests.begin(); i != chests.end(); ++i){
        if(i->getPosition() == character.getPosition()){
            i->move(direction);
            for(auto j = chests.begin(); j != chests.end(); ++j){
                if((i != j)&&(i->getPosition() == j->getPosition())){
                    i->move(opposite);
                    character.move(opposite);
                }
            }
            for(auto j = walls.begin(); j != walls.end(); ++j){
                if(i->getPosition() == j->getPosition()){
                    i->move(opposite);
                    character.move(opposite);
                }
            }
        }
    }

    int count_apples_in_buckets=0;
    bool change_level=false;
    for(auto i = chests.begin(); i != chests.end(); ++i){
        bool placed = false;
        for(auto j = targets.begin(); j != targets.end(); ++j){
            if(i->getPosition() == j->getPosition()){
                placed = true;
                j->setFull(true);
                i->setInPlace(true);
                count_apples_in_buckets=count_apples_in_buckets+1;
                if(count_apples_in_buckets==targets.size())
                {
                    change_level=true;
                    count_apples_in_buckets=0;
                }
            }
        }
        if(!placed){
            i->setInPlace(false);
        }
    }
    if(change_level)
    {
        change_level=false;
        if_win=true;
    }
}


