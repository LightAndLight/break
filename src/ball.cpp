#include "ball.h"

Ball::Ball() {}

Ball::Ball(sf::Texture& tex, sf::IntRect rect) {
    sprite = sf::Sprite(tex,rect);
    direction = sf::Vector2f(0.0,0.0);
    speed = 300;
    box = Bounded(rect);
}

sf::Vector2f Ball::getDir() {
    return direction;
}

void Ball::setDir(sf::Vector2f vec) {
    direction = vec;
}

void Ball::reflectX() {
    direction = sf::Vector2f(direction.x,-direction.y);
}

void Ball::reflectY() {
    direction = sf::Vector2f(-direction.x,direction.y);
}

int Ball::getSpeed() {
    return speed;
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
