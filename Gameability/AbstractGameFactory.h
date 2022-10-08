//
// Created by Tal Mizrahi on 06/09/2022.
//

#ifndef GRAPHICSCPP_ABSTRACTGAMEFACTORY_H
#define GRAPHICSCPP_ABSTRACTGAMEFACTORY_H

#include <SFML/Graphics/Texture.hpp>
#include "../SpriteRelated/AbstractSprites.h"
#include "../CollisionRelated/Player.h"
#include "GameOver.h"
#include "../CollisionRelated/Obstacle.h"
#include <cstdlib>
#include <random>
#include <ctime>

/**
 * This class created to be a factory for the game's objects. It creates all visual objects and contain their data.
 */
class AbstractGameFactory {
protected:
    virtual void createPlayer();

    virtual void createPipesRight(float length, float height, sf::Texture *texture);

    virtual void createPipesLeft(float length, float height, sf::Texture *texture);

    virtual void createBackground();

    virtual void createBorders();

    virtual void createBordersRight(float newY, sf::Texture *texture);

    virtual void createBordersLeft(float newY, sf::Texture *texture);

    virtual void createScoreText();

    virtual void createGameOver();

    virtual void createPipes();

    virtual void createStartScreen();

    // Constant value of the size of the screen.
    static const unsigned int VIEW_HEIGHT = 900.0f;
    static const unsigned int VIEW_WIDTH = 1200.0f;

protected:
    std::vector<AbstractSprites *> sprites;        // Contain all sprites of the game in a listener's list.
    std::vector<AbstractCollidable *> collidables; // Contain all collidable objects in a listeners list.
    std::vector<sf::Texture *> textures;           //Contain all textures of the game for safe delete at game's end.
    Player *player;                                // The player's reference.
    GameOver *gameOver = nullptr;                  // The "Game Over" member of the game.
    sf::Text *text = nullptr;                      // The text of the game, created for the score.
    sf::Font *font = nullptr;                      // The special font of the game.
    Background startScreen = Background(nullptr, sf::Vector2f(0.0f, 0.0f),
                                        sf::Vector2f(0.0f, 0.0f)); // The default start screen of the game.
};

#endif //GRAPHICSCPP_ABSTRACTGAMEFACTORY_H