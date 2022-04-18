#pragma once

#include "Board.h"

class Game {
public:
    Game();

    void Start();

private:
    sf::RenderWindow Window;

    TextureManager TextureManager;
    Board Board;
};

