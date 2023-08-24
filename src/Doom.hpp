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
	bool attack;
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
	void WalkRight(),
		WalkLeft(),
		Iddle();
};

class Npcs : public Entity{
public:
bool fireanimation;
	shared_ptr<sf::Sprite> npc;
	sf::Texture npcstexture;
	sf::Texture textureVilionRight[9];
	sf::Texture textureVilionstop[4];
	sf::Texture downVilion;
	int timer = 0;
	int distance = 0;
public:
	Npcs(int referent);
	~Npcs();
	void RightWalk(),
		LeftWalk();
	void animation();
	void Iddle();
	void attack1();
	void attack3();
	void testAproxim(Hero * heroobj);
	void pop_attack();
	void npc1();
	void npc2();
	void npc3();
	void colison(Hero * heroobj, bool * GameOver);
};

class DoomAdventure {
	shared_ptr<sf::RenderWindow> window; //ponteiro inteligente para a janela
	shared_ptr<sf::Sprite> background;
	sf::Texture bgtexutre;
	Hero *heroobj = new Hero();
	bool GameOver;
	Npcs *npc1 = new Npcs(1);
	Npcs *npc3 = new Npcs(3);

protected:
	void events();
	void draw();
	void game();

public:
	DoomAdventure();
	~DoomAdventure();
	void run();
};