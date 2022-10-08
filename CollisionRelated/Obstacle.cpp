//
// Created by Tal Mizrahi on 29/08/2022.
//

#include <iostream>
#include "Obstacle.h"

/**
 * The constructor for the class. Sets the texture, size, origin and position of the obstacle to it's body.
 * @param texture the texture of the obstacle.
 * @param size the size of the obstacle.
 * @param position the position of the obstacle.
 */
Obstacle::Obstacle(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position) {
    body.setSize(size);
    body.setTexture(texture);
    body.setOrigin(size / 2.0f);
    body.setPosition(position);
}

/**
 * A default destructor for the class.
 */
Obstacle::~Obstacle() = default;

/**
 * The draw method. Drawing the obstacle on the window.
 * @param window the window that the obstacle will be drawn on.
 */
void Obstacle::draw(sf::RenderWindow &window) {
    window.draw(body);
}


