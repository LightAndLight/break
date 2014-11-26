#ifndef GAME_H
#define GAME_H

#include<SFML/Graphics.hpp>
#include<vector>

enum Dir {
    LEFT,
    RIGHT,
    NONE
};

class Game {
    sf::RenderWindow window;
    sf::Texture sheet;
    sf::Sprite paddle;

    sf::Clock clock;
    sf::Time last_call;

    Dir paddle_dir;
    int paddle_speed;

    bool run;
    void key_press(sf::Keyboard::Key k);
    void key_release(sf::Keyboard::Key k);
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
