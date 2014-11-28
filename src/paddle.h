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
        sf::Vector2f getMotion();
        Bounded getBB();

        void setMotion(sf::Vector2f vec);
        void setScale(float x, float y);
        void setPosition(float x, float y);

        float width();
        float height();
        float left();
        float top();
        float right();

        void move(float x, float y);

        void draw(sf::RenderWindow& w);

};

#endif // PADDLE_H
