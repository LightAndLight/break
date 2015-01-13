#ifndef OBJECT_H
#define OBJECT_H

#include<SFML/Graphics.hpp>
#include "bounded.h"

class Object {
    sf::Sprite sprite;
    Bounded box;

    public:
        Object();
        Object(sf::Texture& tex, sf::IntRect rect);

        Bounded getBB();

        void setScale(float x, float y);
        void setPosition(float x, float y);
        void setColor(int r, int g, int b);

        float width();
        float height();
        float left();
        float right();
        float top();
        float bottom();

        void move(float x, float y);

        void draw(sf::RenderWindow& w);

};

#endif // OBJECT_H
