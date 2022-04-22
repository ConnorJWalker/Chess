#include <cmath>
#include <utility>
#include <iostream>
#include <type_traits>

#include "../Enums/PieceColour.h"
#include "UI.h"

UI::UI(sf::RenderWindow& window, class TextureManager& textureManager, std::string player1Name, std::string player2Name, bool isLocalGame)
    : Window(window), TextureManager(textureManager), Player1Name(std::move(player1Name)), Player2Name(std::move(player2Name)), IsLocalGame(isLocalGame)
{
    if (!Font.loadFromFile("../assets/Raleway-Regular.ttf")) {
        std::cerr << "Could not load font file" << std::endl;
        return;
    }

    Player1Label.setFont(Font);
    Player1Label.setString(Player1Name);
    Player1Label.setCharacterSize(24);
    Player1Label.setPosition(sf::Vector2f(820.f, 730.f));

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
    Window.draw(Player1Label);
    Window.draw(Player2Label);

    // Render taken pieces under users names
    float size = 30.f;
    std::vector<std::unordered_map<PieceType, int>> takenPieces{ Player1TakenPieces, Player2TakenPieces };
    for (int i = 0; i < takenPieces.size(); i++) {
        float counter = 0.f;
        sf::Vector2f startLocation(820.f, i == 0 ? 770.f : 30.f);
        PieceColour colour = i == 0 ? PieceColour::Black : PieceColour::White;

        for (const auto& piece : takenPieces[i]) {
            sf::Texture& texture = TextureManager.GetTexture(piece.first, colour);
            for (int j = 0; j < piece.second; j++) {
                sf::RectangleShape rect(sf::Vector2f(size, size));
                rect.setTexture(&texture);
                rect.setPosition(sf::Vector2f(startLocation.x + size * counter, startLocation.y));
                Window.draw(rect);

                counter++;
            }
        }
    }
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
