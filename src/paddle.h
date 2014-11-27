#ifndef PADDLE_H
#define PADDLE_H

#include<SFML/Graphics.hpp>
#include "bounded.h"

namespace Direction {
    enum Dir {
        LEFT,
        RIGHT,
        NONE
    };
}

class Paddle {
    Direction::Dir direction;    
    int speed;
    sf::Sprite sprite;
    Bounded box;
    
    public:
        Paddle();
        Paddle(sf::Texture& tex, sf::IntRect rect);
        int getSpeed();
        void setDir(Direction::Dir d);
        Direction::Dir getDir();
        void draw(sf::RenderWindow& w);
        void setScale(float x, float y);
        void setPosition(float x, float y);
        float width();
        float height();
        float left();
        float top();
        void move(float x, float y);
        Bounded getBB();

};

#endif // PADDLE_H
