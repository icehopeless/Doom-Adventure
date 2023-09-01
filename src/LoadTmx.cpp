#include "Doom.hpp"

void DoomAdventure::update(){

	mYSt2.loadFromFile("assets/Background/night-town-background-previewx1.png");
	r2.setTexture(mYSt2,true);
	r2.setColor(sf::Color::White);
	r2.setScale(1,1);


	mYSt3.loadFromFile("assets/Menu/02.png");
	r3.setTexture(mYSt3,true);
	r3.setColor(sf::Color::Red);
	r3.setScale(3,3);
	static sf::Vector2i position(1,17);
	static sf::Vector2i size(33,30);
	r3.setTextureRect(sf::IntRect(position,size));

	view->setSize(window->getSize().x / 2, window->getSize().y  / 2);

	if(view->getCenter().x == window->getSize().x /2){
		if(view->getCenter().y == window->getSize().y /2){
			view->setCenter(320,heroobj->hero->getPosition().y);
		}
	}

	if(heroobj->hero->getPosition().x > 320 and heroobj->hero->getPosition().x < 2240){
		view->setCenter(heroobj->hero->getPosition());
		r1.setPosition(heroobj->hero->getPosition().x + 100,heroobj->hero->getPosition().y - 200);
		r2.setPosition(heroobj->hero->getPosition().x - 360, heroobj->hero->getPosition().y - 400);
		r3.setPosition(heroobj->hero->getPosition().x + 200,heroobj->hero->getPosition().y - 100);
	}else if(heroobj->hero->getPosition().y < 180 and heroobj->hero->getPosition().x < 2240){
		r2.setPosition(0,-300);
		r3.setPosition(0,-300);
	}else if(heroobj->hero->getPosition().x > 2000){
		view->setCenter(view->getCenter().x,heroobj->hero->getPosition().y);
		r1.setPosition(2316,heroobj->hero->getPosition().y - 200);
		r3.setPosition(2416,heroobj->hero->getPosition().y - 100);
		r2.setPosition(1856, heroobj->hero->getPosition().y - 400);
	}else if(heroobj->hero->getPosition().x > 2240 ){
			r2.setPosition(heroobj->hero->getPosition().x, heroobj->hero->getPosition().y);
			r3.setPosition(heroobj->hero->getPosition().x, heroobj->hero->getPosition().y);
	}else{
		view->setCenter(view->getCenter().x,heroobj->hero->getPosition().y);
		r1.setPosition(420,heroobj->hero->getPosition().y - 200);
		r3.setPosition(520,heroobj->hero->getPosition().y - 100);
		r2.setPosition(0,0);
	}


	if(heroobj->hero->getPosition().x < 0){
		heroobj->hero->setPosition(0,heroobj->hero->getPosition().y);
	}
	if(heroobj->hero->getPosition().x > 2472){
		heroobj->hero->setPosition(2472,heroobj->hero->getPosition().y);
	}



	if(heroobj->hero->getPosition().y > 0){
	if (layerZero->getTile((int)(heroobj->hero->getPosition().x + heroobj->hero->getGlobalBounds().width / 2) / 32,
		(int)(heroobj->hero->getPosition().y + heroobj->hero->getGlobalBounds().height) / 32).ID) {
			// Colidiu / Aplica gravidade
	}

	p = layerZero->getTile((int)(heroobj->hero->getPosition().x + heroobj->hero->getGlobalBounds().width / 2) / 32,
		(int)(heroobj->hero->getPosition().y + (heroobj->hero->getGlobalBounds().height  / 2) + 30) / 32).ID;
		

	}
	window->setView(*view);
}


