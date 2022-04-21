#pragma once
#include <SFML/Graphics.hpp>

#include "Piece.h"
#include "../Enums/PieceType.h"
#include "../Helpers/PossibleLocationHelper.h"

class Castle : public Piece {
public:
    Castle(sf::Vector2i location, sf::Texture& texture) : Piece(location, texture) {}

    std::vector<sf::Vector2i> GetPossibleMoves(
            std::vector<Piece*> const& currentPlayer,
            std::vector<Piece*> const& other) override
    {
        return plh::GetPossibleMovesStraight(currentPlayer, other, Location);
    }

    PieceType GetPieceType() override { return PieceType::Castle; };
};
