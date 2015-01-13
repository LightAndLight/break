#include "brick.h"

Brick::Brick() {}

Brick::Brick(sf::Texture& tex, sf::IntRect rec) 
: Object(tex,rec) {
    visible = true;
    hits = 2;
}

bool Brick::isVisible() {
    return visible;
}

void Brick::recieveHit() {
    hits -= 1;
}

int Brick::hitsRemaining() {
    return hits;
}

void Brick::hide() {
    visible = false;
}
