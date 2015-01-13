#ifndef BRICK_H
#define BRICK_H

#include<SFML/Graphics.hpp>
#include "object.h"

class Brick : public Object {
    bool visible;

    public:
        Brick();
        Brick(sf::Texture& tex, sf::IntRect rec);

        bool isVisible();
};

#endif // BRICK_H
