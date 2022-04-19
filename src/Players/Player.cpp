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

int Player::FindClickedPieceIndex(sf::Vector2i mousePosition) {
    for (int i = 0; i < Pieces.size(); i++) {
        if (Pieces[i]->HasBeenClicked(mousePosition.x, mousePosition.y)) {
            return i;
        }
    }

    return -1;
}

std::vector<sf::Vector2i> Player::GetPossibleMoves(int index, std::vector<Piece*> const& otherPlayersPieces) {
    return Pieces[index]->GetPossibleMoves(Pieces, otherPlayersPieces);
}
