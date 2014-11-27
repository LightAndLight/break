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

        float bRight = b.getRight();
        float bLeft = b.getLeft();
        float bBottom = b.getBottom();
        float bTop = b.getTop();

        if ((bLeft < right || bRight > left) && bBottom > top) {
            return TOP;
        } else if ((bBottom > top || bTop < bottom) && bLeft < right) {
            return RIGHT;
        } else if ((bBottom > top || bTop < bottom) && bRight > left) {
            return LEFT;
        }

    } else {
        return NONE;
    }
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
