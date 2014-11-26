#ifndef BALL_H
#define BALL_H

#include<SFML/Graphics.hpp>

class Ball {
    sf::Sprite sprite;
    sf::Vector2f direction;
    int speed;

    public:
        Ball();
        Ball(sf::Texture& tex,sf::IntRect rect);
        sf::Vector2f getDir();
        void reflectX();
        void reflectY();
        int getSpeed();
        void setPosition(float x, float y);
        void move(float x, float y);
        float width();
        float height();
};

#endif // BALL_H
