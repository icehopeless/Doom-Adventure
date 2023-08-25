#include "Doom.hpp"
#include "Hero.cpp"
#include "Vilions.cpp"
#include "Npcs.cpp"
#include "DoomAdventure.cpp"

//rodar game
int main (){
    auto Doom = make_shared<DoomAdventure>();
    Doom->run();
    return EXIT_SUCCESS;
}
