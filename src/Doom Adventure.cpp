#include "Doom.hpp"

DoomAdventure::DoomAdventure() {
	window = make_shared<sf::RenderWindow>(
			//criando a janela com ponteiro inteligente
			sf::VideoMode(1280, 720), "Doom Adventure",
			sf::Style::Titlebar | sf::Style::Close);
	heroobj = new Hero();
	villian = new Villain(1);
	window->setFramerateLimit(60);
}

Bullet::Bullet() {
	frame = 0;
	attacksprite = make_shared<sf::Sprite>();
	for (auto i = 0; i < 4; i++) {
		bullettexture[i] = make_shared<sf::Texture>();
	}
	orientation = false;
}
Bullet::~Bullet() {

}
//variavel de controle da orientação
void Bullet::Orientation( int vel){
	orientation == true ? attacksprite->move(-vel,0) : attacksprite->move(vel,0);
}
void Bullet::animation(){

	if(frame < 4){
		attacksprite->setTexture(*bullettexture[frame]);
		frame++;
	}else{
		frame = 0;
	}

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
	window->draw(*villian->Vilion);
	window->draw(*npc1->npc);

	int x = heroobj->shots.size();

	for(int i = 0; i < x; i++){
		heroobj->shots[i].Orientation(30);
		window->draw(*heroobj->shots[i].attacksprite);
	}

	int y = villian->shots.size();

		for(int i = 0; i < y; i++){
			villian->shots[i].Orientation(10);
			window->draw(*villian->shots[i].attacksprite);
		}
	window->display();

}

void DoomAdventure::game() {
	villian->animation();
	villian->testAproxim(heroobj);
	heroobj->animation();
	heroobj->attack();
	heroobj->shotstimer++;
	npc1->animation();
	
}

void DoomAdventure::run() {
	while (window->isOpen()) {
		draw();
		events();
		game();
	}
}

DoomAdventure::~DoomAdventure(){
	delete heroobj;
	delete villian;
	heroobj = NULL;
	villian = NULL;
}
