#include "Doom.hpp"
#include "Hero.cpp"
#include "Npcs.cpp"
#include "Update.cpp"
#include "SFMLOrthogonalLayer.hpp"
#include "tinyxml2.cpp"
#include "tinyxml2.h"
#include "Vilions.cpp"
#include "DoomAdventure.cpp"


//rodar game
int main (){
    auto Doom = make_shared<DoomAdventure>();
    Doom->run();
    return EXIT_SUCCESS;
}
