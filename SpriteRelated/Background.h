//
// Created by Tal Mizrahi on 01/09/2022.
//

#ifndef GRAPHICSCPP_BACKGROUND_H
#define GRAPHICSCPP_BACKGROUND_H

#include <SFML/Graphics.hpp>
#include "../CollisionRelated/Collider.h"
#include "AbstractSprites.h"

/**
 * The Background class.
 * Implements AbstractSprites and contain the body of a background to the window.
 */
class Background : public AbstractSprites {
public:
    Background(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position);

    Background(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position, sf::Vector2f origin);

    ~Background() override;

    void draw(sf::RenderWindow &window);

    sf::RectangleShape getBody();


private:
    sf::RectangleShape body; // The body of the animation.
};

#endif //GRAPHICSCPP_BACKGROUND_H