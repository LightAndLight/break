#ifndef BOUNDED_H
#define BOUNDED_H

#include<SFML/Graphics.hpp>
#include<vector>

enum Side {
    LEFT,
    RIGHT,
    TOP,
    BOTTOM,
    NONE
};

class Bounded {
    float left;  
    float top;  
    float bottom;  
    float right;  

    public:
        Bounded();
        Bounded(sf::IntRect rec);
        bool intersects(Bounded b);
        std::vector<Side> intersectingSide(Bounded b);
        float getTop();
        float getBottom();
        float getLeft();
        float getRight();
        void setPosition(float x, float y);
        void setScale(float x, float y);
        void move(float x, float y);

};

#endif // BOUNDED_H
