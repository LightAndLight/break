#ifndef GAME_H
#define GAME_H

#include<SFML/Graphics.hpp>
#include<vector>
#include "paddle.h"
#include "ball.h"

class Game {
    sf::RenderWindow window;
    Paddle paddle;
    Ball ball;
    sf::Texture sheet;

    sf::Clock clock;
    sf::Time last_call;

    bool run;
    void key_press(sf::Keyboard::Key k);
    void key_release(sf::Keyboard::Key k);
    void quit();

    public:
        Game();
        void events();
        void update();
        void collisions();
        void draw();
        bool running();

};

#endif // GAME_H
