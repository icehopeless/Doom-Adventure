#pragma once

#include <iostream>
#include <memory>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <sstream>
#include "tinyxml2.h"
using namespace std;
#include <tmxlite/Map.hpp>
#include "SFMLOrthogonalLayer.hpp"

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
	bool stopFunction = false;
 	bool dead = false;
	int live;
	sf::Sound atack;
	sf::Sound deadSound;
protected: 
	void animation();

};

class Hero: public Entity {
public:
	sf::SoundBuffer Heroatack;
	int shotstimer = 0;
	sf::Texture textureheroRight[9];
	sf::Texture textureherostop[4];
	sf::Texture down;
	shared_ptr<sf::Sprite> hero;
	sf::Texture herotexture[3];

public:
	Hero();
	void colision(shared_ptr<sf::Sprite> atingido,int * live);
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
	sf::SoundBuffer Villainatack;

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
		Idle();
};

class Npcs : public Entity{
public:
	sf::SoundBuffer Npcatack;
	sf::SoundBuffer NpcDead;
bool fireanimation;
	shared_ptr<sf::Sprite> npc;
	sf::Texture npcstexture;
	sf::Texture textureIdle[4];
	sf::Texture downVilion;
	int timer = 0;
	int distance = 0;
public:
	Npcs(int referent);
	~Npcs();
	void RightWalk(),
		LeftWalk();
	void animation();
	void Idle();
	void attack1();
	void attack3();
	void attack4();
	void testAproxim(Hero * heroobj);
	void pop_attack();
	void npc1();
	void npc2();
	void npc3();
	void npc4();
	void Death();
	void colision(Hero * heroobj, bool * GameOver);
};

class DoomAdventure {

	shared_ptr<sf::RenderWindow> window; //ponteiro inteligente para a janela
	shared_ptr<sf::Sprite> background;
	sf::Texture bgtexutre;
	Hero *heroobj = new Hero();
	bool GameOver;
	Npcs *npc1 = new Npcs(1);
	Npcs *npc2 = new Npcs(2);
	Npcs *npc3 = new Npcs(3);
	Npcs *npc4 = new Npcs(4);
	Villain *villain = new Villain(1);
	bool KeyIntro;
	bool KeyMenu; 
	bool KeyGame;

	 sf::Texture mYSt;
	 sf::Texture mYSt2;
	 sf::Texture mYSt3;
	 sf::Sprite r1;
	 sf::Sprite r2;
	 sf::Sprite r3;

	 sf::Texture name;
	 sf::Texture name2;
	 sf::Texture name3;
	 sf::Music rain;
	sf::Music musicGame;
	bool chekedaudio = false;
	 sf::Sprite n1;
	 sf::Sprite n2;
	 sf::Sprite n3;
	 sf::Sprite Persona;
	 sf::Texture texturePersona[4];
	 sf::Sprite logo;
	 sf::Texture logotexture;
	 int time;
	 int frame = 0;
	 int Animation = 1;
	 sf::Clock clock;
	 sf::Time timepassado;
	 bool personagenslibery = false;
	 sf::View *view;
	 tmx::Map map;
	bool KeyDown;
	bool KeyUp;
	MapLayer * layerZero;
	sf::Font font;
	int i = 0;
	sf::Text textGm;
	sf::Text returnKey;

protected:
	void Introduction(shared_ptr<sf::RenderWindow> window);
	void events();
	void draw();
	void game();
	void Menu();
	void Restart();
	void GameOverX();
	void update();
	void Interface();

public:
	DoomAdventure();
	~DoomAdventure();
	void run();
};
