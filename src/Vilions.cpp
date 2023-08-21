#include "Doom.hpp"

Villain::Villain(int referent) {
	attack = false;
	fireanimation = false;
	this->referent = referent;
	Vilion = make_shared<sf::Sprite>();

	if (referent == 1) {
		textureVilionRight[0].loadFromFile("assets/Vilions/Death/Idle.png");
		Vilion->setTexture(textureVilionRight[0]);
		sf::Vector2i position(19, 8);
		sf::Vector2i size(42, 63);
		Vilion->setTextureRect(sf::IntRect(position, size));
		framesStopVilion = 1;
		frameLeftAndRight = 1;
		Vilion->setPosition(1200, 300);
	}
}

void Villain::animation() {
	if (referent == 1) {
		Villan1();
	}
}

void Villain::testAproxim(Hero * herobobj){
	if(herobobj->hero->getPosition().x - Vilion->getPosition().x <= 20 and herobobj->hero->getPosition().x - Vilion->getPosition().x > -200 ){
		distance = herobobj->hero->getPosition().x - Vilion->getPosition().x;
		attack = true;
	}
	else{
		attack = false;
	}

}
void Villain::Villan1() {

	if(attack == false){
		timer++;
		if(timer == 100 or timer == 200 or timer == 0){
			fireanimation = false;
		}
		if (timer < 100) {
			transtion1();
		}
		else if (timer > 100 and timer < 200) {
			transtion2();
		}else if(timer >= 200){
			transtion3();
		}
		if(timer == 300){
			timer = 0;
	}
	}else{
		fireanimation = false;
		attks();
	}

}

void Villain::attks(){
	if(referent == 1){
		attk1();
	}

}
void Villain::attk1(){

	if(distance < 0){
		Vilion->setScale(1, 1);
	}
	if(distance > 0){
		Vilion->setScale(-1, 1);
	}

	textureVilionRight[0].loadFromFile("assets/Vilions/Death/Attack.png");
		Vilion->setTexture(textureVilionRight[0]);


		if (frame >= 5) {
			frame = 0;
			if (framesStopVilion >= 8 and fireanimation == false) {
				framesStopVilion = 1;

			} else {
				framesStopVilion++;
			}
		} else {
			frame++;
		}

		cout << framesStopVilion << endl;
		if (fireanimation == false) {
			if (framesStopVilion == 1) {
				sf::Vector2i position(31, 14);
				sf::Vector2i size(56, 103);
				Vilion->setTextureRect(sf::IntRect(position, size));
			}

			if (framesStopVilion == 2) {
				sf::Vector2i position(153, 14);
				sf::Vector2i size(56, 103);
				Vilion->setTextureRect(sf::IntRect(position, size));
			}
			if (framesStopVilion == 3) {
				sf::Vector2i position(280, 14);
				sf::Vector2i size(56, 103);
				Vilion->setTextureRect(sf::IntRect(position, size));
			}
			if (framesStopVilion == 4) {
				sf::Vector2i position(398, 14);
				sf::Vector2i size(56, 103);
				Vilion->setTextureRect(sf::IntRect(position, size));
			}
			if (framesStopVilion == 5) {
				sf::Vector2i position(533, 14);
				sf::Vector2i size(56, 103);
				Vilion->setTextureRect(sf::IntRect(position, size));
			}
			if (framesStopVilion == 6) {
				sf::Vector2i position(6, 130);
				sf::Vector2i size(95, 107);
				Vilion->setTextureRect(sf::IntRect(position, size));
			}
			if (framesStopVilion == 7) {
				sf::Vector2i position(123, 130);
				sf::Vector2i size(95, 107);
				Vilion->setTextureRect(sf::IntRect(position, size));
				Bullet *bu = new Bullet();
				bu->attacksprite->setScale(-1.3f, 1.3f);
				bu->attacksprite->setPosition(Vilion->getPosition().x ,Vilion->getPosition().y + 45);

				if(distance < 0){
					bu->orientation = true;
				}
				if(distance > 0){
					bu->orientation = false;
				}

				shots.push_back(*bu);
			}

			int x = shots.size();

			bool check = false;

			if (check == false) {
				for (int j = 0; j < x; j++) {
						shots[j].bullettexture[0]->loadFromFile("assets/Vilions/Death/Shot.png");
						shots[j].attacksprite->setTexture(*shots[j].bullettexture[0]);

				}
				check = true;
			}

			int tam = shots.size();

				if(tam >= 20/* and shotstimer >= 100 */ ){
					pop_attack();
				}

		}
}
void Villain::pop_attack() {
	int tam = shots.size();

	for(int i  = 0; i < tam ; i++){
		shots.pop_back();
	}

}

