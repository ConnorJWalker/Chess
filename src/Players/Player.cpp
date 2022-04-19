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

