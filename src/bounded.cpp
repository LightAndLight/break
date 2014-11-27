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

std::vector<Side> Bounded::intersectingSide(Bounded b) {
    std::vector<Side> sides;
    if (intersects(b)) {
        if (b.getLeft() > left + getWidth()/2) {
            sides.push_back(RIGHT); 
        }

        if (b.getRight() < left + getWidth()/2) {
            sides.push_back(LEFT);
        }

        if (b.getTop() > top + getHeight()/2) {
            sides.push_back(BOTTOM);
        }

        if (b.getBottom() < top + getHeight()/2) {
            sides.push_back(TOP);
        }

    } else {
        sides.push_back(NONE);
    }

    return sides;
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
