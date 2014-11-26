#include "ball.h"

Ball::Ball() {}

Ball::Ball(sf::Texture& tex, sf::IntRect rect) {
    sprite = sf::Sprite(tex,rect);
    direction = sf::Vector2f(0.0,0.0);
    speed = 300;
}

sf::Vector2f Ball::getDir() {
    return direction;
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
}

void Ball::move(float x, float y) {
    sprite.move(x,y); 
}
