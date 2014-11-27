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
        return true;
    } else if (b.getRight() < left) {
        return true;
    } else if (bottom < b.getTop()) {
        return true;
    } else if (b.getBottom() < top) {
        return true;
    } else {
        return false;
    }
}

std::vector<Side> Bounded::intersectingSide(Bounded b) {
    std::vector<Side> sides;
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

    if (sides.size() == 0) {
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

void Bounded::move(float x, float y) {
    left += x;
    top += y;
}

