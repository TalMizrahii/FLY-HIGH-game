//
// Created by Tal Mizrahi on 29/08/2022.
//
#ifndef GRAPHICSCPP_ANIMATION_H
#define GRAPHICSCPP_ANIMATION_H

#include <SFML/Graphics.hpp>

/**
 * The header of the class who creates an animation and moving it using the update method.
 */
class Animation {
public:
    Animation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime);

    ~Animation();

    void update(unsigned int row, float deltaTime, bool faceRight);

public:
    sf::IntRect uvRect;

private:
    sf::Vector2u imageCount;   // how many images are in the texture.
    sf::Vector2u currentImage; // the axes of the current image.
    float totalTime;          //the total time of the animation.
    float switchTime;         //how long the frame is shown on the screen.

};


#endif //GRAPHICSCPP_ANIMATION_H
