#pragma once
#include <unordered_map>
#include <SFML/Graphics.hpp>

#include "../Enums/PieceType.h"

class UI {
public:
    UI(sf::RenderWindow& window, std::string player1Name, std::string player2Name, bool isLocalGame);
    void Draw();
    void UpdateScore(PieceType pieceType, int currentPlayer);

private:
    sf::Font Font;
    sf::RenderWindow& Window;

    sf::Text Player1Label, Player2Label, Player1ScoreLabel, Player2ScoreLabel;

    bool IsLocalGame;
    std::string Player1Name, Player2Name;

    int Player1Score = 0, Player2Score = 0;
    std::unordered_map<PieceType, int> Player1TakenPieces {};
    std::unordered_map<PieceType, int> Player2TakenPieces {};
};
