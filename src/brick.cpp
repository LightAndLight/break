#include "brick.h"

Brick::Brick() {}

Brick::Brick(sf::Texture& tex, sf::IntRect rec) 
: Object(tex,rec) {
    visible = true;
}

bool Brick::isVisible() {
    return visible;
}
