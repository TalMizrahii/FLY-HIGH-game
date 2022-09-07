//
// Created by Tal Mizrahi on 29/08/2022.
//

#include <iostream>
#include "Animation.h"


/**
 * A constructor for the class.
 * @param texture the texture in full witch we cut and animating.
 * @param imageCount  the amount of images in the animation.
 * @param switchTime the switch time between each frame.
 */
Animation::Animation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime) {
    // Setting the values to the members.
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = 0;

    // Calculating and setting the uvRect's size for each animation image.
    uvRect.width = texture->getSize().x / float(imageCount.x);
    uvRect.height = texture->getSize().y / float(imageCount.y);
}

/**
 * When called, updates the animation to the next frame.
 * @param row The current row of the images from the texture.
 * @param deltaTime The time between each frame to be added to the full time.
 */
void Animation::update(unsigned int row, float deltaTime, bool faceRight) {
    currentImage.y = row;    //setting the current image to the specific row.
    totalTime += deltaTime;  //adding the deltaTime to the total time.

    if (totalTime >= switchTime) {
        totalTime -= switchTime;
        currentImage.x++;

        if (currentImage.x >= imageCount.x) {
            currentImage.x = 0;
        }
    }

    // Setting the uvRect to its new coordinates.
    uvRect.top = currentImage.y * uvRect.height;

    if (faceRight) {
        uvRect.left = currentImage.x * uvRect.width;
        uvRect.width = abs(uvRect.width);

    } else {
        uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }
}

/**
 * A default destructor for the class.
 */
Animation::~Animation() = default;
