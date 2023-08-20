#pragma once

#include <iostream>
#include <memory>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <vector>
#include <sstream>
using namespace std;

class Bullet {
private:
	int frame;
public:
	shared_ptr<sf::Sprite> attacksprite;
	shared_ptr<sf::Texture> bullettexture[4];
	bool orientation;
public:
	void Orientation(int vel);
	void animation();
	Bullet();
	~Bullet();

};


class Entity {
public:
	int frame = 0;
	int countattacks;
	int vel;
	vector<Bullet> shots;
};

class Hero: public Entity {
public:
	int framestophero = 0,
	frameLeftAndRight = 0,
	shotstimer = 0;

	sf::Texture textureheroRight[9];
	sf::Texture textureherostop[4];
	sf::Texture down;
	shared_ptr<sf::Sprite> hero;
	sf::Texture herotexture[3];

public:
	Hero();
	void animation();
	void attk();
	void pop_attack();

};

class Villain: public Entity {
public:
	int referent = 0;
	int framesStopVilion = 1,
	frameLeftAndRight = 1,
	timer = 0;
	int distance = 0;
	bool fireanimation;
	bool attack;
	sf::Texture textureVilionRight[9];
	sf::Texture textureVilionstop[4];
	sf::Texture downVilion;
	shared_ptr<sf::Sprite> Vilion;
	sf::Texture herotexture[3];

public:
	void animation();
	void attks();
	void attk1();
	void pop_attack();
	void Villan1();
	void transtion1(),
		transtion2(),
		transtion3();
	void testAproxim(Hero * heroobj);
	Villain(int referent);
	~Villain();
};

class DoomAdventure {
protected:
	shared_ptr<sf::RenderWindow> window; //ponteiro inteligente para a janela
	shared_ptr<sf::Sprite> background;
	sf::Texture bgtexutre;
	Hero *heroobj;
	Villain * villian;
protected:
	void events();
	void draw();
	void game();

public:
	DoomAdventure();
	void run();
};



