#include "Doom.hpp"

Villain::Villain(int referent)
{
	attack = false;
	fireanimation = false;
	this->referent = referent;
	Vilion = make_shared<sf::Sprite>();
	lifebar = make_shared<sf::Sprite>();
	if (referent == 1)
	{
		textureVilionRight[0].loadFromFile(
			"assets/Villain/Dragon/demon-idle.png");
		Vilion->setTexture(textureVilionRight[0]);
		sf::Vector2i position(0, 5);
		sf::Vector2i size(154, 144);
		Vilion->setTextureRect(sf::IntRect(position, size));
		framestop = 1;
		frameOrientationX = 1;
		Vilion->setScale(2.2f, 2.2f);
		// Vilion->setOrigin(Vilion->getPosition().x / 2 ,Vilion->getPosition().y / 2 );
		Vilion->setPosition(1000, 80);

	}
}

void Villain::animation()
{
	if (live > 0)
	{
		if (referent == 1)
		{
			Villan1();
		}
	}
}

void Villain::testAproxim(Hero *herobobj)
{
	int static play = 0;
	if (herobobj->hero->getGlobalBounds().intersects(Vilion->getGlobalBounds()))
	{
		if (play == 0)
		{
			visible = false;
			play = 1;
		}

		attack = true;
		herobobj->live -= 3;
	}
	else
	{
		play = 0;
		attack = false;
	}

	if(perseg == true){
		persegui(herobobj);
	}

	GetScale.x = herobobj->hero->getScale().x ;
	GetScale.y = herobobj->hero->getScale().y ;
	distance = herobobj->hero->getPosition().x - Vilion->getPosition().x ;
}
void Villain::Villan1()
{
	Vilion->setColor(sf::Color::White);
	if (perseg == false)
	{
		
		if (attack == false)
		{
			timer++;
			if (timer == 100 or timer == 200 or timer == 0)
			{
				fireanimation = false;
			}
			if (timer < 100)
			{
				Idle();
			}
			else if (timer > 100 and timer < 200)
			{
				WalkLeft();
			}
			else if (timer >= 200)
			{
				WalkRight();
			}
			if (timer == 300)
			{
				timer = 0;
			}
		}
		else
		{
			attacks();
		}
	}
}

