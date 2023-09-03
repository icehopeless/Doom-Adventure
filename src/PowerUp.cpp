#include "Doom.hpp"

PowerUp::PowerUp(int x, int y, int referent)
{
    Power = make_shared<sf::Sprite>();
    frame = 0;
    this->refernt = referent;
    frameAnimation = 0;
    Power->setPosition(x, y);
    Texture.loadFromFile("assets/PowerUps/Portion.png");
    if (referent == 1)
    {   Power->setColor(sf::Color::Red);
        Power->setScale(0.1, 0.1);
        for (int i = 0; i <= 5; i++)
        {
            stringstream ss;
            ss << "assets/PowerUps/frame " << i + 1 << ".png";
            Textures[i].loadFromFile(ss.str());
        }
    }
    
}

PowerUp::~PowerUp()
{
}
void PowerUp::animation()
{
    if (refernt == 1)
    {
        if (frame >= 2)
        {
            frame = 0;
            if (frameAnimation >= 5)
            {
                frameAnimation = 0;
            }
            else
            {
                frameAnimation++;
            }
        }
        else
        {
            frame++;
        }

        Power->setTexture(Textures[frameAnimation]);
    }else{
        Power->setColor(sf::Color::White);
        Power->setScale(2, 2);
        Power->setTexture(Texture);
    }
}

void PowerUp::Update(shared_ptr<sf::Sprite> spr_hero, int *live, bool *Restart, bool *Activ)
{
    if (verificed == false)
    {
        if (spr_hero->getGlobalBounds().intersects(Power->getGlobalBounds())  and spr_hero->getColor() != sf::Color::Red)
        {
            if (refernt == 1)
            {
                *Restart = true;
                *Activ = true;
            }
            if (refernt == 2)
            {
                *live += 100;
            }
            verificed = true;
        }
    }
    else
    {
        Power->setColor(sf::Color::Transparent);
    }
}