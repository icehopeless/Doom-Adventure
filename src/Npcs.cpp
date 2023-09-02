#include "Doom.hpp"

Npcs::Npcs(int referent){
    npc = make_shared<sf::Sprite>();
    fireanimation = false;
	orientation =false;
	if(referent == 1){
		live = 50;
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
		Npcatack.loadFromFile("assets/attacks_sounds/arrow.wav");
		atack.setBuffer(Npcatack);
		atack.setVolume(100);
		NpcDead.loadFromFile("assets/attacks_sounds/Ghost.wav");
		deadSound.setBuffer(NpcDead);
		deadSound.setVolume(100);
	}

	if(referent == 2){
			live = 50;
		npcstexture.loadFromFile("assets/Npcs/Wolf/hell-hound-idle.png");
		npc->setTexture(npcstexture);
		sf::Vector2i position(0, 180);
		sf::Vector2i size(67, 60);
		npc->setTextureRect(sf::IntRect(position, size));
		npc->setScale(2.f,2.f);
		npc->setPosition(800, 540);
		this->referent = referent;
		attack = false;
		framestop = 1;   
	}
	
    if(referent == 3){
		live = 50;
		npcstexture.loadFromFile("assets/Npcs/Death/Idle.png");
		npc->setTexture(npcstexture);
		sf::Vector2i position(19, 8);
		sf::Vector2i size(42, 63);
		npc->setTextureRect(sf::IntRect(position, size));
		framestop = 1;
		frameOrientationX = 1;
		npc->setPosition(2208, 255);
        this->referent = referent;
		Npcatack.loadFromFile("assets/attacks_sounds/deadRED.wav");
		atack.setBuffer(Npcatack);
		atack.setVolume(100);
		NpcDead.loadFromFile("assets/attacks_sounds/Ghost.wav");
		deadSound.setBuffer(NpcDead);
		deadSound.setVolume(100);
	}


	if(referent == 4){
		live = 50;
	npcstexture.loadFromFile("assets/Npcs/Gh0$t/ghost-idle.png");
    npc->setTexture(npcstexture);
    sf::Vector2i position(12, 10);
	sf::Vector2i size(33, 55);
    npc->setTextureRect(sf::IntRect(position, size));
    npc->setScale(2.f,2.f);
	npc->setPosition(2032, 495);
	this->referent = referent;
    attack = false;
    framestop = 1;   
	Npcatack.loadFromFile("assets/attacks_sounds/deadRED.wav");
	atack.setBuffer(Npcatack);
	atack.setVolume(100);
		NpcDead.loadFromFile("assets/attacks_sounds/Ghost.wav");
		deadSound.setBuffer(NpcDead);
		deadSound.setVolume(100);
	}

}

void Npcs::animation(){
	if(stopFunction != true){
		if(referent == 1){
		npc->setColor(sf::Color::Cyan);
		}else{
		npc->setColor(sf::Color::White);
		}
	}
	if (referent == 1) {
		npc1();
	}
	if (referent == 2) {
		npc2();
	}
    if (referent == 3) {
		npc3();
	}
	   if (referent == 4) {
		npc4();
	}
	 if(live == 10){
		 deadSound.play();
	 }
}

void Npcs::npc1(){
	if(live <= 0){
		dead = true;
	}
	timer =0 ;
    if(attack == false and dead != true){
	
		if (orientation == false) {
			RightWalk();
		}
		else if (orientation == true) {
			LeftWalk();
		}

	} else if(attack == true and  dead != true) {
        attack1();
    }else if(dead == true and stopFunction == false){
		Death();
	}else{

	}

}



void Npcs::npc2(){
	if(live <= 0){
		dead = true;
	}

	if(dead == false){
		timer++;
		if(timer == 100 or timer == 200 or timer == 0){
			fireanimation = false;
		}
		if (timer < 100) {
			Idle();
		}
		else if (orientation == false) {
			LeftWalk();
		}else if(orientation == true){
			RightWalk();
		}
		if(timer == 500){
			timer = 0;
		}
	}else if(dead == true and stopFunction == false){
		Death();
	}
}

void Npcs::npc3(){
	if(live <= 0){
		dead = true;
	}

if(attack == false and dead != true){
		timer++;
		if(timer == 100 or timer == 200 or timer == 0){
			fireanimation = false;
		}
		if (timer < 100) {
			Idle();
		}
		else if (timer > 100 and timer < 200) {
			LeftWalk();
		}else if(timer >= 200){
			RightWalk();
		}
		if(timer == 300){
			timer = 0;
	}
	}else if(attack == true and dead != true){
		fireanimation = false;
		attack3();
	}else if(dead == true and stopFunction == false){
		Death();
	}else{

	}

}

