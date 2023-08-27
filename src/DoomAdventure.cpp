#include "Doom.hpp"

DoomAdventure::DoomAdventure() {
	window = make_shared<sf::RenderWindow>(
			//criando a janela com ponteiro inteligente
			sf::VideoMode(1280, 720), "Doom Adventure",
			sf::Style::Titlebar | sf::Style::Close);
	GameOver = false;
	KeyIntro = true;
	KeyGame = false;
	KeyMenu = false;
	KeyDown = false;
 	KeyUp = false;
	heroobj = new Hero();
	npc1 = new Npcs(1);
	npc3 = new Npcs(3);
	npc4 = new Npcs(4);
	time = 0;
	background = make_shared<sf::Sprite>();
	window->setFramerateLimit(60);

	rain.openFromFile("assets/sound/rain.wav");
	static bool test = false;
	if(test == false){
		rain.play();
		rain.setVolume(50);
		test = true;
	}

		if(chekedaudio == false){
		musicGame.openFromFile("assets/sound/bit.wav");
		musicGame.setLoop(true);
		musicGame.setVolume(100);
		musicGame.play();
		chekedaudio = true;
	}

}

void DoomAdventure::Introduction(shared_ptr<sf::RenderWindow> window){
	static 	float i = 0;
	static float j = 0;

	timepassado = clock.getElapsedTime();
	time = timepassado.asSeconds();

	if(time == 0){
			mYSt.loadFromFile("rz/safeimagekit-pixel-art.png");
			r1.setTexture(mYSt);
			r1.setPosition(390, 60);
	}

		if (time == 3) {
			i = 255;
		} else if (time > 3 and personagenslibery == false and i != 0) {
			i--;
			r1.setColor(sf::Color(255, 255, 255, i));
			if (i < 0) {
				r1.setColor(sf::Color::Transparent);
				i = 0;
			}
		} else if (time < 3 and i < 255) {
			i = i + 1;
			r1.setColor(sf::Color(255, 255, 255, i));
		}

		if (time == 5) {
			personagenslibery = true;
		}

		if (time >= 6 and time < 10) {
			if (personagenslibery == true) {
				mYSt.loadFromFile("rz/ghost-idle.png");
				r1.setTexture(mYSt);
				sf::Vector2i position(15, 12);
				sf::Vector2i size(38, 55);
				r1.setTextureRect(sf::IntRect(position, size));
				r1.setColor(sf::Color(255, 0, 255, j));
				
				r1.setScale(6, 6);
				r1.setPosition(200, 160);
				
				name.loadFromFile("rz/Bel.png");
				n1.setTexture(name);
				n1.setPosition(200, 460);
				n1.setColor(sf::Color(255, 0, 255, j));

				mYSt2.loadFromFile("rz/spritesheet.png");
				r2.setTexture(mYSt2);
				r2.setTextureRect(sf::IntRect(266, 194, 57, 52));
				r2.setScale(6, 6);
				r2.setPosition(500, 160);
				r2.setColor(sf::Color(0, 255, 255, j));

				name2.loadFromFile("rz/Ice.png");
				n2.setTexture(name2);
				n2.setPosition(600, 460);

				n2.setColor(sf::Color(255, 0, 255, j));

				mYSt3.loadFromFile("rz/Idle.png");
				r3.setTexture(mYSt3);
				r3.setTextureRect(sf::IntRect(720, 7, 60, 71));
				r3.setScale(4, 4);
				r3.setPosition(850, 160);
				r3.setColor(sf::Color(255, 0, 255, j));

				name3.loadFromFile("rz/Ws.png");
				n3.setTexture(name3);
				n3.setPosition(950, 460);
				n3.setColor(sf::Color(255, 255, 255, j));

				n1.setScale(0.4, 0.4);
				n2.setScale(0.4, 0.4);
				n3.setScale(0.4, 0.4);

				if (j < 255 and time >= 6 and personagenslibery == true) {
					j++;
					i = 0;
				}

				if (j == 254) {
					personagenslibery = false;
					j = 255;
				}

			}
			
		}

		if (time == 10) {
			r1.setColor(sf::Color::Transparent);
			r2.setColor(sf::Color::Transparent);
			r3.setColor(sf::Color::Transparent);
			n1.setColor(sf::Color::Transparent);
			n2.setColor(sf::Color::Transparent);
			n3.setColor(sf::Color::Transparent);

		}
		if(time > 9){
			r1.move(9, 0);
		}

		if (frame >= 2 and time > 9) {
			r1.setColor(sf::Color::White);
			r1.setScale(-6, 6);

			frame = 0;

			if (Animation < 5) {
				if (Animation == 1) {
					mYSt.loadFromFile("rz/hell-hound-run.png");
					r1.setTexture(mYSt);
					r1.setTextureRect(sf::IntRect(6, 1, 60, 34));
				}
				if (Animation == 2) {
					mYSt.loadFromFile("rz/hell-hound-run.png");
					r1.setTexture(mYSt);
					r1.setTextureRect(sf::IntRect(78, 1, 60, 34));
				}
				if (Animation == 3) {
					mYSt.loadFromFile("rz/hell-hound-run.png");
					r1.setTexture(mYSt);
					r1.setTextureRect(sf::IntRect(146, 1, 60, 34));
				}
				if (Animation == 4) {
					mYSt.loadFromFile("rz/hell-hound-run.png");
					r1.setTexture(mYSt);
					r1.setTextureRect(sf::IntRect(211, 1, 60, 34));
				}
				if (Animation == 5) {
					mYSt.loadFromFile("rz/hell-hound-run.png");
					r1.setTexture(mYSt);
					r1.setTextureRect(sf::IntRect(281, 1, 60, 34));
				}
				Animation++;
			} else {
				Animation = 1;
			}
		} else {
			frame++;
		}

		if (time > 15) {
			r1.setColor(sf::Color::Transparent);
			KeyIntro = false;
			KeyMenu = true;
		}

	window->draw(r1);
	window->draw(r2);
	window->draw(r3);
	window->draw(n1);
	window->draw(n2);
	window->draw(n3);

	
}

