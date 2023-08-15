#pragma once

#include <iostream>
#include <memory>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class Npc{
public:
	int frame = 0;
};

class Hero : public Npc{
public:
	int framestophero =0,
	frameLeftAndRight = 0;
	sf::Texture textureheroRight[9];
	sf::Texture textureherostop[4];
	sf::Texture down;
    shared_ptr<sf::Sprite> hero;
    sf::Texture herotexture[3]; //vetor inteligente para a textura do heroi

public:
    void drawHero();
    Hero();
    void animation();
};

class DoomAdventure {
protected:
    shared_ptr<sf::RenderWindow> window; //ponteiro inteligente para a janela
    shared_ptr<sf::Sprite> background;
    sf::Texture bgtexutre;
    Hero * hero = new Hero();

protected:
    void events();
    void draw();
    void game();

public:
    DoomAdventure();
    void run();
};

class Villain : public Npc{

    vector<sf::Texture> villaintexture;

public:
    Villain();
    ~Villain();
};

