#include "Doom.hpp"

Npcs::Npcs(int referent){
    npc = make_shared<sf::Sprite>();

	if(referent == 1){
    npcstexture.loadFromFile("assets/Npcs/MeioTermo/spritesheet.png");
    npc->setTexture(npcstexture);
    sf::Vector2i position(0, 180);
    npc->setPosition(0,45);
	sf::Vector2i size(67, 60);
    npc->setTextureRect(sf::IntRect(position, size));
    npc->setScale(2.f,2.f);
	this->referent = referent;
    attack = false;
    npc->setColor(sf::Color::Cyan);
    framestop = 1;    
	}

	if(referent == 2){
	npcstexture.loadFromFile("assets/Npcs/Wolf/hell-hound-idle.png");
    npc->setTexture(npcstexture);
    sf::Vector2i position(0, 180);
	sf::Vector2i size(67, 60);
    npc->setTextureRect(sf::IntRect(position, size));
    npc->setScale(2.f,2.f);
	this->referent = referent;
    attack = false;
    framestop = 1;   
	}
	
    if(referent == 3){
		textureVilionRight[0].loadFromFile("assets/Npcs/Death/Idle.png");
		npc->setTexture(textureVilionRight[0]);
		sf::Vector2i position(19, 8);
		sf::Vector2i size(42, 63);
		npc->setTextureRect(sf::IntRect(position, size));
		framestop = 1;
		frameOrientationX = 1;
		npc->setPosition(1200, 300);
        this->referent = referent;
	}

}

void Npcs::animation(){
if (referent == 1) {
		npc1();
	}
if (referent == 2) {
		npc2();
	}
    if (referent == 3) {
		npc3();
	}
}

void Npcs::npc1(){
    if(attack == false){
		timer++;
		if (timer < 300) {
			RightWalk();
		}
		else if (timer > 100 and timer <= 600) {
			LeftWalk();
		}
		if(timer == 600){
			timer = 0;
        }
	} else {
        attack1();
    }
}



void Npcs::npc2(){
    if(attack == false){
		timer++;
		if (timer < 300) {
			RightWalk();
		}
		else if (timer > 100 and timer <= 600) {
			LeftWalk();
		}
		if(timer == 600){
			timer = 0;
        }
	} else {
        attack1();
    }
}

void Npcs::npc3(){
if(attack == false){
		timer++;
		if(timer == 100 or timer == 200 or timer == 0){
			fireanimation = false;
		}
		if (timer < 100) {
			Iddle();
		}
		else if (timer > 100 and timer < 200) {
			LeftWalk();
		}else if(timer >= 200){
			RightWalk();
		}
		if(timer == 300){
			timer = 0;
	}
	}else{
		fireanimation = false;
		attack3();
	}
}
void Npcs::RightWalk(){
	if(referent == 1){
        npc->setScale(2.f,2.f);
        if (frame >= 5) {
                    frame = 0;
                    if (framestop == 8) {
                        framestop = 1;

                    } else {
                        framestop++;
                    }
                } else {
                    frame++;
                }

        if(framestop == 1){
            sf::Vector2i position(13, 10);
            sf::Vector2i size(38, 49);
            npc->setTextureRect(sf::IntRect(position, size));
        }
        else if(framestop == 2){
            sf::Vector2i position(85, 6);
            sf::Vector2i size(38, 49);
            npc->setTextureRect(sf::IntRect(position, size));
        }
        else if (framestop == 3){
            sf::Vector2i position(144, 6);
            sf::Vector2i size(38, 49);
            npc->setTextureRect(sf::IntRect(position, size));
        }
        else if(framestop == 4){
            sf::Vector2i position(209, 6);
            sf::Vector2i size(38, 49);
            npc->setTextureRect(sf::IntRect(position, size));
        }else if(framestop == 5){
            sf::Vector2i position(261, 6);
            sf::Vector2i size(38, 49);
            npc->setTextureRect(sf::IntRect(position, size));
        }else if(framestop == 6){
            sf::Vector2i position(333, 6);
            sf::Vector2i size(38, 49);
            npc->setTextureRect(sf::IntRect(position, size));
        }else if(framestop == 7){
            sf::Vector2i position(405, 6);
            sf::Vector2i size(38, 49);
            npc->setTextureRect(sf::IntRect(position, size));
        }else if(framestop == 8){
            sf::Vector2i position(466, 6);
            sf::Vector2i size(38, 49);
            npc->setTextureRect(sf::IntRect(position, size));
        }
        npc->move(3,0);
	}
	if(referent == 2){

	}	
    if(referent == 3){
textureVilionRight[0].loadFromFile("assets/Npcs/Death/fly_Left.png");
			npc->setTexture(textureVilionRight[0]);
			npc->setScale(-2,2);
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
					npc->setTextureRect(sf::IntRect(position, size));
				}

				if (frameOrientationX == 2) {
					sf::Vector2i position(99, 10);
					sf::Vector2i size(42, 63);
					npc->setTextureRect(sf::IntRect(position, size));
				}

				if (frameOrientationX == 3) {
					sf::Vector2i position(170, 10);
					sf::Vector2i size(42, 63);
					npc->setTextureRect(sf::IntRect(position, size));
					fireanimation = true;
				}
			} else {
				if (frameOrientationX == 4) {
					sf::Vector2i position(237, 10);
					sf::Vector2i size(76, 58);
					npc->setTextureRect(sf::IntRect(position, size));
				}

				if (frameOrientationX == 5) {
					sf::Vector2i position(323, 10);
					sf::Vector2i size(76, 58);
					npc->setTextureRect(sf::IntRect(position, size));
				}
				if (frameOrientationX == 5) {
						sf::Vector2i position(403, 10);
						sf::Vector2i size(76, 58);
						npc->setTextureRect(sf::IntRect(position, size));
					}
			}

			npc->move(10,0);
    }
}

