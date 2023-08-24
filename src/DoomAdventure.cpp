#include "Doom.hpp"

DoomAdventure::DoomAdventure() {
	window = make_shared<sf::RenderWindow>(
			//criando a janela com ponteiro inteligente
			sf::VideoMode(1280, 720), "Doom Adventure",
			sf::Style::Titlebar | sf::Style::Close);
	heroobj = new Hero();
	npc1 = new Npcs(1);
	npc3 = new Npcs(3);
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
	window->draw(*npc3->npc);
	window->draw(*npc1->npc);

	int x = heroobj->shots.size();

	for(int i = 0; i < x; i++){
		heroobj->shots[i].Orientation(30);
		window->draw(*heroobj->shots[i].attacksprite);
	}

	int y = npc3->shots.size();

		for(int i = 0; i < y; i++){
			npc3->shots[i].Orientation(10);
			window->draw(*npc3->shots[i].attacksprite);
		}

	int z = npc1->shots.size();

	for(int i = 0; i < z; i++){
			npc1->shots[i].Orientation(30);
			window->draw(*npc1->shots[i].attacksprite);
		}

	window->display();

}

void DoomAdventure::game() {
	npc3->animation();
	npc3->testAproxim(heroobj);
	npc1->animation();
	npc1->testAproxim(heroobj);
	heroobj->attack();
	heroobj->shotstimer++;
	heroobj->animation();
	
	
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

	heroobj = NULL;

}


