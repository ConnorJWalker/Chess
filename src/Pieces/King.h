#pragma once
#include <SFML/Graphics.hpp>

#include "Piece.h"

class King : public Piece {
public:
    King(sf::Vector2i location, sf::Texture& texture) : Piece(location, texture) {}

    std::vector<sf::Vector2i> GetPossibleMoves(
            std::vector<Piece*> const& currentPlayer,
            std::vector<Piece*> const& other) override {
        return std::vector<sf::Vector2i>();
    }
};