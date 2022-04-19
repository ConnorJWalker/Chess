#include <vector>
#include <utility>
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

void Player::HandleClickEvent(sf::Event event) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(Window);
    for (Piece* piece : Pieces) {
        if (piece->HasBeenClicked(mousePosition.x, mousePosition.y)) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                piece->HandleClickEvent();
                return;
            }
        }
    }
}

