#include "paddle.h"

Paddle::Paddle() {}

Paddle::Paddle(sf::Texture& tex,sf::IntRect rect) {
    sprite = sf::Sprite(tex,rect);
    speed = 400; 
    direction = NONE;
}

int Paddle::getSpeed() {
    return speed;
}

void Paddle::setDir(Dir d) {
    direction = d;
}

Dir Paddle::getDir() {
    return direction;
}

void Paddle::draw(sf::RenderWindow& w) {
    w.draw(sprite);
}

void Paddle::setScale(float x, float y) {
    sprite.setScale(x,y);
}

void Paddle::setPosition(float x, float y) {
    sprite.setPosition(x,y);
}

sf::FloatRect Paddle::getGlobalBounds() {
    return sprite.getGlobalBounds();
}

void Paddle::move(float x, float y) {
    sprite.move(x,y);
}
