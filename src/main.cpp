#include<SFML/Graphics.hpp>
#include "game.h"

int main() {
    Game game;

    while (game.running()) {
        game.events();
        game.update();
        game.collisions();
        game.draw();
    }

    return 0;
}

