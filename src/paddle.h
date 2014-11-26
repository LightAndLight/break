#ifndef PADDLE_H
#define PADDLE_H

#include<SFML/Graphics.hpp>

enum Dir {
    LEFT,
    RIGHT,
    NONE
};

class Paddle {
    Dir direction;    
    int speed;
    sf::Sprite sprite;
    
    public:
        Paddle();
        Paddle(sf::Texture& tex, sf::IntRect rect);
        int getSpeed();
        void setDir(Dir d);
        Dir getDir();
        void draw(sf::RenderWindow& w);
        void setScale(float x, float y);
        void setPosition(float x, float y);
        sf::FloatRect getGlobalBounds();
        void move(float x, float y);

};

#endif // PADDLE_H
