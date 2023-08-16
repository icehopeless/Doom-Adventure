#include "Doom.hpp"

DoomAdventure::DoomAdventure() {
	window = make_shared<sf::RenderWindow>(
			//criando a janela com ponteiro inteligente
			sf::VideoMode(1280, 720), "Doom Adventure",
			sf::Style::Titlebar | sf::Style::Close);

	window->setFramerateLimit(60);
}

Hero::Hero() {
	hero = make_shared<sf::Sprite>();
	attacksprite = make_shared<sf::Sprite>();

	bullettexture.loadFromFile("assets/Shoots/Player-Shoot/player-shoot1.png");
	herotexture[0].loadFromFile("assets/Hero/Gunner/Gunner_Idle_1.png");

	textureheroRight[0].loadFromFile(
			"assets/Hero/Gunner/Gunner_Rise.png");
	textureheroRight[1].loadFromFile(
			"assets/Hero/Gunner/Gunner_Walk_1.png");
	textureheroRight[2].loadFromFile(
			"assets/Hero/Gunner/Gunner_Walk_2.png");
	textureheroRight[3].loadFromFile(
			"assets/Hero/Gunner/Gunner_Walk_3.png");
	textureheroRight[4].loadFromFile(
			"assets/Hero/Gunner/Gunner_Walk_4.png");
	textureheroRight[5].loadFromFile(
			"assets/Hero/Gunner/Gunner_Walk_5.png");
	textureheroRight[6].loadFromFile(
			"assets/Hero/Gunner/Gunner_Walk_6.png");
	textureheroRight[7].loadFromFile(
			"assets/Hero/Gunner/Gunner_Walk_7.png");
	textureheroRight[8].loadFromFile(
			"assets/Hero/Gunner/Gunner_Walk_8.png");
	textureherostop[0].loadFromFile(
			"assets/Hero/Gunner/Gunner_Idle_1.png");
	textureherostop[1].loadFromFile(
			"assets/Hero/Gunner/Gunner_Idle_2.png");
	textureherostop[2].loadFromFile(
			"assets/Hero/Gunner/Gunner_Idle_3.png");
	textureherostop[3].loadFromFile(
			"assets/Hero/Gunner/Gunner_Idle_4.png");
	down.loadFromFile("assets/Hero/Gunner/Gunner_Crouch.png");
	attacksprite->setTexture(bullettexture);
	attacksprite->setScale(1.f,1.f);
	hero->setScale(2.f,2.f);
	hero->setTexture(herotexture[0]);
	attack();
}

//animando o hero
void Hero::animation() {
	if (frame >= 5) {
		frame = 0;
		if (framestophero == 3) {

			framestophero = 0;
		} else {
			framestophero++;
		}
	}

	frame++;

	hero->setTexture(textureherostop[framestophero], true);

	float x;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

				if (frame >= 4) {
					frame = 0;
					if (frameLeftAndRight == 8) {
						frameLeftAndRight = 0;
					} else {
						frameLeftAndRight++;
					}
				}
				frame++;
				hero->setTexture(textureheroRight[frameLeftAndRight], true);
				hero->move(8, 0);
				hero->setScale(2.f, 2.f);
				
			}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				if (frame >= 4) {
					frame = 0;
					if (frameLeftAndRight == 8) {
						frameLeftAndRight = 0;
					} else {
						frameLeftAndRight++;
					}
				}
				frame++;
				hero->setTexture(textureheroRight[frameLeftAndRight], true);
				hero->move(-8, 0);
				hero->setScale(-2.f,2.f);
				
			}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
				hero->setTexture(down, true);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		hero->move(0, -15);
	}

	hero->move(0, 5);

}

void Hero::attk(){
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		
		attacksprite->setPosition(hero->getPosition().x + 83, hero->getPosition().y + 85);
	}
	attack();
}

void Npc::attack(){
	attacksprite->move(10,0);
}

void DoomAdventure::events() {
	sf::Event event;

	while (window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window->close();
		}
	}
}


void DoomAdventure::draw() {
	window->clear(sf::Color::Black);
	window->draw(*heroobj->hero);
	window->draw(*heroobj->attacksprite);
	window->display();
}

void DoomAdventure::game() {
	heroobj->animation();
	heroobj->attk();

}

void DoomAdventure::run() {
	while (window->isOpen()) {
		draw();
		events();
		game();
	}
}
