#ifndef BALL_H
#define BALL_H

#include<SFML/Graphics.hpp>
#include "bounded.h"

class Ball {
    sf::Sprite sprite;
    sf::Vector2f motion;
    Bounded box;

    public:
        Ball();
        Ball(sf::Texture& tex,sf::IntRect rect);
        sf::Vector2f getMotion();
        void setMotion(sf::Vector2f vec);
        void reflectX();
        void reflectY();
        float getSpeed();
        void setPosition(float x, float y);
        void setScale(float x, float y);
        void move(float x, float y);
        float width();
        float height();
        float top();
        float left();
        void draw(sf::RenderWindow& w);
        Bounded getBB();
};

#endif // BALL_H
