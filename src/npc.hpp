#include "Doom.hpp"
using namespace std;

class Npc : public DoomAdventure {
public:
   float x,y;    
};


class Hero : public Npc{
public:
    shared_ptr<sf::Sprite> hero;
    sf::Texture herotexture[3]; //vetor inteligente para a textura do heroi

public:
    void drawHero();
    Hero();
    void animation();
};

class Villain : public Npc{

    vector<sf::Texture> villaintexture;
    
public:
    Villain();
    ~Villain();
};
