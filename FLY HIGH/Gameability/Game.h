//
// Created by Tal Mizrahi on 31/08/2022.
//

#ifndef GRAPHICSCPP_GAME_H
#define GRAPHICSCPP_GAME_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include "../CollisionRelated/Player.h"
#include "../CollisionRelated/Obstacle.h"
#include "../SpriteRelated/Background.h"
#include "GameOver.h"
#include "AbstractGameFactory.h"
#include <vector>

/**
 * The game class. Contain all methods related to the operation of the game,
 * including the initialize, run an destroy methods.
 */
class Game : public AbstractGameFactory {
public:
    Game();

    ~Game();

    Collider updatePlayer(float deltaTime);

    void initialize();

    bool run();

    void destroyAll();

    void destroyGameOver();

    void destroySprites();

    void destroyTextures();

    void resizeView(const sf::RenderWindow &window, sf::View &view);

    bool checkCollisions(float deltaTime);

    void whatToShow(bool endOfTheGame);

private:
    sf::RenderWindow window; // The window of the game.
    bool startFlag = true; // A boolean variable to know if to present the start screen.
};

#endif //GRAPHICSCPP_GAME_H
