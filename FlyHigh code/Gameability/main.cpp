//
// Created by Tal Mizrahi on 01/09/2022.
//

#include <SFML/Graphics.hpp>
#include "../CollisionRelated/Player.h"
#include "Game.h"

/**
 * The main method. Creates the game, initializing and running it.
 * @return hopefully zero.
 */
int main() {
    // A boolean value to know if the user want's to play another game.
    bool anotherGame = true;
    // Initiating and running the game while checking the anotherGame value.
    Game game;
    while (anotherGame) {
        game.initialize();
        anotherGame = game.run();
    }
    return 0;
}