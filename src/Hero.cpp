#include "Doom.hpp"

Hero::Hero()
{
	live = 2000;
	hero = make_shared<sf::Sprite>();
	herotexture[0].loadFromFile("assets/Hero/Gunner/Gunner_Idle_1.png");
	timer = 0;
	for (int i = 0; i < 9; i++)
	{
		if (i == 0)
		{
			textureheroRight[i].loadFromFile(
				"assets/Hero/Gunner/Gunner_Rise.png");
		}
		else
		{
			stringstream ss;
			ss << "assets/Hero/Gunner/Gunner_Walk_" << i << ".png";
			textureheroRight[i].loadFromFile(ss.str());
		}
	}

	for (int i = 0; i < 4; i++)
	{
		stringstream ss;
		ss << "assets/Hero/Gunner/Gunner_Idle_" << i + 1 << ".png";
		textureherostop[i].loadFromFile(ss.str());
	}

	down.loadFromFile("assets/Hero/Gunner/Gunner_Crouch.png");
	hero->setScale(1.5f, 1.5f);
	hero->setTexture(herotexture[0]);
	Heroatack.loadFromFile("assets/attacks_sounds/lazer.wav");
	atack.setBuffer(Heroatack);
	atack.setVolume(100);
	fall.loadFromFile("assets/Hero/Gunner/Gunner_Fall.png");
}

// animando o hero

void Hero::animation()
{
	
	SuperHero();
	if (frame >= 5)
	{
		frame = 0;
		if (framestop == 3)
		{

			framestop = 0;
		}
		else
		{
			framestop++;
		}
	}

	frame++;

	if (jumping == true and restjump < 2)
	{
		hero->setTexture(fall, true);
	}

	hero->setTexture(textureherostop[framestop], true);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{

		if (frame >= 4)
		{
			frame = 0;
			if (frameOrientationX == 8)
			{
				frameOrientationX = 0;
			}
			else
			{
				frameOrientationX++;
			}
		}
		frame++;
		hero->setTexture(textureheroRight[frameOrientationX], true);
		hero->setOrigin((hero->getLocalBounds().width / 2) - 30, hero->getOrigin().y);
		hero->move(8, 0);
		hero->setScale(1.5f, 1.5f);

		if (jumping == true and restjump < 2)
		{
			hero->setTexture(fall, true);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (frame >= 4)
		{
			frame = 0;
			if (frameOrientationX == 8)
			{
				frameOrientationX = 0;
			}
			else
			{
				frameOrientationX++;
			}
		}
		frame++;
		hero->setTexture(textureheroRight[frameOrientationX], true);
		hero->move(-8, 0);
		hero->setOrigin((hero->getLocalBounds().width / 2) + 30, (hero->getLocalBounds().height / 2) - 30);
		hero->setScale(-1.5, 1.5);

		if (jumping == true and restjump < 2)
		{
			hero->setTexture(fall, true);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		hero->setTexture(down, true);
	}

	if (ControlSkip <= -2)
	{
		count++;

		if (count == 1)
		{
			count = 0;
			ControlSkip = 4;
		}
	}
}

void Hero::attack()
{

	int tam = shots.size();

	if (tam >= 30)
	{
		shotstimer = 0;
		pop_attack();
	}

	if (tam < 30 and quantbullet < 5)
	{
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and hero->getScale().x == -1.5)
			{
				atack.play();
				Bullet *bu = new Bullet();
				bu->attacksprite->setScale(-1.3f, 1.3f);
				bu->attacksprite->setPosition(hero->getPosition().x + 90, hero->getPosition().y + 50);
				bu->orientation = true;
				shots.push_back(*bu);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and hero->getScale().x == 1.5)
			{
				atack.play();
				Bullet *bu = new Bullet();
				bu->attacksprite->setScale(1.3f, 1.3f);
				bu->attacksprite->setPosition(hero->getPosition().x, hero->getPosition().y + 50);
				bu->orientation = false;
				shots.push_back(*bu);
			}
		}

		// agachando
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and hero->getScale().x == -1.5 and sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
		{
			atack.play();
			Bullet *bu = new Bullet();
			bu->attacksprite->setScale(-1.3f, 1.3f);
			bu->attacksprite->setPosition(hero->getPosition().x + 90, hero->getPosition().y + 63);
			bu->orientation = true;
			shots.push_back(*bu);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and hero->getScale().x == 1.5 and sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			atack.play();
			Bullet *bu = new Bullet();
			bu->attacksprite->setScale(1.3f, 1.3f);
			bu->attacksprite->setPosition(hero->getPosition().x, hero->getPosition().y + 63);
			bu->orientation = false;
			shots.push_back(*bu);
		}

		int x = shots.size();

		bool check = false;

		if (check == false)
		{
			for (int j = 0; j < x; j++)
			{
				for (int i = 0; i < 4; i++)
				{
					stringstream ss;
					ss << "assets/Shoots/Player-Shoot/player-shoot" << i + 1 << ".png";
					shots[j].bullettexture[i]->loadFromFile(ss.str());
				}
			}
			check = true;
		}

		for (int j = 0; j < x; j++)
		{
			shots[j].animation();
		}
	}

	if (tam == 30)
	{
		quantbullet++;
	}
}

void Hero::pop_attack()
{
	int tam = shots.size();

	for (int i = 0; i < tam; i++)
	{
		shots.pop_back();
	}
}

void Hero::colision(shared_ptr<sf::Sprite> atingido, int *live)
{
	int tam = shots.size();

	for (int i = 0; i < tam; i++)
	{
		if (atingido->getGlobalBounds().intersects(shots[i].attacksprite->getGlobalBounds()))
		{
			if (atingido->getColor() != sf::Color::Transparent)
			{
				*live = *live - 1;
				atingido->setColor(sf::Color::Black);
			}else{
				atingido->setColor(sf::Color::White);
			}
		}
	}
}

void Hero::CheckVictory(int liveVilon, bool *GameVictory, int level)
{
	if (level == 3)
	{
		if (liveVilon < 0)
		{	
			countKill++;
			*GameVictory = true;
		}
	}
}


void Hero::SuperHero(){
	
	static int acm = 0;
	if(restartClock == true){
		acm = live;
		clock.restart();
		restartClock = false;
		quantbullet -= 2;
	}

	if(Activ == true){
		hero->setColor(sf::Color::Red);
		timepassado = clock.getElapsedTime();
		timer = timepassado.asSeconds();
		if(timer < 10){
			live = 10000;
		}else{
			live = acm;
			Activ = false;
		}
	}else{
		hero->setColor(sf::Color::White);
	}

}