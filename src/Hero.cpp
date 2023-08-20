#include "Doom.hpp"

Hero::Hero() {
	hero = make_shared<sf::Sprite>();

	herotexture[0].loadFromFile("assets/Hero/Gunner/Gunner_Idle_1.png");

	for (int i = 0; i < 9; i++) {
		if (i == 0) {
			textureheroRight[i].loadFromFile(
					"assets/Hero/Gunner/Gunner_Rise.png");
		} else {
			stringstream ss;
			ss << "assets/Hero/Gunner/Gunner_Walk_" << i << ".png";
			textureheroRight[i].loadFromFile(ss.str());
		}
	}

	for (int i = 0; i < 4; i++) {
		stringstream ss;
		ss << "assets/Hero/Gunner/Gunner_Idle_" << i + 1 << ".png";
		textureherostop[i].loadFromFile(ss.str());
	}

	down.loadFromFile("assets/Hero/Gunner/Gunner_Crouch.png");
	hero->setScale(2.f, 2.f);
	hero->setTexture(herotexture[0]);
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
		hero->setScale(-2.f, 2.f);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		hero->setTexture(down, true);
		hero->move(0, 15);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		hero->move(0, -15);
	}

}

void Hero::attk() {

	int tam = shots.size();

	if(tam >= 20 /* and shotstimer >= 100 */ ){
		shotstimer =0;
		pop_attack();
	}

	if(tam < 20){
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and hero->getScale().x == -2) {
			Bullet *bu = new Bullet();
			bu->attacksprite->setScale(-1.3f, 1.3f);
			bu->attacksprite->setPosition(hero->getPosition().x - 77,hero->getPosition().y + 77);
			bu->orientation = true;
			shots.push_back(*bu);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)and hero->getScale().x == 2) {
			Bullet *bu = new Bullet();
			bu->attacksprite->setScale(1.3f, 1.3f);
			bu->attacksprite->setPosition(hero->getPosition().x + 75,hero->getPosition().y + 77);
			bu->orientation = false;
			shots.push_back(*bu);
		}

		//agachando
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)and hero->getScale().x == -2 and sf::Keyboard::isKeyPressed(sf::Keyboard::Down))) {
			Bullet *bu = new Bullet();
			bu->attacksprite->setScale(-1.3f, 1.3f);
			bu->attacksprite->setPosition(hero->getPosition().x - 77,hero->getPosition().y + 88);
			bu->orientation = true;
			shots.push_back(*bu);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and hero->getScale().x == 2 and sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			Bullet *bu = new Bullet();
			bu->attacksprite->setScale(1.3f, 1.3f);
			bu->attacksprite->setPosition(hero->getPosition().x + 75,hero->getPosition().y + 88);
			bu->orientation = false;
			shots.push_back(*bu);
		}

		int x = shots.size();

		bool check = false;

		if(check == false){
			for(int j =0; j < x; j++){
				for (int i =0; i < 4; i++){
					stringstream ss;
					ss << "assets/Shoots/Player-Shoot/player-shoot" <<i + 1<< ".png";
					shots[j].bullettexture[i]->loadFromFile(ss.str());
				}
			}
			check = true;
		}

		for(int j =0; j < x; j++){
			shots[j].animation();
		}

	}
}

void Hero::pop_attack() {
	int tam = shots.size();

	for(int i  = 0; i < tam ; i++){
		shots.pop_back();
	}

}
