//
// Created by Tal Mizrahi on 29/08/2022.
//

#ifndef GRAPHICSCPP_PLAYER_H
#define GRAPHICSCPP_PLAYER_H

#include <SFML/Graphics.hpp>
#include "../SpriteRelated/Animation.h"
#include "Collider.h"
#include "../SpriteRelated/AbstractSprites.h"
#include "AbstractCollidable.h"

/**
 * The player class. Contain all methods related to the player including the draw and update.
 */
class Player : public AbstractSprites, public AbstractCollidable {
public:
    Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed);

    ~Player() override;

    void update(float deltaTime);

    sf::Vector2f getPosition();

    void draw(sf::RenderWindow &window) override;

    Collider getCollider() override { return Collider(body); }

    sf::RectangleShape getBody() override { return body; }

private:
    sf::RectangleShape body; // The body of the player.
    Animation animation;     // The animation of the player (to make it move).
    unsigned int row;        // The row of the animation from the texture (left/right/up).
    float speed;             // The speed of the player.
    bool faceRight;          // A boolean value to check if the player face to the right or to the left.
};


#endif //GRAPHICSCPP_PLAYER_H
