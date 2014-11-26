#ifndef GAME_H
#define GAME_H

#include<SFML/Graphics.hpp>
#include<vector>

class Game {
    sf::RenderWindow window;
    sf::Texture sheet;
    sf::Sprite paddle;

    bool run;
    void handle_key(sf::Keyboard::Key k);
    void quit();

    std::vector<sf::Sprite*> objects;

    public:
        Game();
        void events();
        void update();
        void draw();
        bool running();

};

#endif // GAME_H
