#include "ball.h"
#include<cmath>

Ball::Ball() : Object() {}

Ball::Ball(sf::Texture& tex, sf::IntRect rect)
: Object(tex,rect) {
    motion = sf::Vector2f(0.0,0.0);
}

sf::Vector2f Ball::getMotion() {
    return motion;
}

float Ball::getSpeed() {
    return std::sqrt(std::pow(motion.x,2) + std::pow(motion.y,2));
}

void Ball::setMotion(sf::Vector2f vec) {
    motion = vec;
}

void Ball::setSpeed(float s) {
    float mag = getSpeed();
    float factor = s/mag;
    motion.x *= factor;
    motion.y *= factor;
}

void Ball::reflectX() {
    motion.y *= -1;
}

void Ball::reflectY() {
    motion.x *= -1;
}

