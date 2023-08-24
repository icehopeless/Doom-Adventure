#include "Doom.hpp"

Villain::Villain(int referent) {
	attack = false;
	fireanimation = false;
	this->referent = referent;
	Vilion = make_shared<sf::Sprite>();
	
	if (referent == 1) {
		textureVilionRight[0].loadFromFile("assets/Npcs/Death/Idle.png");
		Vilion->setTexture(textureVilionRight[0]);
		sf::Vector2i position(19, 8);
		sf::Vector2i size(42, 63);
		Vilion->setTextureRect(sf::IntRect(position, size));
		framestop = 1;
		frameOrientationX = 1;
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
            if(herobobj->hero->getPosition().y - Vilion->getPosition().y <= 60 and herobobj->hero->getPosition().y - Vilion->getPosition().y > -90 ){
                distance = herobobj->hero->getPosition().x - Vilion->getPosition().x;
                attack = true;
            }
            else{
                attack = false;
            }
        }
        else{
            attack = false;
        }
cout << herobobj->hero->getPosition().y - Vilion->getPosition().y << endl;
}
void Villain::Villan1() {

	if(attack == false){
		timer++;
		if(timer == 100 or timer == 200 or timer == 0){
			fireanimation = false;
		}
		if (timer < 100) {
			Iddle();
		}
		else if (timer > 100 and timer < 200) {
			WalkLeft();
		}else if(timer >= 200){
			WalkRight();
		}
		if(timer == 300){
			timer = 0;
	}
	}else{
		fireanimation = false;
		attacks();
	}

}

