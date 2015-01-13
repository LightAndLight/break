#ifndef BALL_H
#define BALL_H

#include<SFML/Graphics.hpp>
#include "object.h"

class Ball : public Object{
    sf::Vector2f motion;

    public:
        Ball();
        Ball(sf::Texture& tex,sf::IntRect rect);

        sf::Vector2f getMotion();
        float getSpeed();

        void setMotion(sf::Vector2f vec);
        void setSpeed(float s);

        void reflectX();
        void reflectY();
};

#endif // BALL_H
