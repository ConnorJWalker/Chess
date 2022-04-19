#pragma once
#include <SFML/Graphics.hpp>

#include "Piece.h"

class Castle : public Piece {
public:
    Castle(sf::Vector2i location, sf::Texture& texture) : Piece(location, texture) {}

    std::vector<sf::Vector2i> GetPossibleMoves() override {
        return std::vector<sf::Vector2i>();
    }
};