#include "paddle.h"

Paddle::Paddle() {}

Paddle::Paddle(sf::Texture& tex,sf::IntRect rect) {
    sprite = sf::Sprite(tex,rect);
    speed = 400; 
    direction = Direction::NONE;
    box = Bounded(rect);
}

int Paddle::getSpeed() {
    return speed;
}

void Paddle::setDir(Direction::Dir d) {
    direction = d;
}

Direction::Dir Paddle::getDir() {
    return direction;
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
    box.setPosition(x,y);
}

Bounded Paddle::getBB() {
    return box;
}
