#include "bounded.h"

Bounded::Bounded() {}

Bounded::Bounded(sf::IntRect rec) {
    top = rec.top;
    left = rec.left;
    bottom = rec.top + rec.height;
    right = rec.left + rec.width;
}

bool Bounded::intersects(Bounded b) {
    if (right < b.getLeft()) {
        return false;
    } else if (b.getRight() < left) {
        return false;
    } else if (bottom < b.getTop()) {
        return false;
    } else if (b.getBottom() < top) {
        return false;
    } else {
        return true;
    }
}

std::vector<Side> Bounded::intersectingSide(Bounded b) {
    std::vector<Side> sides;
    if (intersects(b)) {
        if (b.getLeft() < right) {
            sides.push_back(RIGHT); 
        }

        if (b.getTop() < bottom) {
            sides.push_back(BOTTOM);
        }

        if (left < b.getRight()) {
            sides.push_back(LEFT);
        }

        if (top < b.getBottom()) {
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
    left = x;
    top = y;
}

void Bounded::setScale(float x, float y) {
    right = left + (right - left)*x;
    bottom = top + (bottom - top)*y;
}

void Bounded::move(float x, float y) {
    left += x;
    top += y;
}

