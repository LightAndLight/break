#include "paddle.h"
#include<cmath>

Paddle::Paddle() {}

Paddle::Paddle(sf::Texture& tex,sf::IntRect rect) {
    sprite = sf::Sprite(tex,rect);
    motion = sf::Vector2f(0.0,0.0);
    box = Bounded(rect);
}

float Paddle::getSpeed() {
    return std::sqrt(std::pow(motion.x,2) + std::pow(motion.y,2));
}

void Paddle::setMotion(sf::Vector2f vec) {
    motion = vec;
}

sf::Vector2f Paddle::getMotion() {
    return motion;
}

void Paddle::draw(sf::RenderWindow& w) {
    w.draw(sprite);
}

void Paddle::setScale(float x, float y) {
    sprite.setScale(x,y);
    box.setScale(x,y);
}

void Paddle::setPosition(float x, float y) {
    sprite.setPosition(x,y);
    box.setPosition(x,y);
}

float Paddle::width() {
    return sprite.getGlobalBounds().width;
}

float Paddle::height() {
    return sprite.getGlobalBounds().height;
}

float Paddle::left() {
    return sprite.getGlobalBounds().left;
}

float Paddle::top() {
    return sprite.getGlobalBounds().top;
}

void Paddle::move(float x, float y) {
    sprite.move(x,y);
    box.move(x,y);
}

Bounded Paddle::getBB() {
    return box;
}

float Paddle::right() {
    return left() + width();
}
