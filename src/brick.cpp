#include "brick.h"

Brick::Brick() {}

Brick::Brick(sf::Texture& tex, sf::IntRect rec) 
: Object(tex,rec) {
    visible = true;
    hits = 8;
}

bool Brick::isVisible() {
    return visible;
}

void Brick::recieveHit() {
    hits -= 1;

    switch (hits) {
        case 1:
            setColor(127,0,255);
            break;
        case 2:
            setColor(75,0,130);
            break;
        case 3:
            setColor(0,0,255);
            break;
        case 4:
            setColor(0,255,0);
            break;
        case 5:
            setColor(255,255,0);
            break;
        case 6:
            setColor(255,127,0);
            break;
        case 7:
            setColor(255,0,0);
            break;
        default:
            break;
    }
}

int Brick::hitsRemaining() {
    return hits;
}

void Brick::hide() {
    visible = false;
}
