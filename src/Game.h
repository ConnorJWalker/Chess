#pragma once

#include "Board.h"
#include "Players/Player.h"

class Game {
public:
    Game();

    void Start();

private:
    sf::RenderWindow Window;

    TextureManager TextureManager;
    Board Board;
    Player Players[2];

    void Draw();
};

