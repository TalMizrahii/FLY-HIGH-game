//
// Created by Tal Mizrahi on 29/08/2022.
//

#include "Player.h"

/**
 * A constructor for the player. Receives the texture, imageCount and switchTime for the animation member.
 * Additionally sets the speed of the player.
 * @param texture the texture of the animation.
 * @param imageCount the imageCount of the animation.
 * @param switchTime the switchTime of the animation.
 * @param speed the speed of the player.
 */
Player::Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed) :
        animation(texture, imageCount, switchTime) {
    //Setting the initiated values of the player.
    this->speed = speed;
    this->row = 0;
    faceRight = true;
    // Setting the body of the player.
    body.setSize(sf::Vector2f(144.0f, 192.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(0.0f, 450.0f);
    body.setTexture(texture);
}

/**
 * A default destructor for the player.
 */
Player::~Player() = default;

/**
 * Updating method to update the position and animation of the player.
 * @param deltaTime the relative time between the player's speed and the computer's speed.
 */
void Player::update(float deltaTime) {
    //Default movement set to zero.
    sf::Vector2f movement(0.0f, 0.0f);
    //Checking if the right keys are pressed to control the player.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        movement.x += speed * deltaTime;
    }
    //Checking if the left keys are pressed to control the player.
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        movement.x -= speed * deltaTime;
    }
    // Always Move up.
    movement.y -= speed * deltaTime;
    //Face the animation according to the pressed key.
    if (movement.x == 0.0f) {
        row = 0;
    } else {
        row = 1;
        if (movement.x > 0) {
            faceRight = false;
        } else {
            faceRight = true;
        }
    }
    // Update the position and the animation.
    animation.update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(movement);
}

/**
 * The draw method. Drawing the player on the window.
 * @param window the window that the player will be drawn on.
 */
void Player::draw(sf::RenderWindow &window) {
    window.draw(body);
}

/**
 * A getter for the player's position.
 * @return the player's position as a vector.
 */
sf::Vector2f Player::getPosition() {
    return body.getPosition();
}