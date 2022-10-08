//
// Created by Tal Mizrahi on 31/08/2022.
//

#ifndef GRAPHICSCPP_ABSTRACTSPRITES_H
#define GRAPHICSCPP_ABSTRACTSPRITES_H

#include <SFML/Graphics.hpp>
#include "Animation.h"

/**
 * This abstract class is used to create polymorphism between all sprite objects.
 */
class AbstractSprites {

public:
    AbstractSprites();

    virtual ~AbstractSprites();

    virtual void draw(sf::RenderWindow &window) = 0;

    virtual sf::RectangleShape getBody() = 0;

};

#endif //GRAPHICSCPP_ABSTRACTSPRITES_H