void Villain::transtion1(){
	textureVilionRight[0].loadFromFile("assets/Vilions/Death/Idle.png");
			Vilion->setTexture(textureVilionRight[0]);
			Vilion->setScale(2,2);
			if (frame >= 5) {
				frame = 0;
				if (framesStopVilion == 10 and fireanimation == false) {
					framesStopVilion = 1;

				} else if (framesStopVilion == 10 and fireanimation == true) {
					framesStopVilion = 7;

				} else {
					framesStopVilion++;
				}
			} else {
				frame++;
			}
			if (fireanimation == false) {
				if (framesStopVilion == 1) {
					sf::Vector2i position(19, 8);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}

				if (framesStopVilion == 2) {
					sf::Vector2i position(94, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}
				if (framesStopVilion == 3) {
					sf::Vector2i position(174, 7);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}
				if (framesStopVilion == 4) {
					sf::Vector2i position(255, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}
				if (framesStopVilion == 5) {
					sf::Vector2i position(332, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}
				if (framesStopVilion == 6) {
					sf::Vector2i position(414, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
					fireanimation = true;
				}

			} else {

				if (framesStopVilion == 7) {
					sf::Vector2i position(494, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));

				}

				if (framesStopVilion == 8) {
					sf::Vector2i position(571, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}
				if (framesStopVilion == 9) {
					sf::Vector2i position(571, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}
				if (framesStopVilion == 10) {
					sf::Vector2i position(732, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}
			}
}

void Villain::transtion2(){
	Vilion->setScale(2,2);
			textureVilionRight[0].loadFromFile("assets/Vilions/Death/fly_Left.png");
			Vilion->setTexture(textureVilionRight[0]);

			if (frame >= 5) {
				frame = 0;
				if (frameLeftAndRight == 6 and fireanimation == false) {
					frameLeftAndRight = 1;

				} else if (frameLeftAndRight == 6 and fireanimation == true) {
					frameLeftAndRight = 3;

				} else {
					frameLeftAndRight++;
				}
			} else {
				frame++;
			}

			if (fireanimation == false) {
				if (frameLeftAndRight == 1) {
					sf::Vector2i position(21, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}

				if (frameLeftAndRight == 2) {
					sf::Vector2i position(99, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}

				if (frameLeftAndRight == 3) {
					sf::Vector2i position(170, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
					fireanimation = true;
				}
			} else {
				if (frameLeftAndRight == 4) {
					sf::Vector2i position(237, 10);
					sf::Vector2i size(76, 58);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}

				if (frameLeftAndRight == 5) {
					sf::Vector2i position(323, 10);
					sf::Vector2i size(76, 58);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}
				if (frameLeftAndRight == 5) {
						sf::Vector2i position(403, 10);
						sf::Vector2i size(76, 58);
						Vilion->setTextureRect(sf::IntRect(position, size));
					}
			}

			Vilion->move(-10,0);
}
void Villain::transtion3(){

	textureVilionRight[0].loadFromFile("assets/Vilions/Death/fly_Left.png");
			Vilion->setTexture(textureVilionRight[0]);
			Vilion->setScale(-2,2);
			if (frame >= 5) {
				frame = 0;
				if (frameLeftAndRight == 6 and fireanimation == false) {
					frameLeftAndRight = 1;

				} else if (frameLeftAndRight == 6 and fireanimation == true) {
					frameLeftAndRight = 3;

				} else {
					frameLeftAndRight++;
				}
			} else {
				frame++;
			}

			if (fireanimation == false) {
				if (frameLeftAndRight == 1) {
					sf::Vector2i position(21, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}

				if (frameLeftAndRight == 2) {
					sf::Vector2i position(99, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}

				if (frameLeftAndRight == 3) {
					sf::Vector2i position(170, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
					fireanimation = true;
				}
			} else {
				if (frameLeftAndRight == 4) {
					sf::Vector2i position(237, 10);
					sf::Vector2i size(76, 58);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}

				if (frameLeftAndRight == 5) {
					sf::Vector2i position(323, 10);
					sf::Vector2i size(76, 58);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}
				if (frameLeftAndRight == 5) {
						sf::Vector2i position(403, 10);
						sf::Vector2i size(76, 58);
						Vilion->setTextureRect(sf::IntRect(position, size));
					}
			}

			Vilion->move(10,0);

}
Villain::~Villain() {

}