void Villain::attacks(){
	if(referent == 1){
		attack1();
	}

}
void Villain::attack1(){

	if(distance < 0){
		Vilion->setScale(1, 1);
	}
	if(distance > 0){
		Vilion->setScale(-1, 1);
	}

	textureVilionRight[0].loadFromFile("assets/Npcs/Death/Attack.png");
		Vilion->setTexture(textureVilionRight[0]);


		if (frame >= 5) {
			frame = 0;
			if (framestop >= 8 and fireanimation == false) {
				framestop = 1;

			} else {
				framestop++;
			}
		} else {
			frame++;
		}

		if (fireanimation == false) {
			if (framestop == 1) {
				sf::Vector2i position(31, 14);
				sf::Vector2i size(56, 103);
				Vilion->setTextureRect(sf::IntRect(position, size));
			}

			if (framestop == 2) {
				sf::Vector2i position(153, 14);
				sf::Vector2i size(56, 103);
				Vilion->setTextureRect(sf::IntRect(position, size));
			}
			if (framestop == 3) {
				sf::Vector2i position(280, 14);
				sf::Vector2i size(56, 103);
				Vilion->setTextureRect(sf::IntRect(position, size));
			}
			if (framestop == 4) {
				sf::Vector2i position(398, 14);
				sf::Vector2i size(56, 103);
				Vilion->setTextureRect(sf::IntRect(position, size));
			}
			if (framestop == 5) {
				sf::Vector2i position(533, 14);
				sf::Vector2i size(56, 103);
				Vilion->setTextureRect(sf::IntRect(position, size));
			}
			if (framestop == 6) {
				sf::Vector2i position(6, 130);
				sf::Vector2i size(95, 107);
				Vilion->setTextureRect(sf::IntRect(position, size));
			}
			if (framestop == 7) {
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
						shots[j].bullettexture[0]->loadFromFile("assets/Npcs/Death/Shot.png");
						shots[j].attacksprite->setTexture(*shots[j].bullettexture[0]);
						

				}
				check = true;
			}

			int tam = shots.size();

				if(tam >= 20){
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

void Villain::Iddle(){
	textureVilionRight[0].loadFromFile("assets/Npcs/Death/Idle.png");
			Vilion->setTexture(textureVilionRight[0]);
			Vilion->setScale(2,2);
			if (frame >= 5) {
				frame = 0;
				if (framestop == 10 and fireanimation == false) {
					framestop = 1;

				} else if (framestop == 10 and fireanimation == true) {
					framestop = 7;

				} else {
					framestop++;
				}
			} else {
				frame++;
			}
			if (fireanimation == false) {
				if (framestop == 1) {
					sf::Vector2i position(19, 8);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}

				if (framestop == 2) {
					sf::Vector2i position(94, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}
				if (framestop == 3) {
					sf::Vector2i position(174, 7);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}
				if (framestop == 4) {
					sf::Vector2i position(255, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}
				if (framestop == 5) {
					sf::Vector2i position(332, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}
				if (framestop == 6) {
					sf::Vector2i position(414, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
					fireanimation = true;
				}

			} else {

				if (framestop == 7) {
					sf::Vector2i position(494, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));

				}

				if (framestop == 8) {
					sf::Vector2i position(571, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}
				if (framestop == 9) {
					sf::Vector2i position(571, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}
				if (framestop == 10) {
					sf::Vector2i position(732, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}
			}
}
//andar para a esquerda
void Villain::WalkLeft(){
	Vilion->setScale(2,2);
			textureVilionRight[0].loadFromFile("assets/Npcs/Death/fly_Left.png");
			Vilion->setTexture(textureVilionRight[0]);

			if (frame >= 5) {
				frame = 0;
				if (frameOrientationX == 6 and fireanimation == false) {
					frameOrientationX = 1;

				} else if (frameOrientationX == 6 and fireanimation == true) {
					frameOrientationX = 3;

				} else {
					frameOrientationX++;
				}
			} else {
				frame++;
			}

			if (fireanimation == false) {
				if (frameOrientationX == 1) {
					sf::Vector2i position(21, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}

				if (frameOrientationX == 2) {
					sf::Vector2i position(99, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}

				if (frameOrientationX == 3) {
					sf::Vector2i position(170, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
					fireanimation = true;
				}
			} else {
				if (frameOrientationX == 4) {
					sf::Vector2i position(237, 10);
					sf::Vector2i size(76, 58);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}

				if (frameOrientationX == 5) {
					sf::Vector2i position(323, 10);
					sf::Vector2i size(76, 58);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}
				if (frameOrientationX == 5) {
						sf::Vector2i position(403, 10);
						sf::Vector2i size(76, 58);
						Vilion->setTextureRect(sf::IntRect(position, size));
					}
			}

			Vilion->move(-10,0);
}
//andar para a esquerda
void Villain::WalkRight(){

	textureVilionRight[0].loadFromFile("assets/Npcs/Death/fly_Left.png");
			Vilion->setTexture(textureVilionRight[0]);
			Vilion->setScale(-2,2);
			if (frame >= 5) {
				frame = 0;
				if (frameOrientationX == 6 and fireanimation == false) {
					frameOrientationX = 1;

				} else if (frameOrientationX == 6 and fireanimation == true) {
					frameOrientationX = 3;

				} else {
					frameOrientationX++;
				}
			} else {
				frame++;
			}

			if (fireanimation == false) {
				if (frameOrientationX == 1) {
					sf::Vector2i position(21, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}

				if (frameOrientationX == 2) {
					sf::Vector2i position(99, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}

				if (frameOrientationX == 3) {
					sf::Vector2i position(170, 10);
					sf::Vector2i size(42, 63);
					Vilion->setTextureRect(sf::IntRect(position, size));
					fireanimation = true;
				}
			} else {
				if (frameOrientationX == 4) {
					sf::Vector2i position(237, 10);
					sf::Vector2i size(76, 58);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}

				if (frameOrientationX == 5) {
					sf::Vector2i position(323, 10);
					sf::Vector2i size(76, 58);
					Vilion->setTextureRect(sf::IntRect(position, size));
				}
				if (frameOrientationX == 5) {
						sf::Vector2i position(403, 10);
						sf::Vector2i size(76, 58);
						Vilion->setTextureRect(sf::IntRect(position, size));
					}
			}

			Vilion->move(10,0);

}
Villain::~Villain() {

}
