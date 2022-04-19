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

    int SelectedPieceIndex = -1;

    void Draw();
    void HandleEvents();
    void HandleClickEvent(sf::Event event);

    int CurrentPlayer = 0;
};

