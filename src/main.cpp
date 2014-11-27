#include<SFML/Graphics.hpp>
#include "game.h"

int main() {
    Game game;

    while (game.running()) {
        game.events();
        game.collisions();
        game.update();
        game.draw();
    }

    return 0;
}

