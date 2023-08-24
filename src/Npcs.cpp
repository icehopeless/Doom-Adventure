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
	

}

void Npcs::animation(){
if (referent == 1) {
		npc1();
	}
if (referent == 2) {
		npc2();
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
}

void Npcs::LeftWalk(){
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

void Npcs::testAproxim(Hero * herobobj){
    if(referent == 1){
        if(herobobj->hero->getPosition().x - npc->getPosition().x <= 20 and herobobj->hero->getPosition().x - npc->getPosition().x > -200 ){
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
    

}
void Npcs::pop_attack() {
	int tam = shots.size();

	for(int i  = 0; i < tam ; i++){
		shots.pop_back();
	}	
}










