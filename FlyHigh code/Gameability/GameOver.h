//
// Created by Tal Mizrahi on 05/09/2022.
//

#ifndef GRAPHICSCPP_GAMEOVER_H
#define GRAPHICSCPP_GAMEOVER_H


#include "../SpriteRelated/Background.h"

/**
 * The game over class. Contains the background of the "Game Over" screen and the text of the score.
 */
class GameOver {
public:
    GameOver(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position, sf::Text *text);

    ~GameOver();

    Background getBackground();

    sf::Text *getText();

private:
    Background background; // The background of the screen.
    sf::Text *text;        // The text of the score.
};


#endif //GRAPHICSCPP_GAMEOVER_H
