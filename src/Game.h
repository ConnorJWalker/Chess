#pragma once

#include "Board.h"

class Game {
public:
    Game();

    void Start();

private:
    sf::RenderWindow Window;
    Board Board;
};

