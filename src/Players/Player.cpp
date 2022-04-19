#include <vector>
#include <utility>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "../Pieces/Piece.h"
#include "../Enums/PieceColour.h"
#include "Player.h"

Player::Player(sf::RenderWindow& window, PieceColour colour, std::vector<Piece*> pieces)
    : Window(window), Colour(colour), Pieces(std::move(pieces)) {}

Player::~Player() {
    for (Piece* piece : Pieces) {
        delete piece;
    }

    Pieces.clear();
}

void Player::Draw() {
    for (Piece* piece : Pieces) {
        piece->Draw(Window);
    }
}

void Player::HandleClickEvent(sf::Event event, std::vector<Piece*> const& otherPlayersPieces) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(Window);
    for (Piece* piece : Pieces) {
        if (piece->HasBeenClicked(mousePosition.x, mousePosition.y)) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                auto possibleMoves = piece->GetPossibleMoves(Pieces, otherPlayersPieces);
                for (auto move : possibleMoves) {
                    std::cout << "X: " << move.x << " Y: " << move.y << std::endl;
                }

                return;
            }
        }
    }
}

