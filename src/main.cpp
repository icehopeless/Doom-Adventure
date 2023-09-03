#include "Doom.hpp"
#include "Hero.cpp"
#include "Npcs.cpp"
#include "Update.cpp"
#include "SFMLOrthogonalLayer.hpp"
#include "Vilions.cpp"
#include "DoomAdventure.cpp"
#include "PowerUp.cpp"


//rodar game
int main (){
    auto Doom = make_shared<DoomAdventure>();
    Doom->run();
    return EXIT_SUCCESS;
}
