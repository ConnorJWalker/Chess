#include <cmath>
#include <utility>
#include <iostream>
#include <type_traits>

#include "UI.h"

UI::UI(sf::RenderWindow& window, std::string player1Name, std::string player2Name, bool isLocalGame)
    : Window(window), Player1Name(std::move(player1Name)), Player2Name(std::move(player2Name)), IsLocalGame(isLocalGame)
{
    if (!Font.loadFromFile("../assets/Raleway-Regular.ttf")) {
        std::cerr << "Could not load font file" << std::endl;
        return;
    }

    Player1Label.setFont(Font);
    Player1Label.setString(Player1Name);
    Player1Label.setCharacterSize(24);
    Player1Label.setPosition(sf::Vector2f(820.f, 770.f));

    Player2Label.setFont(Font);
    Player2Label.setString(Player2Name);
    Player2Label.setCharacterSize(24);
    Player2Label.setPosition(sf::Vector2f(820.f, 0.f));

    Player2Label.setFont(Font);
    Player2Label.setString(Player2Name);
    Player2Label.setCharacterSize(24);
    Player2Label.setPosition(sf::Vector2f(820.f, 0.f));
}

void UI::Draw() {
    std::cout << "Player 1 Score: " << Player1Score << std::endl;
    std::cout << "Player 2 Score: " << Player2Score << std::endl;

    Window.draw(Player1Label);
    Window.draw(Player2Label);
}

void UI::UpdateScore(PieceType pieceType, int currentPlayer) {
    auto takenPieces = currentPlayer == 0 ? &Player1TakenPieces : &Player2TakenPieces;
    auto playerScore = currentPlayer == 0 ? &Player1Score : &Player2Score;
    // Absolute value needed or taking knights will decrement the score
    (*playerScore) += std::abs(std::underlying_type<PieceType>::type(pieceType));

    if (takenPieces->contains(pieceType)){
        takenPieces->at(pieceType)++;
        return;
    }

    takenPieces->insert(std::make_pair(pieceType, 1));
}
