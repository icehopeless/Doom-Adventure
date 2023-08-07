#pragma once

#include <iostream>
#include <memory>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <vector>
#include "npc.hpp"

using namespace std;

class DoomAdventure {
    shared_ptr<sf::RenderWindow> window; //ponteiro inteligente para a janela
    shared_ptr<sf::Sprite> background;
    sf::Texture bgtexutre;

protected:
    void events();
    void draw();
    void game();

public:
    DoomAdventure();
    void run();
};


