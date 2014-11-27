#include "bounded.h"
#include<iostream>

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
        if (right > b.getLeft()) {
            sides.push_back(RIGHT); 
            std::cout << "RIGHT" << std::endl;
        }

        if (b.getRight() > left) {
            sides.push_back(LEFT);
            std::cout << "LEFT" << std::endl;
        }

        if (bottom > b.getTop()) {
            sides.push_back(BOTTOM);
            std::cout << "BOTTOM" << std::endl;
        }

        if (b.getBottom() > top) {
            sides.push_back(TOP);
            std::cout << "TOP" << std::endl;
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
