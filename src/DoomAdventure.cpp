#include "Doom.hpp"

DoomAdventure::DoomAdventure() {
	window = make_shared<sf::RenderWindow>(
			//criando a janela com ponteiro inteligente
			sf::VideoMode(1280, 720), "Doom Adventure",
			sf::Style::Titlebar | sf::Style::Close);


	GameOver = false;
	KeyIntro = false;
	KeyGame = true;
	KeyMenu = false;
	KeyDown = false;
 	KeyUp = false;
	level1 = false;
	level2 = false;
	level3 = false;
	heroobj = new Hero();
	npcA1 = new Npcs(1);
	npcA2 = new Npcs(1);
	npcB1 = new Npcs(2);
	npcB2 = new Npcs(2);
	npcC1 = new Npcs(4);
	npcC2 = new Npcs(4);
	npcC3 = new Npcs(4);
	villain = new Villain(1);
	time = 0;
	level = 1;
	view = new sf::View(sf::FloatRect(0,0,window->getSize().x / 2, window->getSize().y  / 2));
	background = make_shared<sf::Sprite>();
	map_2 = make_shared<tmx::Map>();
	villain->live = -1;
	window->setFramerateLimit(60);
	npcC1->live = -1;
	npcC2->live = -1;
	npcC3->live = -1;
	rain.openFromFile("assets/sound/rain.wav");
	static bool test = false;
	npcA1->npc->setPosition(450, 595);
	npcA2->npc->setPosition(1648, 340);
	npcA2->orientation = false;
	npcB1->npc->setPosition(1000, 475);
	npcB2->npc->setPosition(344, 228);
	checkpoint.setSize(sf::Vector2f(60,100));
	checkpoint.setPosition(2504,290);
	skiplevel = false;
	//transitionTexture.loadFromFile("assets/Background/transition.png");
	//transition.setTexture(transitionTexture);
	transition.setColor(sf::Color::Transparent);
	
	if(test == false){
		rain.play();
		rain.setVolume(50);
		test = true;
	}

	if(chekedaudio == false){
		musicGame.openFromFile("assets/sound/menu.wav");
		musicGame.setLoop(true);
		musicGame.setVolume(1000);
		musicGame.play();
		chekedaudio = true;
	}

	if (map.load("maps/map.tmx")) {
		layerDraw = new MapLayer(map, 0);
		layerLeft = new MapLayer(map, 3);
		layerRight = new MapLayer(map, 1);
		layerUp = new MapLayer(map, 2);
		layerDown = new MapLayer(map, 4);
	}

	if(map_2->load("maps/map2.tmx")){
			layerDraw_2 = new MapLayer(*map_2, 0);
			layerLeft_2 = new MapLayer(*map_2, 3);
			layerRight_2 = new MapLayer(*map_2, 2);
			layerUp_2 = new MapLayer(*map_2, 4);
			layerDown_2 = new MapLayer(*map_2, 1);
	}
	
}