void Villain::attacks()
{
	if (referent == 1)
	{
		attack1();
	}
}
void Villain::attack1()
{

	if(GetScale.x < -1){
		Vilion->setScale(-2.2,2.2);
	}else{
		Vilion->setScale(2.2,2.2);
	}
	textureVilionRight[0].loadFromFile(
		"assets/Villain/Dragon/demon-attack.png");
	Vilion->setTexture(textureVilionRight[0]);

	if (frame >= 2)
	{
		frame = 0;

		if (framestop >= 11 and fireanimation == false)
		{
			framestop = 1;
		}
		else
		{
			framestop++;
		}
	}
	else
	{
		frame++;
	}

	if (fireanimation == false)
	{
		if (framestop == 1)
		{
			sf::Vector2i position(0, 10);
			sf::Vector2i size(250, 180);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}

		if (framestop == 2)
		{
			sf::Vector2i position(250, 10);
			sf::Vector2i size(250, 180);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
		if (framestop == 3)
		{
			sf::Vector2i position(500, 10);
			sf::Vector2i size(250, 180);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
		if (framestop == 4)
		{
			sf::Vector2i position(750, 10);
			sf::Vector2i size(250, 180);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
		if (framestop == 5)
		{
			sf::Vector2i position(1000, 10);
			sf::Vector2i size(250, 180);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
		if (framestop == 6)
		{
			sf::Vector2i position(1250, 10);
			sf::Vector2i size(250, 180);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
		if (framestop == 7)
		{
			sf::Vector2i position(1500, 10);
			sf::Vector2i size(250, 180);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
		if (framestop == 8)
		{
			sf::Vector2i position(1670, 10);
			sf::Vector2i size(250, 180);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
		if (framestop == 9)
		{
			sf::Vector2i position(1900, 10);
			sf::Vector2i size(250, 180);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
		if (framestop == 10)
		{
			sf::Vector2i position(2150, 10);
			sf::Vector2i size(250, 180);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
		if (framestop == 11)
		{
			sf::Vector2i position(2400, 10);
			sf::Vector2i size(250, 180);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
	}
	perseg = true;
	attack = false;
}

void Villain::pop_attack()
{
	int tam = shots.size();

	for (int i = 0; i < tam; i++)
	{
		shots.pop_back();
	}
}

void Villain::Idle()
{
	textureVilionRight[0].loadFromFile("assets/Villain/Dragon/demon-idle.png");
	Vilion->setTexture(textureVilionRight[0]);
	Vilion->setScale(2.2f, 2.2f);
	if (frame >= 2)
	{
		frame = 0;
		if (framestop == 7 and fireanimation == false)
		{
			framestop = 1;
		}
		else
		{
			framestop++;
		}
	}
	else
	{
		frame++;
	}
	if (fireanimation == false)
	{
		if (framestop == 1)
		{
			sf::Vector2i position(0, 5);
			sf::Vector2i size(155, 144);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
		if (framestop == 2)
		{
			sf::Vector2i position(155, 5);
			sf::Vector2i size(155, 144);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
		if (framestop == 3)
		{
			sf::Vector2i position(325, 5);
			sf::Vector2i size(154, 144);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
		if (framestop == 4)
		{
			sf::Vector2i position(480, 5);
			sf::Vector2i size(154, 144);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
		if (framestop == 5)
		{
			sf::Vector2i position(620, 5);
			sf::Vector2i size(154, 144);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
		if (framestop == 6)
		{
			sf::Vector2i position(795, 5);
			sf::Vector2i size(154, 144);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
	}
}

void Villain::WalkLeft()
{
	Vilion->setScale(2.f, 2.f);
	textureVilionRight[0].loadFromFile("assets/Villain/Dragon/demon-idle.png");
	Vilion->setTexture(textureVilionRight[0]);

	if (frame >= 2)
	{
		frame = 0;
		if (framestop == 7 and fireanimation == false)
		{
			framestop = 1;
		}
		else
		{
			framestop++;
		}
	}
	else
	{
		frame++;
	}
	if (fireanimation == false)
	{
		if (framestop == 1)
		{
			sf::Vector2i position(0, 5);
			sf::Vector2i size(155, 144);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
		if (framestop == 2)
		{
			sf::Vector2i position(155, 5);
			sf::Vector2i size(155, 144);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
		if (framestop == 3)
		{
			sf::Vector2i position(325, 5);
			sf::Vector2i size(154, 144);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
		if (framestop == 4)
		{
			sf::Vector2i position(480, 5);
			sf::Vector2i size(154, 144);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
		if (framestop == 5)
		{
			sf::Vector2i position(620, 5);
			sf::Vector2i size(154, 144);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
		if (framestop == 6)
		{
			sf::Vector2i position(795, 5);
			sf::Vector2i size(154, 144);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
	}
	Vilion->move(-10, 0);
}
// andar para a esquerda
void Villain::WalkRight()
{

	Vilion->setScale(-2, 2);
	textureVilionRight[0].loadFromFile("assets/Villain/Dragon/demon-idle.png");
	Vilion->setTexture(textureVilionRight[0]);

	if (frame >= 2)
	{
		frame = 0;
		if (framestop == 7 and fireanimation == false)
		{
			framestop = 1;
		}
		else
		{
			framestop++;
		}
	}
	else
	{
		frame++;
	}
	if (fireanimation == false)
	{
		if (framestop == 1)
		{
			sf::Vector2i position(0, 5);
			sf::Vector2i size(155, 144);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
		if (framestop == 2)
		{
			sf::Vector2i position(155, 5);
			sf::Vector2i size(155, 144);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
		if (framestop == 3)
		{
			sf::Vector2i position(325, 5);
			sf::Vector2i size(154, 144);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
		if (framestop == 4)
		{
			sf::Vector2i position(480, 5);
			sf::Vector2i size(154, 144);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
		if (framestop == 5)
		{
			sf::Vector2i position(620, 5);
			sf::Vector2i size(154, 144);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
		if (framestop == 6)
		{
			sf::Vector2i position(795, 5);
			sf::Vector2i size(154, 144);
			Vilion->setTextureRect(sf::IntRect(position, size));
		}
	}
	Vilion->move(10, 0);
}



void Villain::persegui(Hero * heroobj){
	static int distanceY;

	distanceY =  heroobj->hero->getPosition().y - Vilion->getPosition().y;

	if(distance < -8 and distance >  -400){
		Vilion->move(-11,0);
	}
	if(distance >  8 and distance <  400 ){
		Vilion->move(11,0);
	}

	if(distanceY < -10 and distanceY >  -400 ){
		Vilion->move(0,-11);
	}
	if(distanceY > 300 and distanceY <  400 ){
		Vilion->move(0,11);
	}

	attack1();
	
}




Villain::~Villain()
{
}

