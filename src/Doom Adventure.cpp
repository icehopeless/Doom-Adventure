#include "Doom.hpp"

DoomAdventure::DoomAdventure(){
    window = make_shared<sf::RenderWindow>( //criando a janela com ponteiro inteligente 
     sf::VideoMode(1280, 720),
     "Doom Adventure",
     sf::Style::Titlebar | sf::Style::Close
    );

    window->setFramerateLimit(60);
}


Hero::Hero(){
    hero = make_shared<sf::Sprite>();
    herotexture[0].loadFromFile("assets/Hero/Gunner_Idle_1.png");
}

//animando o hero
void Hero::animation(){
    hero->setTexture(herotexture[0]);
}


void DoomAdventure :: events(){
    sf::Event event;

    while(window->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window->close();
        }
    }
}

void Hero::drawHero(){
     window->clear(sf::Color::Black);
     window->draw(*hero);
     window->display();
}

void DoomAdventure::draw(){
    hero->drawHero();
}
   

void DoomAdventure::game(){
    hero->animation();
}

void DoomAdventure::run(){
    while(window->isOpen()){
        draw();
        events();
        game();
        
    }
}