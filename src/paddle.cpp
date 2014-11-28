#include "paddle.h"
#include<cmath>

Paddle::Paddle() : Object() {}

Paddle::Paddle(sf::Texture& tex,sf::IntRect rect) 
: Object(tex,rect) {
    motion = sf::Vector2f(0.0,0.0);
}

float Paddle::getSpeed() {
    return std::sqrt(std::pow(motion.x,2) + std::pow(motion.y,2));
}

sf::Vector2f Paddle::getMotion() {
    return motion;
}

void Paddle::setMotion(sf::Vector2f vec) {
    motion = vec;
}

