#include "Doom.hpp"

class npc : public DoomAdventure{
    
};


class Hero : public npc{
public:
    shared_ptr<sf::Sprite> hero;
    vector<sf::Texture> herotexture; //vetor inteligente para a textura do heroi

protected:
    void animation();

public:
    void drawHero();
    Hero();
};

class Villain : public npc{

    vector<sf::Texture> villaintexture;
    
public:
    Villain();
    ~Villain();
};
