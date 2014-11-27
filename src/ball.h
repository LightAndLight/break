#ifndef BALL_H
#define BALL_H

#include<SFML/Graphics.hpp>
#include "bounded.h"

class Ball {
    sf::Sprite sprite;
    sf::Vector2f direction;
    int speed;
    Bounded box;

    public:
        Ball();
        Ball(sf::Texture& tex,sf::IntRect rect);
        sf::Vector2f getDir();
        void setDir(sf::Vector2f vec);
        void reflectX();
        void reflectY();
        int getSpeed();
        void setPosition(float x, float y);
        void setScale(float x, float y);
        void move(float x, float y);
        float width();
        float height();
        void draw(sf::RenderWindow& w);
        float top();
        float left();
};

#endif // BALL_H
