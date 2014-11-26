#ifndef GAME_H
#define GAME_H

#include<SFML/Graphics.hpp>

class Game {
    sf::RenderWindow window;
    bool run;
    void handle_key(sf::Keyboard::Key k);
    void quit();

    public:
        Game();
        void events();
        void update();
        void draw();
        bool running();

};

#endif // GAME_H
