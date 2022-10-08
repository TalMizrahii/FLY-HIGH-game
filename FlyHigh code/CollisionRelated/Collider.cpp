//
// Created by Tal Mizrahi on 29/08/2022.
//

#include <iostream>
#include "Collider.h"

/**
 * A default destructor.
 */
Collider::~Collider() = default;

/**
 * The constructor of the class. Receives the body as a reference.
 * @param body the reference of the body of the collider.
 */
Collider::Collider(sf::RectangleShape &body) :
        body(body) {
}

/**
 * Checking if any collision is about to occur with another collider.
 * @param other the other collider to check the collision with.
 * @param push how far to push each object away to prevent the collision.
 * @return a boolean value if the collision occurs.
 */
bool Collider::checkCollision(Collider &other, float push) {
    // Creating trajectory of both objects.
    sf::Vector2f otherPosition = other.getPosition();
    sf::Vector2f otherHalfSize = other.getHalfSize();
    sf::Vector2f thisPosition = getPosition();
    sf::Vector2f thisHalfSize = getHalfSize();

    // Calculating the intersection between the two trajectories.
    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;
    float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

    // Checking if a collision happens.
    if (intersectX < 0.0f && intersectY < 0.0f) {
        // Setting the push.
        push = std::min(std::max(push, 0.0f), 1.0f);
        // Checking if the collision happens closer to the x-axis or the y-axis.
        if (intersectX > intersectY) {
            // If to the x axes, move the objects horizontally.
            if (deltaX > 0.0f) {
                move(intersectX * (1.0f - push), 0.0f);
                other.move(-intersectX * push, 0.0f);
            } else {
                move(-intersectX * (1.0f - push), 0.0f);
                other.move(intersectX * push, 0.0f);
            }
        } else {
            //If to the y-axis, move the objects vertically.
            if (deltaY > 0.0f) {
                move(0.0f, intersectY * (1.0f - push));
                other.move(0.0f, -intersectY * push);
            } else {
                move(0.0f, -intersectY * (1.0f - push));
                other.move(0.0f, intersectY * push);
            }
        }
        return true;
    }
    return false;
}