void Npcs::LeftWalk(){
    if(referent == 1){
        npc->setScale(-2.f,2.f);
        if (frame >= 5) {
                    frame = 0;
                    if (framestop == 8) {
                        framestop = 1;

                    } else {
                        framestop++;
                    }
                } else {
                    frame++;
                }

        if(framestop == 1){
            sf::Vector2i position(13, 10);
            sf::Vector2i size(38, 49);
            npc->setTextureRect(sf::IntRect(position, size));
        }
        else if(framestop == 2){
            sf::Vector2i position(85, 6);
            sf::Vector2i size(38, 49);
            npc->setTextureRect(sf::IntRect(position, size));
        }
        else if (framestop == 3){
            sf::Vector2i position(144, 6);
            sf::Vector2i size(38, 49);
            npc->setTextureRect(sf::IntRect(position, size));
        }
        else if(framestop == 4){
            sf::Vector2i position(209, 6);
            sf::Vector2i size(38, 49);
            npc->setTextureRect(sf::IntRect(position, size));
        }else if(framestop == 5){
            sf::Vector2i position(261, 6);
            sf::Vector2i size(38, 49);
            npc->setTextureRect(sf::IntRect(position, size));
        }else if(framestop == 6){
            sf::Vector2i position(333, 6);
            sf::Vector2i size(38, 49);
            npc->setTextureRect(sf::IntRect(position, size));
        }else if(framestop == 7){
            sf::Vector2i position(405, 6);
            sf::Vector2i size(38, 49);
            npc->setTextureRect(sf::IntRect(position, size));
        }else if(framestop == 8){
            sf::Vector2i position(466, 6);
            sf::Vector2i size(38, 49);
            npc->setTextureRect(sf::IntRect(position, size));
        }
        npc->move(-3,0);
    }

    if(referent == 3){
        npc->setScale(2,2);
			textureVilionRight[0].loadFromFile("assets/Npcs/Death/fly_Left.png");
			npc->setTexture(textureVilionRight[0]);

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
					npc->setTextureRect(sf::IntRect(position, size));
				}

				if (frameOrientationX == 2) {
					sf::Vector2i position(99, 10);
					sf::Vector2i size(42, 63);
					npc->setTextureRect(sf::IntRect(position, size));
				}

				if (frameOrientationX == 3) {
					sf::Vector2i position(170, 10);
					sf::Vector2i size(42, 63);
					npc->setTextureRect(sf::IntRect(position, size));
					fireanimation = true;
				}
			} else {
				if (frameOrientationX == 4) {
					sf::Vector2i position(237, 10);
					sf::Vector2i size(76, 58);
					npc->setTextureRect(sf::IntRect(position, size));
				}

				if (frameOrientationX == 5) {
					sf::Vector2i position(323, 10);
					sf::Vector2i size(76, 58);
					npc->setTextureRect(sf::IntRect(position, size));
				}
				if (frameOrientationX == 5) {
						sf::Vector2i position(403, 10);
						sf::Vector2i size(76, 58);
						npc->setTextureRect(sf::IntRect(position, size));
					}
			}

			npc->move(-10,0);
    }
 
}