void DoomAdventure::Introduction(shared_ptr<sf::RenderWindow> window){
	static float i = 0;
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
			r1.setPosition(0,500);
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
	transition.setColor(sf::Color::Transparent);
	view->setSize(window->getSize().x, window->getSize().y);
	view->setCenter(window->getSize().x /2, window->getSize().y /2);
	window->setView(*view);
	bgtexutre.loadFromFile("assets/Background/back.jpg");
	background->setTexture(bgtexutre);
	logotexture.loadFromFile("assets/Background/Doom.png");
	logo.setTexture(logotexture);
	logo.setScale(1.2,1.2);
	logo.setPosition(0,0);
	logo.setColor(sf::Color::White);
	static float f =0;
	static int framestop = 0;


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
			level = 1;
			Restart();
			KeyMenu= false;
			KeyGame = true;
			musicGame.stop();
			rain.stop();

		}
		if(i == 2){
			window->close();
		}
	}


	if(chekedaudio == false){
		musicGame.openFromFile("assets/sound/menu.wav");
		musicGame.setLoop(true);
		musicGame.setVolume(1000);
		musicGame.play();
		chekedaudio = true;
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				heroobj->ControlSkip--;
		}
	}
}
void DoomAdventure::drawGame() {

	window->draw(r2);
	if(level1 == true){
		window->draw(*layerDraw);
		window->draw(*heroobj->hero);
		window->draw(*npcA1->npc);
		window->draw(*npcA2->npc);
		window->draw(*npcB1->npc);
		window->draw(*npcB2->npc);
	
		int x = heroobj->shots.size();

		for(int i = 0; i < x; i++){
			heroobj->shots[i].Orientation(60);
			window->draw(*heroobj->shots[i].attacksprite);
		}

		int z = npcA1->shots.size();

		for(int i = 0; i < z; i++){
				npcA1->shots[i].Orientation(50);
				window->draw(*npcA1->shots[i].attacksprite);
			}

		int r = npcA2->shots.size();

		for(int i = 0; i < r; i++){
			npcA2->shots[i].Orientation(90);
			window->draw(*npcA2->shots[i].attacksprite);
		}

	}

	if(level2 == true){
		window->draw(*layerDraw_2);
		window->draw(*layerDown_2);
		window->draw(*heroobj->hero);
		window->draw(*npcA1->npc);
		window->draw(*npcA2->npc);
		window->draw(*npcB1->npc);
		window->draw(*npcB2->npc);
		window->draw(*npcC1->npc);
		window->draw(*npcC2->npc);
		window->draw(*npcC3->npc);

		
		int x = heroobj->shots.size();

		for(int i = 0; i < x; i++){
			heroobj->shots[i].Orientation(60);
			window->draw(*heroobj->shots[i].attacksprite);
		}


	int z = npcA1->shots.size();

		for(int i = 0; i < z; i++){
				npcA1->shots[i].Orientation(50);
				window->draw(*npcA1->shots[i].attacksprite);
			}

		int r = npcA2->shots.size();

		for(int i = 0; i < r; i++){
			npcA2->shots[i].Orientation(90);
			window->draw(*npcA2->shots[i].attacksprite);
		}

		int a = npcC1->shots.size();

		for(int i = 0; i < a; i++){
			npcC1->shots[i].Orientation(90);
			window->draw(*npcC1->shots[i].attacksprite);
		}

		int u = npcC2->shots.size();

		for(int i = 0; i < u; i++){
			npcC2->shots[i].Orientation(90);
			window->draw(*npcC2->shots[i].attacksprite);
		}

		int v = npcC3->shots.size();

		for(int i = 0; i < v; i++){
			npcC3->shots[i].Orientation(90);
			window->draw(*npcC3->shots[i].attacksprite);
		}

	}

	window->draw(r3);
	window->draw(n1);
	window->draw(r1);

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
		drawGame();
	}
	if(GameOver == true){
		window->draw(r1);
		window->draw(textGm);
		window->draw(returnKey);
	}
	window->draw(transition);
	window->display();

}

void DoomAdventure::Interface(){
	mYSt.loadFromFile("assets/Menu/06.png");
	
	r1.setScale(5,5);
	r1.setPosition(900,0);
	r1.setColor(sf::Color::Red);

	if(heroobj->live > 1500){
		sf::Vector2i size(45,20);
		sf::Vector2i position(2,77);
		r1.setTexture(mYSt,true);
		r1.setTextureRect(sf::IntRect(position,size));
	}

	if(heroobj->live < 1000){
		sf::Vector2i size(45,20);
		sf::Vector2i position(49,77);
		r1.setTexture(mYSt,true);
		r1.setTextureRect(sf::IntRect(position,size));
	}

	if(heroobj->live < 500){
		sf::Vector2i size(45,20);
		sf::Vector2i position(97,77);
		r1.setTexture(mYSt,true);
		r1.setTextureRect(sf::IntRect(position,size));
	}

	if(heroobj->live < 100){
		sf::Vector2i size(45,20);
		sf::Vector2i position(144,77);
		r1.setTexture(mYSt,true);
		r1.setTextureRect(sf::IntRect(position,size));
	}

	if(heroobj->live < 0){
		sf::Vector2i size(45,20);
		sf::Vector2i position(193,77);
		r1.setTexture(mYSt,true);
		r1.setTextureRect(sf::IntRect(position,size));
	}

	if(heroobj->live < -100){
		KeyGame = false;
		GameOver = true;
	}
}

