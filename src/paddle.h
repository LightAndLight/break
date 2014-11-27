#ifndef PADDLE_H
#define PADDLE_H

#include<SFML/Graphics.hpp>
#include "bounded.h"

class Paddle {
    sf::Vector2f motion;
    sf::Sprite sprite;
    Bounded box;
    
    public:
        Paddle();
        Paddle(sf::Texture& tex, sf::IntRect rect);
        float getSpeed();
        void setMotion(sf::Vector2f vec);
        sf::Vector2f getMotion();
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
