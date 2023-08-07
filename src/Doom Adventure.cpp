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

void DoomAdventure::draw(){
    window->clear(sf::Color::Black);
    window->draw();
    
    
    
}
   


void run(){

}