void DoomAdventure::game() {

	if(chekedaudio == true){
		musicGame.openFromFile("assets/sound/map1.wav");
		musicGame.setLoop(true);
		musicGame.setVolume(50);
		musicGame.play();
		chekedaudio = false;
	}
	gravityAndColision();
	Interface();
	update();


	npcB1->animation();
	npcB1->testAproxim(heroobj);
	npcB2->animation();
	npcB2->testAproxim(heroobj);
	npcA1->animation();
	npcA1->testAproxim(heroobj);
	npcA2->animation();
	npcA2->testAproxim(heroobj);
	
	if(level2 == true or level3 == true){
		npcC1->animation();
		npcC1->testAproxim(heroobj);
		npcC2->animation();
		npcC2->testAproxim(heroobj);
		npcC3->animation();
		npcC3->testAproxim(heroobj);
	}

	heroobj->attack();
	heroobj->shotstimer++;
	heroobj->animation();
	if(level3 == 3){
		villain->animation();
		villain->testAproxim(heroobj);
	}
	

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
			game();
			heroobj->colision(npcA1->npc,&npcA1->live);
			heroobj->colision(npcA2->npc,&npcA2->live);
			heroobj->colision(npcB1->npc,&npcB1->live);
			heroobj->colision(npcB2->npc,&npcB2->live);
			npcA1->colision(heroobj,&GameOver,level);
			npcA2->colision(heroobj, &GameOver,level);
			npcB1->colision(heroobj,&GameOver,level);
			npcB2->colision(heroobj,&GameOver,level);
			npcC1->colision(heroobj, &GameOver,level);
			npcC2->colision(heroobj,&GameOver,level);
			npcC3->colision(heroobj,&GameOver,level);
		}
		if(GameOver == true){
			GameOverX();
		}
		
	}
}

void DoomAdventure::GameOverX(){

	if(level == 1){
		mYSt.loadFromFile("assets/Shoots/fire/fire-skull-no-fire.png");
		r1.setTexture(mYSt);
		int static teste = 0;
		if(teste == 0){
			r1.setPosition(view->getCenter().x + 90,view->getCenter().y - 200);
		}
		teste = 1;
		view->setCenter(r1.getPosition());
		
	}

	if(level == 2){
	
		mYSt.loadFromFile("assets/Shoots/fire/fire-skull-no-fire.png");
		r1.setTexture(mYSt);
		int static teste = 0;
		if(teste == 0){
			r1.setPosition(view->getCenter().x + 90,view->getCenter().y - 200);
		}
		teste = 1;
		view->setCenter(r1.getPosition());
	}

	static int framSkull =0;
	r1.setColor(sf::Color::White);
	font.loadFromFile("assets/Background/Pixelmania.ttf");
	textGm.setFont(font);
	textGm.setString("GAME OVER");
	textGm.setCharacterSize(30);
	textGm.setPosition(r1.getPosition().x - 400, r1.getPosition().y+100);

	returnKey.setFont(font);
	returnKey.setString("PRES ENTER...");
	returnKey.setCharacterSize(30);
	returnKey.setPosition(r1.getPosition().x - 400, r1.getPosition().y+300);

	if (frame >= 30) {
		frame = 0;
		if (framSkull >= 4) {
			framSkull = 1;
		} else {
			framSkull++;
		}
	}else{
		frame++;
	}

	if(framSkull == 1){
		sf::Vector2i postion(3,2);
		sf::Vector2i size(55,71);
		r1.setTextureRect(sf::IntRect(postion,size));
	}
	if(framSkull == 2){
		sf::Vector2i postion(51,2);
		sf::Vector2i size(55,71);
		r1.setTextureRect(sf::IntRect(postion,size));
	}
	if(framSkull == 3){
		sf::Vector2i postion(108,2);
		sf::Vector2i size(55,71);
		r1.setTextureRect(sf::IntRect(postion,size));
	}
	if(framSkull == 4){
		sf::Vector2i postion(162,2);
		sf::Vector2i size(55,71);
		r1.setTextureRect(sf::IntRect(postion,size));
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
		KeyGame = false;
		GameOver = false;
		KeyMenu = true;

	}

}

