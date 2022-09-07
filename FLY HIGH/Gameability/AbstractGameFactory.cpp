//
// Created by Tal Mizrahi on 06/09/2022.
//

#include "AbstractGameFactory.h"

using namespace std;

/**
 * Creating the player of the game.
 */
void AbstractGameFactory::createPlayer() {
    //Uploading the texture of the player.
    auto *playerTexture = new sf::Texture;
    playerTexture->loadFromFile("C:\\Users\\Tal Mizrahi\\Desktop\\coding\\C"
                                "\\clion\\CLionProjects\\GraphicsCPP\\resources\\bird.png");
    // Insert the texture to the textures list.
    textures.push_back(playerTexture);
    player = new Player(playerTexture, sf::Vector2u(3, 4), 0.3f, 500.0f); // Setting its coordinates.
    sprites.push_back(player); // Adding it to the sprite's list.
}

/**
 * Creating the background of the game.
 */
void AbstractGameFactory::createBackground() {
    //Importing the texture.
    auto *backgroundTexture = new sf::Texture;
    backgroundTexture->loadFromFile("C:\\Users\\Tal Mizrahi\\Desktop\\coding\\C"
                                    "\\clion\\CLionProjects\\GraphicsCPP\\resources\\sky.png");
    // Insert the texture to the textures list.
    textures.push_back(backgroundTexture);
    //Creating the background.
    for (int i = 0; i < 1000; i++) {
        auto newY = float(-abs(i * 1800));
        sf::Vector2f size = sf::Vector2f(3000.0f, 1800.0f);
        auto background = new Background(backgroundTexture, size,
                                         sf::Vector2f(0.0f, newY), size / 2.0f);
        //Adding it to the "sprites" listeners.
        sprites.push_back(background);
    }
}

/**
 * Creating the right sided borders.
 * @param newY the width of the pipe.
 * @param texture the texture of the border.
 */
void AbstractGameFactory::createBordersRight(float newY, sf::Texture *texture) {
    auto *borderRight = new Obstacle(texture, sf::Vector2f(1000.0f, 1800.0f),
                                     sf::Vector2f(1000.0f, newY));
    // Adding the borders to the Listeners lists.
    sprites.push_back(borderRight);
    collidables.push_back(borderRight);
}

/**
 * Creating the left sided borders.
 * @param newY the width of the pipe.
 * @param texture the texture of the border.
 */
void AbstractGameFactory::createBordersLeft(float newY, sf::Texture *texture) {
    auto *borderLeft = new Obstacle(texture, sf::Vector2f(1000.0f, 1800.0f),
                                    sf::Vector2f(-1000.0f, newY));
    sprites.push_back(borderLeft);
    collidables.push_back(borderLeft);
}

/**
 * Creating the borders of the game (bricks shape).
 */
void AbstractGameFactory::createBorders() {
    // Importing the texture.
    auto *borderTexture = new sf::Texture;
    borderTexture->loadFromFile("C:\\Users\\Tal Mizrahi\\Desktop\\coding\\C"
                                "\\clion\\CLionProjects\\GraphicsCPP\\resources\\border.png");
    // Insert the texture to the textures list.
    textures.push_back(borderTexture);
    //Creating the game's space borders.
    for (int i = 0; i < 1000; i++) {
        auto newY = float(-abs(i * 1800));
        createBordersLeft(newY, borderTexture);
        createBordersRight(newY, borderTexture);
    }
}

/**
 * Creating the pipes who go to the right.
 * @param length the length of the pipe.
 * @param height the height of the pipe.
 */
void AbstractGameFactory::createPipesRight(float length, float height, sf::Texture *pipeRightTexture) {
    // Setting the coordinates.
    auto *pipe = new Obstacle(pipeRightTexture,
                              sf::Vector2f(800.0f, 50.0f), sf::Vector2f(length, height));
    // Adding the pipe to the Listener's lists.
    collidables.push_back(pipe);
    sprites.push_back(pipe);
}

/**
 * Creating the pipes who go to the Left.
 * @param length the length of the pipe.
 * @param height the height of the pipe.
 */
void AbstractGameFactory::createPipesLeft(float length, float height, sf::Texture *pipeLeftTexture) {
    // Setting the coordinates.
    auto *pipe = new Obstacle(pipeLeftTexture,
                              sf::Vector2f(800.0f, 50.0f), sf::Vector2f(length, height));
    // Adding the pipe to the Listener's lists.
    collidables.push_back(pipe);
    sprites.push_back(pipe);
}

