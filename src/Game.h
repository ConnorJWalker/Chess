#pragma once

#include "UI/UI.h"
#include "Board.h"
#include "Players/Player.h"
#include "Enums/GameMode.h"

class Game {
public:
    Game(GameMode gameMode, std::string player1Name, std::string player2Name);

    void Start();

private:
    sf::RenderWindow Window;

    TextureManager TextureManager;
    Board Board;
    Player Players[2];

    UI UI;

    int SelectedPieceIndex = -1;

    void Draw();
    void HandleEvents();
    void HandleClickEvent(sf::Event event);
};

