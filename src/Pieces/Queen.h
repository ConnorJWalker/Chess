#pragma once
#include <SFML/Graphics.hpp>

#include "Piece.h"
#include "../Helpers/PossibleLocationHelper.h"

class Queen : public Piece {
public:
    Queen(sf::Vector2i location, sf::Texture& texture) : Piece(location, texture) {}

    std::vector<sf::Vector2i> GetPossibleMoves(
            std::vector<Piece*> const& currentPlayer,
            std::vector<Piece*> const& other) override {
        std::vector<sf::Vector2i> possibleMoves;

        auto straight = plh::GetPossibleMovesStraight(currentPlayer, other, Location);
        auto diagonal = plh::GetPossibleMovesDiagonal(currentPlayer, other, Location);

        possibleMoves.insert(possibleMoves.end(), straight.begin(), straight.end());
        possibleMoves.insert(possibleMoves.end(), diagonal.begin(), diagonal.end());

        return possibleMoves;
    }
};