#include "bounded.h"

Bounded::Bounded() {}

Bounded::Bounded(sf::IntRect rec) {
    top = rec.top;
    left = rec.left;
    bottom = rec.top + rec.height;
    right = rec.left + rec.width;
}

bool Bounded::intersects(Bounded b) {
    if (right < b.getLeft() || b.getRight() < left 
        || bottom < b.getTop() || b.getBottom() < top) {
        return false; 
    } else {
        return true;
    }
}

Side Bounded::intersectingSide(Bounded b) {
    if (intersects(b)) {

        float leftCollision = b.getRight() - left;
        float rightCollision = right - b.getLeft();
        float topCollision = b.getBottom() - top;

        if (topCollision < leftCollision && topCollision < rightCollision) {
            return TOP;
        }
        
        if (rightCollision < leftCollision && rightCollision < topCollision) {
            return RIGHT;
        } 
        
        if (leftCollision < topCollision && leftCollision < rightCollision) {
            return LEFT;
        }

    }

    return NONE;
}

float Bounded::getTop() {
    return top;
}

float Bounded::getBottom() {
    return bottom;
}

float Bounded::getLeft() {
    return left;
}

float Bounded::getRight() {
    return right;
}

void Bounded::setPosition(float x, float y) {
    float width = right - left;
    left = x;
    right = x + width;

    float height = bottom - top;
    top = y;
    bottom = y + height;
}

void Bounded::setScale(float x, float y) {
    right = left + (right - left)*x;
    bottom = top + (bottom - top)*y;
}

void Bounded::move(float x, float y) {
    left += x;
    right += x;
    top += y;
    bottom += y;
}

float Bounded::getWidth() {
    return right - left;
}

float Bounded::getHeight() {
    return bottom - top;
}