void Npcs::npc4(){
		if(live <= 0){
		dead = true;
	}
if(attack == false and dead != true){
		timer++;
		if(timer == 100 or timer == 200 or timer == 0){
			fireanimation = false;
		}
		if (timer < 100) {
			Idle();
		}
		else if (timer > 100 and timer < 200) {
			LeftWalk();
		}else if(timer >= 200){
			RightWalk();
		}
		if(timer == 300){
			timer = 0;
	}
	}else if(attack == true and dead != true){
		fireanimation = false;
		attack4();
	}else if(dead == true and stopFunction == false){
		Death();
		
	}else{

	}
	

}


void Npcs::RightWalk(){
	if(referent == 1){
        npc->setScale(2.f,2.f);
        if (frame >= 2) {
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
		npc->setOrigin((npc->getLocalBounds().width / 2 ) -  10,npc->getOrigin().y);
        npc->move(3,0);
	}
	if(referent == 2){
		npcstexture.loadFromFile("assets/Npcs/Wolf/hell-hound-run.png");
		npc->setTexture(npcstexture);
		npc->setScale(-2.f,2.f);
        if (frame >= 2) {
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
            sf::Vector2i position(6, 1);
            sf::Vector2i size(50, 34);
            npc->setTextureRect(sf::IntRect(position, size));
        }
        else if(framestop == 2){
            sf::Vector2i position(78, 1);
            sf::Vector2i size(50, 34);
            npc->setTextureRect(sf::IntRect(position, size));
        }
        else if (framestop == 3){
            sf::Vector2i position(146, 1);
            sf::Vector2i size(50, 34);
            npc->setTextureRect(sf::IntRect(position, size));
        }
        else if(framestop == 4){
            sf::Vector2i position(211, 1);
            sf::Vector2i size(50, 34);
            npc->setTextureRect(sf::IntRect(position, size));
        }else if(framestop == 5){
            sf::Vector2i position(281, 1);
            sf::Vector2i size(50, 34);
            npc->setTextureRect(sf::IntRect(position, size));
        }
		npc->move(16,0);
	}	
    if(referent == 3){
		npcstexture.loadFromFile("assets/Npcs/Death/fly_Left.png");
			npc->setTexture(npcstexture);
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
		if(referent == 4){
        npc->setScale(-2,2);
			npcstexture.loadFromFile("assets/Npcs/Gh0$t/ghost-shriek.png");
			npc->setTexture(npcstexture);
			sf::Vector2i position(17, 10);
			sf::Vector2i size(36, 51);
			npc->setTextureRect(sf::IntRect(position, size));
			npc->move(10,0);
    }


}

void Npcs::LeftWalk(){
    if(referent == 1){
        npc->setScale(-2.f,2.f);
        if (frame >= 2) {
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
		npc->setOrigin((npc->getLocalBounds().width / 2 ) +  30,npc->getOrigin().y);
        npc->move(-3,0);
    }

	if(referent == 2){
		npcstexture.loadFromFile("assets/Npcs/Wolf/hell-hound-run.png");
		npc->setScale(2.f,2.f);
        if (frame >= 2) {
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
            sf::Vector2i position(6, 1);
            sf::Vector2i size(50, 34);
            npc->setTextureRect(sf::IntRect(position, size));
        }
        else if(framestop == 2){
            sf::Vector2i position(78, 1);
            sf::Vector2i size(50, 34);
            npc->setTextureRect(sf::IntRect(position, size));
        }
        else if (framestop == 3){
            sf::Vector2i position(146, 1);
            sf::Vector2i size(50, 34);
            npc->setTextureRect(sf::IntRect(position, size));
        }
        else if(framestop == 4){
            sf::Vector2i position(211, 1);
            sf::Vector2i size(50, 34);
            npc->setTextureRect(sf::IntRect(position, size));
        }else if(framestop == 5){
            sf::Vector2i position(281, 1);
            sf::Vector2i size(50, 34);
            npc->setTextureRect(sf::IntRect(position, size));
        }
		npc->move(-16,0);
	}	

    if(referent == 3){
        npc->setScale(2,2);
			npcstexture.loadFromFile("assets/Npcs/Death/fly_Left.png");
			npc->setTexture(npcstexture);

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
 
	if(referent == 4){
        npc->setScale(2,2);
			npcstexture.loadFromFile("assets/Npcs/Gh0$t/ghost-shriek.png");
			npc->setTexture(npcstexture);
			sf::Vector2i position(17, 10);
			sf::Vector2i size(36, 51);
			npc->setTextureRect(sf::IntRect(position, size));
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

  if (frame >= 2) {
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
    	atack.play();
    	Bullet *bu = new Bullet();
				bu->attacksprite->setScale(-1.3f, 1.3f);
				bu->attacksprite->setPosition(npc->getPosition().x + 35,npc->getPosition().y + 33);

			if(distance < 0){
					bu->orientation = true;
				}
				if(distance > 0){
					bu->orientation = false;
					bu->attacksprite->setScale(bu->attacksprite->getScale().x * -1,bu->attacksprite->getScale().y);
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

	npcstexture.loadFromFile("assets/Npcs/Death/Attack.png");
		npc->setTexture(npcstexture);


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
				atack.play();
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
void Npcs::attack4(){

	if(distance < 0){
		npc->setScale(1, 1);
	}
	if(distance > 0){
		npc->setScale(-1, 1);
	}

	npcstexture.loadFromFile("assets/Npcs/Death/Attack.png");
		npc->setTexture(npcstexture);


		if (frame >= 5) {
			frame = 0;
			if (framestop >= 7) {
				framestop = 1;

			} else {
				framestop++;
			}
		} else {
			frame++;
		}
		npcstexture.loadFromFile("assets/Npcs/Gh0$t/ghost-idle.png");
			npc->setTexture(npcstexture);
			npc->setScale(2,2);
			if (frame >= 5) {
				frame = 0;
				if (framestop == 7) {
					framestop = 1;

				} else {
					framestop++;
				}
			} else {
				frame++;
			}
			
				if (framestop == 1) {
					sf::Vector2i position(12, 10);
					sf::Vector2i size(33, 55);
					npc->setTextureRect(sf::IntRect(position, size));
				}

				if (framestop == 2) {
					sf::Vector2i position(84, 10);
					sf::Vector2i size(33, 55);
					npc->setTextureRect(sf::IntRect(position, size));
				}

				if (framestop == 3) {
					sf::Vector2i position(143, 10);
					sf::Vector2i size(33, 55);
					npc->setTextureRect(sf::IntRect(position, size));
				}
				if (framestop == 4) {
					sf::Vector2i position(204, 10);
					sf::Vector2i size(33, 55);
					npc->setTextureRect(sf::IntRect(position, size));
				}
				if (framestop == 5) {
					sf::Vector2i position(264, 10);
					sf::Vector2i size(33, 55);
					npc->setTextureRect(sf::IntRect(position, size));
				}
				if (framestop == 6) {
					sf::Vector2i position(333, 10);
					sf::Vector2i size(33, 55);
					npc->setTextureRect(sf::IntRect(position, size));
				}
				if (framestop ==7) {
					atack.play();
					sf::Vector2i position(399, 10);
					sf::Vector2i size(33, 55);
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

			if(distance < 0){
					npc->setScale(2,2);

				}
				if(distance > 0){
					npc->setScale(-2,2);
				}
			int x = shots.size();

			bool check = false;

			if (check == false) {
				for (int j = 0; j < x; j++) {
						shots[j].bullettexture[0]->loadFromFile("assets/Shoots/2/2.png");
						shots[j].attacksprite->setTexture(*shots[j].bullettexture[0]);
						shots[j].attacksprite->setColor(sf::Color(0,0,58,255));

				}
				check = true;
			}

			int tam = shots.size();

				if(tam >= 20){
					pop_attack();
				}
}
	


void Npcs::Idle(){
	if(referent == 2){
		npcstexture.loadFromFile("assets/Npcs/Wolf/hell-hound-idle.png");
		npc->setScale(2.f,2.f);
        if (frame >= 2) {
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
            sf::Vector2i position(64, 1);
            sf::Vector2i size(55, 33);
            npc->setTextureRect(sf::IntRect(position, size));
        }
        else if(framestop == 2){
            sf::Vector2i position(128, 1);
            sf::Vector2i size(55, 33);
            npc->setTextureRect(sf::IntRect(position, size));
        }
        else if (framestop == 3){
            sf::Vector2i position(192, 1);
            sf::Vector2i size(55, 33);
            npc->setTextureRect(sf::IntRect(position, size));
        }
        else if(framestop == 4){
            sf::Vector2i position(256, 1);
            sf::Vector2i size(55, 33);
            npc->setTextureRect(sf::IntRect(position, size));
        }else if(framestop == 5){
            sf::Vector2i position(320, 1);
            sf::Vector2i size(55, 33);
            npc->setTextureRect(sf::IntRect(position, size));
        }
	}	

	if(referent == 3){
	npcstexture.loadFromFile("assets/Npcs/Death/Idle.png");
			npc->setTexture(npcstexture);
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

	if(referent ==4){
		npcstexture.loadFromFile("assets/Npcs/Gh0$t/ghost-idle.png");
			npc->setTexture(npcstexture);
			npc->setScale(2,2);
			if (frame >= 5) {
				frame = 0;
				if (framestop == 7) {
					framestop = 1;

				} else {
					framestop++;
				}
			} else {
				frame++;
			}
			
				if (framestop == 1) {
					sf::Vector2i position(12, 10);
					sf::Vector2i size(33, 55);
					npc->setTextureRect(sf::IntRect(position, size));
				}

				if (framestop == 2) {
					sf::Vector2i position(84, 10);
					sf::Vector2i size(33, 55);
					npc->setTextureRect(sf::IntRect(position, size));
				}

				if (framestop == 3) {
					sf::Vector2i position(143, 10);
					sf::Vector2i size(33, 55);
					npc->setTextureRect(sf::IntRect(position, size));
				}
				if (framestop == 4) {
					sf::Vector2i position(204, 10);
					sf::Vector2i size(33, 55);
					npc->setTextureRect(sf::IntRect(position, size));
				}
				if (framestop == 5) {
					sf::Vector2i position(264, 10);
					sf::Vector2i size(33, 55);
					npc->setTextureRect(sf::IntRect(position, size));
				}
				if (framestop == 6) {
					sf::Vector2i position(333, 10);
					sf::Vector2i size(33, 55);
					npc->setTextureRect(sf::IntRect(position, size));
				}
				if (framestop ==7) {
					sf::Vector2i position(399, 10);
					sf::Vector2i size(33, 55);
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

	if(referent == 4){
        	if(herobobj->hero->getPosition().x - npc->getPosition().x <= 20 and herobobj->hero->getPosition().x - npc->getPosition().x > -200 ){
				if(herobobj->hero->getPosition().y - npc->getPosition().y <= 60 and herobobj->hero->getPosition().y - npc->getPosition().y > -90 ){
					distance = herobobj->hero->getPosition().x - npc->getPosition().x;
					attack = true;

				}
				else{
					attack = false;
				}
        	}else{
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


void Npcs::colision(Hero * heroobj, bool  * GameOver,int  level){

	if(level == 1){
		int tam = shots.size();

		for(int i  = 0; i < tam ; i++){
			if(referent == 3){

				if(heroobj->hero->getGlobalBounds().intersects(shots[i].attacksprite->getGlobalBounds())){
					heroobj->live -= 50;
					shots[i].attacksprite->setColor(sf::Color::Transparent);
				}
			}else{

				if(heroobj->hero->getGlobalBounds().intersects(shots[i].attacksprite->getGlobalBounds())){
					heroobj->live -= 20;
					shots[i].attacksprite->setColor(sf::Color::Transparent);
				}
			}
		}
		
		if(referent == 2){
			//heroboud para ajustar a colisao com as dimensoes do sprite
			sf::FloatRect heroBound = heroobj->hero->getGlobalBounds();
			heroBound.height -= 20.f;
			heroBound.width -=50.f;

			if(npc->getScale().x < 0){
				heroBound.left += 50.f;
			
			if(heroBound.intersects(npc->getGlobalBounds()) and npc->getColor() != sf::Color::Transparent){
				heroobj->live -= 20;
			}

			}else{
				//heroBound.left -= 50.f;
			if(heroBound.intersects(npc->getGlobalBounds()) and npc->getColor() != sf::Color::Transparent){
				heroobj->live -= 20;
			}
			}
		}
	}else if(level == 2){
				int tam = shots.size();

		for(int i  = 0; i < tam ; i++){
			if(referent == 3){

				if(heroobj->hero->getGlobalBounds().intersects(shots[i].attacksprite->getGlobalBounds())){
					heroobj->live -= 70;
					shots[i].attacksprite->setColor(sf::Color::Transparent);
				}
			}else{

				if(heroobj->hero->getGlobalBounds().intersects(shots[i].attacksprite->getGlobalBounds())){
					heroobj->live -= 40;
					shots[i].attacksprite->setColor(sf::Color::Transparent);
				}
			}
		}
		
		if(referent == 2){
			//heroboud para ajustar a colisao com as dimensoes do sprite
			sf::FloatRect heroBound = heroobj->hero->getGlobalBounds();
			heroBound.height -= 20.f;
			heroBound.width -=50.f;

			if(npc->getScale().x < 0){
				heroBound.left += 50.f;
			
			if(heroBound.intersects(npc->getGlobalBounds()) and npc->getColor() != sf::Color::Transparent){
				heroobj->live -= 40;
			}

			}else{
				//heroBound.left -= 50.f;
			if(heroBound.intersects(npc->getGlobalBounds()) and npc->getColor() != sf::Color::Transparent){
				heroobj->live -= 40;
			}
			}
		}

	}
}

void Npcs::Death(){

	if(referent == 1){

		static sf::Clock clock;
		static sf::Time timepassado;

		timepassado = clock.getElapsedTime();


 		if (frame >= 15) {
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
            sf::Vector2i position(13, 74);
            sf::Vector2i size(38, 49);
            npc->setTextureRect(sf::IntRect(position, size));
        }
        else if(framestop == 2){
            sf::Vector2i position(85, 74);
            sf::Vector2i size(38, 49);
            npc->setTextureRect(sf::IntRect(position, size));
        }
        else if (framestop == 3){
            sf::Vector2i position(144, 74);
            sf::Vector2i size(38, 49);
            npc->setTextureRect(sf::IntRect(position, size));
        }
        else if(framestop == 4){
            sf::Vector2i position(209, 74);
            sf::Vector2i size(38, 49);
            npc->setTextureRect(sf::IntRect(position, size));
        }else if(framestop == 5){
            sf::Vector2i position(261, 74);
            sf::Vector2i size(38, 49);
            npc->setTextureRect(sf::IntRect(position, size));
        }else if(framestop == 6){
            sf::Vector2i position(333, 74);
            sf::Vector2i size(38, 49);
            npc->setTextureRect(sf::IntRect(position, size));
        }else if(framestop == 7){
            sf::Vector2i position(405, 74);
            sf::Vector2i size(38, 49);
            npc->setTextureRect(sf::IntRect(position, size));

        }else if(framestop == 8){
            sf::Vector2i position(466, 74);
            sf::Vector2i size(38, 49);
            npc->setTextureRect(sf::IntRect(position, size));
			stopFunction = true;
			npc->setColor(sf::Color::Transparent);
        }

		

	}

	if(referent == 2){
			stopFunction = true;
			npc->setColor(sf::Color::Transparent);
	}

	if(referent == 3){
		static int framestop = 0;
		npcstexture.loadFromFile("assets/Npcs/Death/dead.png");
			npc->setTexture(npcstexture);
			npc->setScale(2,2);
			if (frame >= 2) {
				frame = 0;
				if (framestop == 10) {
					framestop = 1;

				}  else {
					framestop++;
				}
				} else {
				frame++;
				}

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
					
				}

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
					stopFunction = true;
					npc->setColor(sf::Color::Transparent);
				}

			}if(referent == 4){
			npcstexture.loadFromFile("assets/Npcs/Gh0$t/ghost-appears.png");
			npc->setTexture(npcstexture);
			npc->setScale(2,2);

			if (frame >= 5) {
				frame = 0;
				if (framestop == 7) {
					framestop = 1;

				} else {
					framestop++;
				}
			} else {
				frame++;
			}
			
				if (framestop == 1) {
					sf::Vector2i position(335, 2);
					sf::Vector2i size(36, 46);
					npc->setTextureRect(sf::IntRect(position, size));
				}

				if (framestop == 2) {
					sf::Vector2i position(84, 2);
					sf::Vector2i size(36,46);
					npc->setTextureRect(sf::IntRect(position, size));
				}

				if (framestop == 3) {
					sf::Vector2i position(269, 2);
					sf::Vector2i size(36,46);
					npc->setTextureRect(sf::IntRect(position, size));
				}
				if (framestop == 4) {
					sf::Vector2i position(206, 2);
					sf::Vector2i size(36,46);
					npc->setTextureRect(sf::IntRect(position, size));
				}
				if (framestop == 5) {

					sf::Vector2i position(141, 2);
					sf::Vector2i size(36,46);
					npc->setTextureRect(sf::IntRect(position, size));
				}
				if (framestop == 6) {
					sf::Vector2i position(86, 2);
					sf::Vector2i size(36,46);
					npc->setTextureRect(sf::IntRect(position, size));
				}
				if (framestop ==7) {

					sf::Vector2i position(22, 2);
					sf::Vector2i size(36,46);
					npc->setTextureRect(sf::IntRect(position, size));
					stopFunction = true;
					npc->setColor(sf::Color::Transparent);
				}
			}
}









