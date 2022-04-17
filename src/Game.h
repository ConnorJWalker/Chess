#pragma once

#include "Board.h"

class Game {
public:
    Game();
    ~Game();

    void Start();

private:
    sf::RenderWindow* Window = nullptr;
    Board Board;
};

