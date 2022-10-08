//
// Created by Tal Mizrahi on 01/09/2022.
//

#include <iostream>
#include "Background.h"

/**
 *  A default destructor.
 */
Background::~Background() = default;;

/**
 * A constructor of the class. Receives texture, size and initiated position.
 * @param texture the texture of the background.
 * @param size the size of the background, usually as the size of the window.
 * @param position the initiated position.
 */
Background::Background(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position) {
    body.setSize(size);
    body.setTexture(texture);
    body.setPosition(position);
}

/**
 * A constructor of the class. Receives texture, size, origin and initiated position.
 * @param texture the texture of the background.
 * @param size the size of the background, usually as the size of the window.
 * @param position the initiated position.
 * @param origin the origin of the background.
 */
Background::Background(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position, sf::Vector2f origin) {
    body.setSize(size);
    body.setTexture(texture);
    body.setOrigin(origin);
    body.setPosition(position);
}

/**
 * The draw method as asked in the AbstractSprites class in which this class implements.
 * @param window
 */
void Background::draw(sf::RenderWindow &window) {
    window.draw(body);
}

/**
 * A getter for the body of the background.
 * @return the value of the body of the background.
 */
sf::RectangleShape Background::getBody() {
    return sf::RectangleShape();
}


