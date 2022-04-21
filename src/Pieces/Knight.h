#pragma once
#include <SFML/Graphics.hpp>

#include "Piece.h"
#include "../Enums/PieceType.h"

class Knight : public Piece {
public:
    Knight(sf::Vector2i location, sf::Texture& texture) : Piece(location, texture) {}

    std::vector<sf::Vector2i> GetPossibleMoves(
            std::vector<Piece*> const& currentPlayer,
            [[maybe_unused]] std::vector<Piece*> const& other) override
    {
        // All possible locations in clockwise order
        std::vector<sf::Vector2i> possibleMoves {
            sf::Vector2i(Location.x + 1, Location.y - 2),
            sf::Vector2i(Location.x + 2, Location.y - 1),
            sf::Vector2i(Location.x + 2, Location.y + 1),
            sf::Vector2i(Location.x + 1, Location.y + 2),
            sf::Vector2i(Location.x - 1, Location.y + 2),
            sf::Vector2i(Location.x - 2, Location.y + 1),
            sf::Vector2i(Location.x - 2, Location.y - 1),
            sf::Vector2i(Location.x - 1, Location.y - 2),
        };

        // Remove values where friendly pieces are located
        for (Piece* piece : currentPlayer) {
            auto position = std::find(possibleMoves.begin(), possibleMoves.end(), piece->GetLocation());
            if (position != possibleMoves.end()) {
                possibleMoves.erase(position);
            }
        }

        // Ensure all moves are within the boards bounds
        std::vector<sf::Vector2i> cleanedMoves;
        std::copy_if(
            possibleMoves.begin(),
            possibleMoves.end(),
            std::back_inserter(cleanedMoves),
            [](const sf::Vector2i move) { return move.x < 8 && move.y < 8 && move.x >= 0 && move.y >= 0; }
        );

        return cleanedMoves;
    }

    PieceType GetPieceType() override { return PieceType::Knight; }
};