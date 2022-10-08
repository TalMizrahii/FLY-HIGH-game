//
// Created by Tal Mizrahi on 29/08/2022.
//

#ifndef GRAPHICSCPP_COLLIDER_H
#define GRAPHICSCPP_COLLIDER_H

#include <SFML/Graphics.hpp>

/**
 * A collider class creating collider for a specific object to check collision with other objects.
 */
class Collider {
public:
    explicit Collider(sf::RectangleShape &body);

    ~Collider();

    bool checkCollision(Collider &other, float push);

    void move(float dx, float dy) { body.move(dx, dy); }

    sf::Vector2f getPosition() { return body.getPosition(); }

    sf::Vector2f getHalfSize() { return body.getSize() / 2.0f; }

private:
    sf::RectangleShape &body; // The body of the object the collider is made for.
};


#endif //GRAPHICSCPP_COLLIDER_H
