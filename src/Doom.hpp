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
	int framestop = 0,
	frameOrientationX = 1, 
	referent;
	int frame = 0;
	int countattacks;
	int vel;
	shared_ptr<sf::Sprite> entitysprite;
	vector<Bullet> shots;

protected: 
	void animation();
};

class Hero: public Entity {
public:
	int shotstimer = 0;
	sf::Texture textureheroRight[9];
	sf::Texture textureherostop[4];
	sf::Texture down;
	shared_ptr<sf::Sprite> hero;
	sf::Texture herotexture[3];

public:
	Hero();
	void animation();
	void attack();
	void pop_attack();

};

class Villain: public Entity {
public:
	//variavel de id dos viloes
	int timer = 0;
	int distance = 0;
	bool fireanimation;
	bool attack;
	sf::Texture textureVilionRight[9];
	sf::Texture textureVilionstop[4];
	sf::Texture downVilion;
	shared_ptr<sf::Sprite> Vilion;


public:
	Villain(int referent);
	~Villain();
	void animation();
	void attacks();
	void attack1();
	void pop_attack();
	void Villan1();
	void testAproxim(Hero * heroobj);
	void transition1(),
		transition2(),
		transition3();
};

class Npcs : public Entity{
public:
	shared_ptr<sf::Sprite> npc;
	sf::Texture npcstexture;

public:
	Npcs(int referent);
	~Npcs();
	void animation();
	void npc1();
};

class DoomAdventure {
	shared_ptr<sf::RenderWindow> window; //ponteiro inteligente para a janela
	shared_ptr<sf::Sprite> background;
	sf::Texture bgtexutre;
	Hero *heroobj = new Hero();
	Villain *villian = new Villain(1);
	Npcs *npc1 = new Npcs(1);

protected:
	void events();
	void draw();
	void game();

public:
	DoomAdventure();
	~DoomAdventure();
	void run();
};