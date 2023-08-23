#include "Doom.hpp"

Npcs::Npcs(int referent){
    npc = make_shared<sf::Sprite>();
    npcstexture.loadFromFile("assets/Npcs/MeioTermo/spritesheet.png");
    npc->setTexture(npcstexture);
    sf::Vector2i position(0, 180);
	sf::Vector2i size(67, 60);
    npc->setTextureRect(sf::IntRect(position, size));
    npc->setScale(2.f,2.f);
    

}

void Npcs::animation(){
if (referent == 1) {
		npc1();
	}
}

void Npcs::npc1(){
   /*if (frame >= 5) {
				frame = 0;
				if (framestop == 10) {
					framestop = 1;

				} else if (framestop == 10) {
					framestop = 7;

				} else {
					framestop++;
				}
			} else {
				frame++;
			}

    if(framestop == 1){
        sf::Vector2i position(0, 0);
		sf::Vector2i size(67, 53);
        npc->setTextureRect(sf::IntRect(position, size));
    }
    else if(framestop == 2){
        sf::Vector2i position(70, 0);
		sf::Vector2i size(67, 53);
        npc->setTextureRect(sf::IntRect(position, size));
    }
    else if (framestop == 3){
        sf::Vector2i position(60, 0);
		sf::Vector2i size(67, 53);
        npc->setTextureRect(sf::IntRect(position, size));
    }
    else if(framestop == 4){
        sf::Vector2i position(57, 0);
		sf::Vector2i size(67, 53);
        npc->setTextureRect(sf::IntRect(position, size));
    }
    */
        
    
}