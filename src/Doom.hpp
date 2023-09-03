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

class Bullet
{
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

class PowerUp{
	int frame;
	int frameAnimation;
	sf::Texture Textures[6];
	sf::Texture Texture;
	int refernt= 0;
	bool verificed = false;

public:
	shared_ptr<sf::Sprite> Power;
	void animation();
	void Update(shared_ptr<sf::Sprite> spr_hero,int * live,bool * Restart, bool * Activ);
	PowerUp(int x, int y,int referent);
	~PowerUp();
};

class Entity
{
public:
	int framestop = 0,
		frameOrientationX = 1,
		referent,
		countKill = 0;
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
	int LeftCountColison = 0;
	int RightCountColison = 0;
	int UpCountColison = 0;
	int DownCountColison = 0;
	int SpikesColision = 0;
};

class Hero : public Entity
{
private:
	int count;
	sf::SoundBuffer Heroatack;
	sf::Texture textureheroRight[9];
	sf::Texture textureherostop[4];
	sf::Texture down;
	sf::Texture fall;
	sf::Texture herotexture[3];
	sf::Clock clock;
	sf::Time timepassado;
	int timer;
public:
	bool Activ = false;
	bool restartClock= false;
	int ControlSkip;
	bool jumping;
	int restjump;
	int shotstimer = 0;
	int quantbullet;
	shared_ptr<sf::Sprite> hero;

public:
	Hero();
	void colision(shared_ptr<sf::Sprite> atingido, int *live);
	void animation();
	void attack();
	void CheckVictory(int liveVilon, bool *GameVictory, int level);
	void pop_attack();
	void SuperHero();
};

class Villain : public Entity
{
private:
	// variavel de id dos viloes
	int timer = 0;
	bool perseg = false;
	int distance = 0;
	bool fireanimation;
	sf::Texture textureVilionRight[9];
	sf::Texture textureVilionstop[4];
	sf::Texture downVilion;
	sf::SoundBuffer Villainatack;

public:
	shared_ptr<sf::Sprite> Vilion;
	bool visible = true;

private:
void persegui(Hero *heroobj);
public:
	Villain(int referent);
	~Villain();
	void animation();
	void attacks();
	void attack1();
	void pop_attack();
	void Villan1();
	void testAproxim(Hero *heroobj);
	void WalkRight(),
		WalkLeft(),
		Idle();
};

class Npcs : public Entity
{
private:
	sf::SoundBuffer Npcatack;
	sf::SoundBuffer NpcDead;
	bool fireanimation;
	sf::Texture npcstexture;
	sf::Texture textureIdle[4];
	sf::Texture downVilion;
	int timer = 0;
	int distance = 0;

public:
	bool orientation;
	shared_ptr<sf::Sprite> npc;

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
	void testAproxim(Hero *heroobj);
	void pop_attack();
	void npc1();
	void npc2();
	void npc3(); // d
	void npc4();
	void Death();
	void colision(Hero *heroobj, bool *GameOver, int level);
};

class DoomAdventure
{

	shared_ptr<sf::RenderWindow> window; // ponteiro inteligente para a janela
	shared_ptr<sf::Sprite> background;
	sf::Texture bgtexutre;
	Hero *heroobj = new Hero();
	bool GameOver;

	Npcs *npcA1 = new Npcs(1);
	Npcs *npcA2 = new Npcs(1);
	Npcs *npcB1 = new Npcs(2);
	Npcs *npcB2 = new Npcs(2);
	Npcs *npcC1 = new Npcs(4);
	Npcs *npcC2 = new Npcs(4);
	Npcs *npcC3 = new Npcs(4);
	Npcs *npcD1 = new Npcs(3);
	Npcs *npcD2 = new Npcs(3);
	Villain *villain = new Villain(1);
	bool KeyIntro;
	bool KeyMenu;
	bool KeyGame;
	sf::Texture mYSt;
	sf::Texture mYSt2;
	sf::Texture mYSt3;
	sf::RectangleShape checkpoint;
	sf::Texture name;
	sf::Texture name2;
	sf::Texture name3;
	sf::Texture bulletmenu;
	sf::Texture logotexture;
	sf::Texture texturePersona[4];
	sf::Texture transitionTexture;
	sf::Music rain;
	sf::Music musicGame;
	bool chekedaudio = false;
	sf::Sprite n1;
	sf::Sprite n2;
	sf::Sprite n3;
	sf::Sprite r1;
	sf::Sprite r2;
	sf::Sprite r3;
	sf::Sprite bulletmenuSprite;
	sf::Sprite Persona;
	sf::Sprite logo;
	sf::Sprite transition;
	bool GameWin;
	int time;
	int frame = 0;
	int Animation = 1;
	sf::Clock clock;
	sf::Time timepassado;
	bool personagenslibery = false;
	sf::View *view;
	tmx::Map map;
	shared_ptr<tmx::Map> map_2;
	shared_ptr<tmx::Map> map_3;
	bool KeyDown;
	bool KeyUp;
	bool skiplevel;
	bool level1;
	bool level2;
	bool level3;
	MapLayer *layerDraw;
	MapLayer *layerDown;
	MapLayer *layerLeft;
	MapLayer *layerRight;
	MapLayer *layerUp;

	MapLayer *layerDraw_2;
	MapLayer *layerDown_2;
	MapLayer *layerLeft_2;
	MapLayer *layerRight_2;
	MapLayer *layerUp_2;
	MapLayer *layerSpikes;

	MapLayer *layerDraw_3;
	MapLayer *layerDown_3;
	MapLayer *layerLeft_3;
	MapLayer *layerRight_3;
	MapLayer *layerUp_3;
	sf::Font font;
	int i = 0;
	float gravity;
	sf::Text textGm;
	sf::Text returnKey;
	int level;
	bool Finalgame = false;
	vector<PowerUp> Plusbullet;
protected:
	void Introduction(shared_ptr<sf::RenderWindow> window);
	void events();
	void draw();
	void drawGame();
	void LastMatch();
	void game();
	void Menu();
	void Restart();
	void GameOverX();
	void update();
	void Interface();
	void map1();
	void map2();
	void map3();
	void gravityAndColision();
	void GameWinner();

public:
	DoomAdventure();
	~DoomAdventure();
	void run();
};