void Npcs::attack1(){

	if(distance > 0){
		npc->setScale(2.f,2.f);
	}
	if(distance < 0){
		npc->setScale(-2.f,2.f);
	}

  if (frame >= 5) {
				frame = 0;
				if (framestop == 8) {
					framestop = 1;

				} else {
					framestop++;
				}
			} else {
				frame++;
		}
    if(framestop == 1){
        sf::Vector2i position(13, 200);
		sf::Vector2i size(62, 46);
        npc->setTextureRect(sf::IntRect(position, size));
    }
        if(framestop == 2){
        sf::Vector2i position(82, 200);
		sf::Vector2i size(62, 46);
        npc->setTextureRect(sf::IntRect(position, size));
    }
        if(framestop == 3){
        sf::Vector2i position(143, 200);
		sf::Vector2i size(62, 46);
        npc->setTextureRect(sf::IntRect(position, size));
    }
        if(framestop == 4){
        sf::Vector2i position(205, 200);
		sf::Vector2i size(62, 46);
        npc->setTextureRect(sf::IntRect(position, size));
    }
        if(framestop == 5){
        sf::Vector2i position(270, 200);
		sf::Vector2i size(62, 46);
        npc->setTextureRect(sf::IntRect(position, size));
    }
        if(framestop == 6){
        sf::Vector2i position(333, 200);
		sf::Vector2i size(62, 46);
        npc->setTextureRect(sf::IntRect(position, size));
    }
        if(framestop == 7){
        sf::Vector2i position(396, 200);
		sf::Vector2i size(62, 46);
        npc->setTextureRect(sf::IntRect(position, size));
    }
    if(framestop == 8){
    Bullet *bu = new Bullet();
				bu->attacksprite->setScale(-1.3f, 1.3f);
				bu->attacksprite->setPosition(npc->getPosition().x + 35,npc->getPosition().y + 33);

			if(distance < 0){
					bu->orientation = true;
				}
				if(distance > 0){
					bu->orientation = false;
				}

				shots.push_back(*bu);
			

			int x = shots.size();
            
			bool check = false;

			if (check == false) {
                for (int j = 0; j < x; j++) {
						shots[j].bullettexture[0]->loadFromFile("assets/Npcs/MeioTermo/projectile.png");
						shots[j].attacksprite->setTexture(*shots[j].bullettexture[0]);
                        shots[j].attacksprite->setColor(sf::Color::Cyan);

				}
				check = true;
			}
    }
			int tam = shots.size();

				if(tam >= 20){
					pop_attack();
				}

}