/**
 * creating random length pipes.
 * Setting the pipes to be closer every stage, what make the game gradually harder.
 */
void AbstractGameFactory::createPipes() {

    //Uploading the texture of the pipes to the left.
    auto *pipeLeftTexture = new sf::Texture;
    pipeLeftTexture->loadFromFile("C:\\Users\\Tal Mizrahi\\Desktop\\coding\\C"
                                  "\\clion\\CLionProjects\\GraphicsCPP\\resources\\pipeLeft.png");
    //Uploading the texture of the pipes to the right.
    auto *pipeRightTexture = new sf::Texture;
    pipeRightTexture->loadFromFile("C:\\Users\\Tal Mizrahi\\Desktop\\coding\\C"
                                   "\\clion\\CLionProjects\\GraphicsCPP\\resources\\pipeRight.png");
    // Insert the textures to the textures list.
    textures.push_back(pipeLeftTexture);
    textures.push_back(pipeRightTexture);

    // Seeding the random number generator.
    srand((unsigned) time(NULL));
    // The height of the first pipe's appearance.
    float height = -1000.0f;
    //The stages of the game, represents the space between the pipes each stage (smaller means harder).
    const float stage1 = 470;
    const float stage2 = 450;
    const float stage3 = 350;
    //Creating the amount of pipes we want.
    for (int i = 0; i < 1000; i++) {
        //Generating a random number.
        float length = -150.0f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (300.0f)));
        //Creating the pipes by stage.
        if (i < 40) {
            createPipesLeft(550.f + length, height, pipeLeftTexture);
            createPipesRight(-550.0f + length, height, pipeRightTexture);
            height -= stage1;
        } else if (i >= 40 && i < 100) {
            createPipesLeft(525.f + length, height, pipeLeftTexture);
            createPipesRight(-525.0f + length, height, pipeRightTexture);
            height -= stage2;
        } else {
            createPipesLeft(510.f + length, height, pipeLeftTexture);
            createPipesRight(-510.0f + length, height, pipeRightTexture);
            height -= stage3;
        }
    }
}

/**
 * Creating the "Game Over" screen.
 */
void AbstractGameFactory::createGameOver() {
    //Uploading the texture of the background of the end screen.
    auto *endGameTexture = new sf::Texture;
    endGameTexture->loadFromFile("C:\\Users\\Tal Mizrahi\\Desktop\\coding\\C"
                                 "\\clion\\CLionProjects\\GraphicsCPP\\resources\\endGame.png");
    textures.push_back(endGameTexture);
    //Uploading the font of the score.
    font = new sf::Font;
    font->loadFromFile("C:\\Users\\Tal Mizrahi\\Desktop\\coding\\C"
                       "\\clion\\CLionProjects\\GraphicsCPP\\resources\\fontPixel.ttf");
    //Creating the text of the score.
    text = new sf::Text;
    text->setFont(*font);

    //Creating the score and setting it to the gameOver member.
    createScoreText();
    gameOver = new GameOver(endGameTexture, sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT),
                            sf::Vector2f(player->getBody().getPosition().x - VIEW_WIDTH / 2.0f,
                                         player->getBody().getPosition().y - VIEW_HEIGHT / 2.0f), text);
}

/**
 * Creating the texture and the score of the game, as a text to the "Game Over" screen.
 */
void AbstractGameFactory::createScoreText() {
    //Producing the score from the player's height.
    int score = int(roundf(abs(player->getBody().getPosition().y) / 10));
    string s = to_string(score);
    text->setString(s);
    text->setCharacterSize(75); // Setting the size of the font.
    // Setting the coordinates relatively to the player's position.
    text->setPosition(player->getBody().getPosition().x - 50, player->getBody().getPosition().y - 100);
    text->setFillColor(sf::Color::Black);
}

/**
 * Creating the start screen of the game.
 */
void AbstractGameFactory::createStartScreen() {
    //Uploading the texture of the start screen.
    auto *startScreenTexture = new sf::Texture;
    startScreenTexture->loadFromFile("C:\\Users\\Tal Mizrahi\\Desktop\\coding\\C"
                                     "\\clion\\CLionProjects\\GraphicsCPP\\resources\\homePage.png");
    textures.push_back(startScreenTexture);
    //Setting the startScreen.
    startScreen = Background(startScreenTexture, sf::Vector2f(VIEW_WIDTH, VIEW_HEIGHT),
                             sf::Vector2f(-float(VIEW_WIDTH / 2.0f), 0.0f));
}