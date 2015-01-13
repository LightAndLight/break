#ifndef PADDLE_H
#define PADDLE_H

#include<SFML/Graphics.hpp>
#include "object.h"

class Paddle : public Object {
    sf::Vector2f motion;
    
    public:
        Paddle();
        Paddle(sf::Texture& tex, sf::IntRect rect);

        float getSpeed();
        sf::Vector2f getMotion();

        void setMotion(sf::Vector2f vec);
};

#endif // PADDLE_H