void DoomAdventure::Menu(){
	bgtexutre.loadFromFile("assets/Background/back.jpg");
	background->setTexture(bgtexutre);
	logotexture.loadFromFile("assets/Background/Doom.png");
	logo.setTexture(logotexture);
	logo.setScale(1.2,1.2);
	logo.setPosition(0,0);
	logo.setColor(sf::Color::White);
	static float f =0;
	static int framestop = 0;
	static int i = 0;

	if (frame >= 2) {
		frame = 0;
		if (framestop == 3) {

			framestop = 0;
		} else {
			framestop++;
		}
	}

	frame++;
	for (int i = 0; i < 4; i++) {
		stringstream ss;
		ss << "assets/Hero/Gunner/Gunner_Idle_" << i + 1 << ".png";
		texturePersona[i].loadFromFile(ss.str());
	}
	Persona.setTexture(texturePersona[framestop], true);
	Persona.setScale(-10,10);
	Persona.setPosition(1360,0);


	mYSt2.loadFromFile("assets/Menu/buttons/Buttons.png");
	r2.setTexture(mYSt2);
	sf::Vector2i size1(149,73);
	sf::Vector2i position1(189,129);	
	r2.setTextureRect(sf::IntRect(position1,size1));


	mYSt3.loadFromFile("assets/Menu/buttons/Buttons.png");
	r3.setTexture(mYSt3);
	sf::Vector2i size2(149,73);
	sf::Vector2i position2(349,129);	
	r3.setTextureRect(sf::IntRect(position2,size2));

	r2.setScale(3,3);
	r3.setScale(3,3);

	r2.setPosition(100,300);
	r3.setPosition(100,450);



	if(f < 255){
		f = f + 1.8;
		logo.setColor(sf::Color(255,255,255,f));
		Persona.setColor(sf::Color(255,255,255,f));
		background->setColor(sf::Color(255,255,255,f));

	}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
			KeyDown = true;
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
			KeyUp = true;
		}

	if(KeyDown == true){
		i++;
		if(i >= 3){
			i = 2;
		}
		KeyDown = false;
	}

	if(KeyUp == true){
		i--;
		if(i < 1){
			i = 1;
		}
		KeyUp = false;
	}

	if(i == 1){
			r2.setColor(sf::Color(0,255,0,f));
			r3.setColor(sf::Color(255,255,255,f));
		}
		else if(i == 2){
			r3.setColor(sf::Color(0,255,0,f));
			r2.setColor(sf::Color(255,255,255,f));
		}else{
			r2.setColor(sf::Color(255,255,255,f));
			r3.setColor(sf::Color(255,255,255,f));
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
		if(i == 1){
			KeyMenu= false;
			KeyGame = true;
		}
		if(i == 2){
			window->close();
		}
	}


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

	if(KeyIntro == true){
		Introduction(window);
	}
	if(KeyMenu == true){
		window->draw(*background);
		window->draw(Persona);
		window->draw(logo);
		window->draw(r2);
		window->draw(r3);
	}
	if(KeyGame == true){
		window->draw(*heroobj->hero);
		window->draw(*npc1->npc);
		window->draw(*npc2->npc);
		window->draw(*npc3->npc);
		window->draw(*npc4->npc);
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

			
		int r = npc4->shots.size();

		for(int i = 0; i < r; i++){
			npc4->shots[i].Orientation(10);
			window->draw(*npc4->shots[i].attacksprite);
		}

		int z = npc1->shots.size();

		for(int i = 0; i < z; i++){
				npc1->shots[i].Orientation(30);
				window->draw(*npc1->shots[i].attacksprite);
			}
	}
	window->display();

}

void DoomAdventure::game() {
	npc3->animation();
	npc3->testAproxim(heroobj);
	npc4->animation();
	npc4->testAproxim(heroobj);
	npc1->animation();
	npc1->testAproxim(heroobj);
	npc2->animation();
	heroobj->attack();
	heroobj->shotstimer++;
	heroobj->animation();
	
	
}

void DoomAdventure::run() {
	while (window->isOpen()) {
		draw();
		events();
		if(KeyMenu == true){
			rain.setLoop(true);
			Menu();
		}
		if(GameOver == false and KeyGame == true){
			rain.stop();
			musicGame.stop();
			game();
			heroobj->colision(npc1->npc,&npc1->live);
			heroobj->colision(npc2->npc,&npc2->live);
			heroobj->colision(npc3->npc,&npc3->live);
			heroobj->colision(npc4->npc,&npc4->live);
			npc1->colision(heroobj,&GameOver);
			npc2->colision(heroobj, &GameOver);
			npc3->colision(heroobj,&GameOver);
			npc4->colision(heroobj,&GameOver);
		}
		
	}
}

DoomAdventure::~DoomAdventure(){
	delete heroobj;
	heroobj = NULL;

}


