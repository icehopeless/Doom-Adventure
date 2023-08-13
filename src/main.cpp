#include "Doom.hpp"

//rodar game
int main (){

    auto Doom = make_shared<DoomAdventure>();
    Doom->run();

    return EXIT_SUCCESS;
}