void DoomAdventure::Restart(){

	if(level == 1){
		GameOver= false;
		KeyMenu = true;
		heroobj->live = 2000;
		i =0;
		npcA1->live = 50;
		npcA2->live = 50;
		npcB1->live = 50;
		npcB2->live = 50;
		chekedaudio = false;
		npcA1->npc->setPosition(800,45);
		npcA2->npc->setPosition(800, 540);
		npcB1->npc->setPosition(2208, 255);
		npcB2->npc->setPosition(2032, 495);
		heroobj->hero->setPosition(0,480);
		npcA1->dead = false;
		npcA2->dead = false;
		npcB1->dead = false;
		npcB2->dead = false;
		npcA1->stopFunction = false;
		npcA2->stopFunction = false;
		npcB1->stopFunction = false;
		npcB2->stopFunction = false;
		checkpoint.setSize(sf::Vector2f(60,100));
		checkpoint.setPosition(2504,290);

		npcC1->live = -1;
		npcC2->live = -1;
		npcC3->live = -1;
	}

	if(level == 2){
		heroobj->hero->setPosition(0,441);
		npcA1->npc->setPosition(1250, 430);
		npcA2->npc->setPosition(1640, 357);
		npcA2->orientation = false;
		npcB1->npc->setPosition(844, 477);
		npcB2->npc->setPosition(2280, 223);
		npcC1->npc->setPosition(1890,600);
		npcC2->npc->setPosition(800,heroobj->hero->getPosition().y);
		npcC3->npc->setPosition(1000,400);
		npcA1->live = 200;
		npcA2->live = 200;
		npcB1->live = 200;
		npcB1->live = 200;
		npcC1->live = 200;
		npcC2->live = 200;
		npcC3->live = 200;
	}
}
DoomAdventure::~DoomAdventure(){
	delete heroobj;
	heroobj = NULL;

}


void DoomAdventure::gravityAndColision(){
	if(level1 == true){
		map1();
	}
	if(level2 == true){
		map2();
	}
	if(level3 == true){
		map3();
	}

	// switch (level)
	// {
	// case 1:
	// 	map1();
	// case 2:
	// 	map2();
	// case 3:
	// 	map3();
	// 	break;
	// }
}