void Npcs::attack3(){

	if(distance < 0){
		npc->setScale(1, 1);
	}
	if(distance > 0){
		npc->setScale(-1, 1);
	}

	textureVilionRight[0].loadFromFile("assets/Npcs/Death/Attack.png");
		npc->setTexture(textureVilionRight[0]);


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
				npc->setTextureRect(sf::IntRect(position, size));
			}

			if (framestop == 2) {
				sf::Vector2i position(153, 14);
				sf::Vector2i size(56, 103);
				npc->setTextureRect(sf::IntRect(position, size));
			}
			if (framestop == 3) {
				sf::Vector2i position(280, 14);
				sf::Vector2i size(56, 103);
				npc->setTextureRect(sf::IntRect(position, size));
			}
			if (framestop == 4) {
				sf::Vector2i position(398, 14);
				sf::Vector2i size(56, 103);
				npc->setTextureRect(sf::IntRect(position, size));
			}
			if (framestop == 5) {
				sf::Vector2i position(533, 14);
				sf::Vector2i size(56, 103);
				npc->setTextureRect(sf::IntRect(position, size));
			}
			if (framestop == 6) {
				sf::Vector2i position(6, 130);
				sf::Vector2i size(95, 107);
				npc->setTextureRect(sf::IntRect(position, size));
			}
			if (framestop == 7) {
				sf::Vector2i position(123, 130);
				sf::Vector2i size(95, 107);
				npc->setTextureRect(sf::IntRect(position, size));
				Bullet *bu = new Bullet();
				bu->attacksprite->setScale(-1.3f, 1.3f);
				bu->attacksprite->setPosition(npc->getPosition().x ,npc->getPosition().y + 45);

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
void Npcs::Iddle(){
	textureVilionRight[0].loadFromFile("assets/Npcs/Death/Idle.png");
			npc->setTexture(textureVilionRight[0]);
			npc->setScale(2,2);
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
					npc->setTextureRect(sf::IntRect(position, size));
				}

				if (framestop == 2) {
					sf::Vector2i position(94, 10);
					sf::Vector2i size(42, 63);
					npc->setTextureRect(sf::IntRect(position, size));
				}
				if (framestop == 3) {
					sf::Vector2i position(174, 7);
					sf::Vector2i size(42, 63);
					npc->setTextureRect(sf::IntRect(position, size));
				}
				if (framestop == 4) {
					sf::Vector2i position(255, 10);
					sf::Vector2i size(42, 63);
					npc->setTextureRect(sf::IntRect(position, size));
				}
				if (framestop == 5) {
					sf::Vector2i position(332, 10);
					sf::Vector2i size(42, 63);
					npc->setTextureRect(sf::IntRect(position, size));
				}
				if (framestop == 6) {
					sf::Vector2i position(414, 10);
					sf::Vector2i size(42, 63);
					npc->setTextureRect(sf::IntRect(position, size));
					fireanimation = true;
				}

			} else {

				if (framestop == 7) {
					sf::Vector2i position(494, 10);
					sf::Vector2i size(42, 63);
					npc->setTextureRect(sf::IntRect(position, size));

				}

				if (framestop == 8) {
					sf::Vector2i position(571, 10);
					sf::Vector2i size(42, 63);
					npc->setTextureRect(sf::IntRect(position, size));
				}
				if (framestop == 9) {
					sf::Vector2i position(571, 10);
					sf::Vector2i size(42, 63);
					npc->setTextureRect(sf::IntRect(position, size));
				}
				if (framestop == 10) {
					sf::Vector2i position(732, 10);
					sf::Vector2i size(42, 63);
					npc->setTextureRect(sf::IntRect(position, size));
				}
			}
}

void Npcs::testAproxim(Hero * herobobj){
    if(referent == 1){
        if(herobobj->hero->getPosition().x - npc->getPosition().x <= 100 and herobobj->hero->getPosition().x - npc->getPosition().x > -200 ){
            if(herobobj->hero->getPosition().y - npc->getPosition().y <= 0 and herobobj->hero->getPosition().y - npc->getPosition().y > -105 ){
                distance = herobobj->hero->getPosition().x - npc->getPosition().x;
                attack = true;
            }
            else{
                attack = false;
            }
        }
        else{
            attack = false;
        }
    }
    if(referent == 3){
        if(herobobj->hero->getPosition().x - npc->getPosition().x <= 20 and herobobj->hero->getPosition().x - npc->getPosition().x > -200 ){
            if(herobobj->hero->getPosition().y - npc->getPosition().y <= 60 and herobobj->hero->getPosition().y - npc->getPosition().y > -90 ){
                distance = herobobj->hero->getPosition().x - npc->getPosition().x;
                attack = true;
            }
            else{
                attack = false;
            }
        }
        else{
            attack = false;
        }
    }
    

}
void Npcs::pop_attack() {
	int tam = shots.size();

	for(int i  = 0; i < tam ; i++){
		shots.pop_back();
	}	
}










