#include "object.h"

Object::Object() {}

Object::Object(sf::Texture& tex,sf::IntRect rect) {
    sprite = sf::Sprite(tex,rect);
    box = Bounded(rect);
}

Bounded Object::getBB() {
    return box;
}

void Object::setScale(float x, float y) {
    sprite.setScale(x,y);
    box.setScale(x,y);
}

void Object::setPosition(float x, float y) {
    sprite.setPosition(x,y);
    box.setPosition(x,y);
}

float Object::width() {
    return sprite.getGlobalBounds().width;
}

float Object::height() {
    return sprite.getGlobalBounds().height;
}

float Object::left() {
    return sprite.getGlobalBounds().left;
}

float Object::right() {
    return sprite.getGlobalBounds().left;
}

float Object::top() {
    return sprite.getGlobalBounds().top;
}

float Object::bottom() {
    return sprite.getGlobalBounds().top;
}

void Object::move(float x, float y) {
    sprite.move(x,y);
    box.move(x,y);
}

void Object::draw(sf::RenderWindow& w) {
    w.draw(sprite);
}