#include "ball.h"
#include<cmath>

Ball::Ball() {}

Ball::Ball(sf::Texture& tex, sf::IntRect rect) {
    sprite = sf::Sprite(tex,rect);
    motion = sf::Vector2f(0.0,0.0);
    box = Bounded(rect);
}

void Ball::setSpeed(float s) {
    float mag = getSpeed();
    float factor = s/mag;
    motion.x *= factor;
    motion.y *= factor;
}

sf::Vector2f Ball::getMotion() {
    return motion;
}

void Ball::setMotion(sf::Vector2f vec) {
    motion = vec;
}

void Ball::reflectX() {
    motion.y *= -1;
}

void Ball::reflectY() {
    motion.x *= -1;
}

float Ball::getSpeed() {
    return std::sqrt(std::pow(motion.x,2) + std::pow(motion.y,2));
}

void Ball::setPosition(float x, float y) {
    sprite.setPosition(x,y); 
    box.setPosition(x,y);
}

void Ball::setScale(float x, float y) {
    sprite.setScale(x,y); 
    box.setScale(x,y);
}

void Ball::move(float x, float y) {
    sprite.move(x,y); 
    box.move(x,y);
}

float Ball::width() {
    return sprite.getGlobalBounds().width;
}

float Ball::height() {
    return sprite.getGlobalBounds().height;
}

void Ball::draw(sf::RenderWindow& w) {
    w.draw(sprite);
}

float Ball::top() {
    return sprite.getGlobalBounds().top;
}

float Ball::left() {
    return sprite.getGlobalBounds().left;
}

Bounded Ball::getBB() {
    return box;
}

float Ball::right() {
    return left() + width();
}
