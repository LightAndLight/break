#ifndef BRICK_H
#define BRICK_H

#include<SFML/Graphics.hpp>
#include "object.h"

class Brick : public Object {
    bool visible;
    int hits;

    public:
        Brick();
        Brick(sf::Texture& tex, sf::IntRect rec);

        bool isVisible();
        void recieveHit();
        int hitsRemaining();
        void hide();
};

#endif // BRICK_H
