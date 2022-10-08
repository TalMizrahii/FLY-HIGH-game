//
// Created by Tal Mizrahi on 31/08/2022.
//

#ifndef GRAPHICSCPP_ABSTRACTCOLLIDABLE_H
#define GRAPHICSCPP_ABSTRACTCOLLIDABLE_H

#include "Collider.h"

/**
 * This abstract class is used to create polymorphism between all colloidable objects.
 */
class AbstractCollidable {
public:
    AbstractCollidable();

    virtual ~AbstractCollidable();

    virtual Collider getCollider() = 0;

    virtual sf::RectangleShape getBody() = 0;
};

#endif //GRAPHICSCPP_ABSTRACTCOLLIDABLE_H