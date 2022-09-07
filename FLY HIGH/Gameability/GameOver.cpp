//
// Created by Tal Mizrahi on 05/09/2022.
//

#include <iostream>
#include "GameOver.h"

/**
 * A default destructor.
 */
GameOver::~GameOver() = default;

/**
 * The constructor of the class. Creates the background of the "Game Over" screen and sets the text for the score.
 * @param texture the texture of the background.
 * @param size the size of the background.
 * @param position the position of the background, usually as the size of the screen.
 * @param text1 the text of the score as a reference.
 */
GameOver::GameOver(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position, sf::Text *text1) :
        background(texture, size, position) {
    this->text = text1;
}

/**
 * A getter for the background.
 * @return the background as a value.
 */
Background GameOver::getBackground() {
    return background;
}

/**
 * A getter for the text.
 * @return the text as a reference.
 */
sf::Text *GameOver::getText() {
    return text;
}