#pragma once

#include <iostream>
#include <memory>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class Entity {
public:
	int frame = 0;
    int countattacks;
    shared_ptr<sf::Sprite> attacksprite;
    bool orientation;

protected:
    void attack();
    void animation();
};

class Hero : public Entity{
public:
	int framestophero =0,
	frameLeftAndRight = 0;
	sf::Texture textureheroRight[9];
	sf::Texture textureherostop[4];
	sf::Texture down;
    shared_ptr<sf::Sprite> hero;
    sf::Texture herotexture[3];
    sf::Texture bullettexture;
    

public:
    Hero();
    void animation();
    void attk();
    
};

class DoomAdventure {
protected:
    shared_ptr<sf::RenderWindow> window; //ponteiro inteligente para a janela
    shared_ptr<sf::Sprite> background;
    sf::Texture bgtexutre;
    Hero *heroobj = new Hero();
   // Bullet *bulletobj = new Bullet();

protected:
    void events();
    void draw();
    void game();

public:
    DoomAdventure();
    void run();
};

class Villain : public Entity{

    vector<sf::Texture> villaintexture;

public:
    Villain();
    ~Villain();
};




