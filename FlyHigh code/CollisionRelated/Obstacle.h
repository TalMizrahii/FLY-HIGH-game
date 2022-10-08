//
// Created by Tal Mizrahi on 29/08/2022.
//

#ifndef GRAPHICSCPP_OBSTACLE_H
#define GRAPHICSCPP_OBSTACLE_H

#include <SFML/Graphics.hpp>
#include "Collider.h"
#include "../SpriteRelated/AbstractSprites.h"
#include "AbstractCollidable.h"

/**
 * The Obstacle class. Represent any collidable object and it's body.
 */
class Obstacle : public AbstractSprites, public AbstractCollidable {
public:
    Obstacle(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position);

    ~Obstacle() override;

    void draw(sf::RenderWindow &window) override;

    Collider getCollider() override { return Collider(body); }

    sf::RectangleShape getBody() override { return body; }

private:
    sf::RectangleShape body; // The body of the collidable object.
};

#endif //GRAPHICSCPP_OBSTACLE_H