#pragma once
#include <SFML/Graphics.hpp>

#include "Piece.h"
#include "../Helpers/PossibleLocationHelper.h"

class Bishop : public Piece {
public:
    Bishop(sf::Vector2i location, sf::Texture& texture) : Piece(location, texture) {}

    std::vector<sf::Vector2i> GetPossibleMoves(
            std::vector<Piece*> const& currentPlayer,
            std::vector<Piece*> const& other) override
    {
        return plh::GetPossibleMovesDiagonal(currentPlayer, other, Location);
    }
};