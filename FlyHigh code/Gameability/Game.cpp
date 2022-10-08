//
// Created by Tal Mizrahi on 31/08/2022.
//

#include "Game.h"
#include <random>

/**
 * Constructor for the class. Sets the window of the game.
 */
Game::Game() : window(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT),
                      "FLY HIGH",
                      sf::Style::Close |
                      sf::Style::Titlebar |
                      sf::Style::Resize) {
}

/**
 *  Default destructor for the class.
 */
Game::~Game() = default;

/**
 * Initializing all objects of the game.
 */
void Game::initialize() {
    createStartScreen();
    createBackground();
    createPipes();
    createBorders();
    createPlayer();
}

/**
 * The Run method. Runs the game and contain the main run loop.
 * @return true if the user wish to play another game.
 */
bool Game::run() {
    //Setting the view.
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT));
    //Setting the deltaTime(the time between the last frame and the current frame) and clock.
    float deltaTime = 0.0f;
    sf::Clock clock;
    // A flag to the end of the game. false means game on, true means end the game.
    bool endOfTheGame = false;
    // Showing the window to the screen.
    while (window.isOpen()) {
        // Setting the deltaTime.
        deltaTime = clock.restart().asSeconds();
        // Opening a new window for the event.
        sf::Event evnt{};
        // While the window is open we can move it with the event.
        while (window.pollEvent(evnt)) {
            // Checking the event type, keeping space for changes as required.
            switch (evnt.type) {
                // If closing the window, close.
                case sf::Event::Closed:
                    window.close();
                    destroyAll();
                    return false;
                    // If wish to resize, keep this option.
                case sf::Event::Resized:
                    resizeView(window, view);
                    break;
            }
        }

        // Start the game if the player want to.
        if (startFlag && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            startFlag = false;
        }
        // If the flag is off, check the collisions.
        if (!startFlag && !endOfTheGame) {
            endOfTheGame = checkCollisions(deltaTime);
        }
        // If the gameOver is on and the space is pressed, end the game and start a new one.
        if (endOfTheGame && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            destroyAll();
            return true;
        }

        //Clear and draw all objects of the game and set the view to the center of the player.
        view.setCenter(player->getPosition());
        window.clear(sf::Color(109, 211, 229));
        window.setView(view);

        whatToShow(endOfTheGame);
        // Display the window.
        window.display();
    }
    destroyAll();
    return false;
}

/**
 * Checking what to show on the screen between the start screen, endGame screen or the sprite's listeners.
 * @param endOfTheGame
 */
void Game::whatToShow(bool endOfTheGame) {
    // If the flag is on initiate the "Game Over".
    if (endOfTheGame && gameOver != nullptr) {
        gameOver->getBackground().draw(window);
        window.draw(*gameOver->getText());
    }
        // If the start flag is still on, show the start screen.
    else if (startFlag) {
        startScreen.draw(window);
    }
        // If no flags are on, show the game.
    else {
        for (auto &sprite : sprites) {
            sprite->draw(window);
        }
    }
}

/**
 * Going over all cillidable objects and checking collision with the player.
 * @param deltaTime the time between the last frame and the current frame.
 * @return a boolean value if any collision occurred.
 */
bool Game::checkCollisions(float deltaTime) {
    Collider c = updatePlayer(deltaTime);
    for (auto &collidable : collidables) {
        //If collision detected, return true.
        if (collidable->getCollider().checkCollision(c, 1.0f)) {
            createGameOver();
            return true;
        }
    }
    //No collision occurred, so return false.
    return false;
}

/**
 * updating the players position.
 * @param deltaTime the deltaTime of the player (to show).
 * @return the collider of the player.
 */
Collider Game::updatePlayer(float deltaTime) {
    //Updating the player.
    player->update(deltaTime);
    // Return the player's collider.
    return player->getCollider();
}

/**
 * Resizing the window and centering the view by the initiated ratio.
 * @param window1 the window.
 * @param view the view.
 */
void Game::resizeView(const sf::RenderWindow &window1, sf::View &view) {
    float ratio = float(window1.getSize().x) / float(window1.getSize().y);
    view.setSize(VIEW_WIDTH * ratio, VIEW_HEIGHT);
}

/**
 * A destroy method which free all allocated memory and ends the game.
 */
void Game::destroyAll() {
    destroyGameOver();
    destroySprites();
    destroyTextures();

    // Clearing the Listeners lists.
    collidables.clear();
    sprites.clear();
}

/**
 * Deleting all allocated memory of "GameOver".
 */
void Game::destroyGameOver() {
    if(font != nullptr){
        delete font;
        font = nullptr;
    }
    if(text != nullptr){
        delete text;
        text = nullptr;
    }
    if(gameOver != nullptr){
        delete gameOver;
        gameOver = nullptr;
    }
}

/**
 * Deleting all allocated memory of the sprites of the game.
 */
void Game::destroySprites() {
    for (auto &sprite : sprites) {
        if (sprite != nullptr) {
            delete sprite;
            sprite = nullptr;
        }
    }
}

/**
 * Deleting all allocated memory of the textures of the game.
 */
void Game::destroyTextures() {
    for (auto &texture : textures) {
        if (texture != nullptr) {
            delete texture;
            texture = nullptr;
        }
    }
}