void DoomAdventure::map1(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and heroobj->ControlSkip >= 0) {
		gravity = -7.f;
		heroobj->hero->move(0,gravity);
	}
	
	if(heroobj->DownCountColison != 115 and heroobj->DownCountColison != 153 and heroobj->DownCountColison != 147 and heroobj->DownCountColison != 164 and heroobj->DownCountColison != 58 or heroobj->hero->getPosition().y < 0){
			gravity += 0.7f;
	
		heroobj->hero->move(0,gravity);
	}

	if(heroobj->DownCountColison == 399){
		heroobj->hero->setPosition(heroobj->hero->getPosition().x,heroobj->hero->getPosition().y - 1);
	}

	if(heroobj->LeftCountColison == 58 or heroobj->LeftCountColison == 153){
			heroobj->hero->setPosition(heroobj->hero->getPosition().x + 8,heroobj->hero->getPosition().y);
	}

	if(heroobj->RightCountColison == 58 or heroobj->RightCountColison == 147 or heroobj->RightCountColison == 164){
			heroobj->hero->setPosition(heroobj->hero->getPosition().x - 8,heroobj->hero->getPosition().y);
	}

	if(heroobj->UpCountColison == 58 or heroobj->UpCountColison == 147 or heroobj->UpCountColison == 167){
		gravity += 4.7f;
			heroobj->hero->move(0,gravity);
	}



	if(npcA1->DownCountColison != 115 and npcA1->DownCountColison != 153 and npcA1->DownCountColison != 147 and npcA1->DownCountColison != 164 and npcA1->DownCountColison != 58 or npcA1->npc->getPosition().y < 0){
			gravity += 0.7f;
	
		npcA1->npc->move(0,gravity);
	}

	if(npcA1->DownCountColison == 399){
		npcA1->npc->setPosition(npcA1->npc->getPosition().x,npcA1->npc->getPosition().y - 1);
	}

	if(npcA1->LeftCountColison == 58 or npcA1->LeftCountColison == 153){
			npcA1->orientation = false;
	}
	if(npcA1->RightCountColison == 58 or npcA1->RightCountColison == 147 or npcA1->RightCountColison == 164){
			npcA1->orientation = true;
	}
	if(npcA1->UpCountColison == 58 or npcA1->UpCountColison == 147 or npcA1->UpCountColison == 167){
		gravity += 4.7f;
			npcA1->npc->move(0,gravity);
	}



	if(npcA2->DownCountColison != 115 and npcA2->DownCountColison != 153 and npcA2->DownCountColison != 147 and npcA2->DownCountColison != 164 and npcA2->DownCountColison != 58 or npcA2->npc->getPosition().y < 0){
			gravity += 0.7f;
	
		npcA2->npc->move(0,gravity);
	}
	if(npcA2->LeftCountColison == 58 or npcA2->LeftCountColison == 153){
			npcA2->orientation = false;
	}
	if(npcA2->RightCountColison == 58 or npcA2->RightCountColison == 147 or npcA2->RightCountColison == 164 or npcA2->npc->getPosition().x > 2335 ){
			npcA2->orientation = true;
	}
	if(npcA2->UpCountColison == 58 or npcA2->UpCountColison == 147 or npcA2->UpCountColison == 167){
		gravity += 4.7f;
			npcA2->npc->move(0,gravity);
	}

	if(npcB1->npc->getPosition().x < 476){
		npcB1->orientation = true;
	}
	if(npcB1->npc->getPosition().x > 1000){
		npcB1->orientation = false;
	}

	if(npcB2->npc->getPosition().x < 344){
		npcB2->orientation = true;
	}
	if(npcB2->npc->getPosition().x > 928){
		npcB2->orientation = false;
	}
}

void DoomAdventure::map2(){

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and heroobj->ControlSkip >= 0) {
		gravity = -7.f;
		heroobj->hero->move(0,gravity);
	}


	if(heroobj->DownCountColison != 121 or heroobj->hero->getPosition().y < 0){
			gravity += 0.7f;
	
		heroobj->hero->move(0,gravity);
	}

	

	if(heroobj->LeftCountColison == 58 ){
			heroobj->hero->setPosition(heroobj->hero->getPosition().x + 8,heroobj->hero->getPosition().y);
	}

	if(heroobj->RightCountColison == 58 ){
			heroobj->hero->setPosition(heroobj->hero->getPosition().x - 8,heroobj->hero->getPosition().y);
	}

	if(heroobj->UpCountColison == 58){
		gravity += 4.7f;
			heroobj->hero->move(0,gravity);
	}


	if(npcB1->npc->getPosition().x < 540){
		npcB1->orientation = true;
	}
	if(npcB1->npc->getPosition().x > 884){
		npcB1->orientation = false;
	}

	if(npcB2->npc->getPosition().x < 1920){
		npcB2->orientation = true;
	}
	if(npcB2->npc->getPosition().x > 2280){
		npcB2->orientation = false;
	}

	if(npcA1->npc->getPosition().x < 1316){
		npcA1->orientation = false;
	}
	if(npcA1->npc->getPosition().x > 1464){
		npcA1->orientation = true;
	}

	if(npcA2->npc->getPosition().x < 1590){
		npcA2->orientation = false;
	}
	if(npcA2->npc->getPosition().x > 1700){
		npcA2->orientation = true;
	}

}

void DoomAdventure::map3(){

}